/*
 *  \author António Rui Borges - 2012-2015
 *  \authur Artur Pereira - 2016-2018
 */

#include "work_freelists.h"

#include <stdio.h>
#include <errno.h>
#include <inttypes.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#include <iostream>

#include "core.h"
#include "dal.h"
#include "freelists.h"
#include "bin_freelists.h"

namespace sofs18
{
    namespace work
    {

        uint32_t soAllocInode(uint32_t type)
        {
            soProbe(401, "%s(%x)\n", __FUNCTION__, type);

            /* change the following line by your code */
            
            //verificar se a cache está vazia
            SOSuperBlock *spb = soSBGetPointer();
            if(spb->ifree == 0){
                throw SOException(ENOSPC,__FUNCTION__);
            }
            if(spb->ircache.idx == INODE_REFERENCE_CACHE_SIZE){
                sofs18::soReplenishIRCache(); //replenish if empty
            }
            //libertar o espaço em memoria
            spb->ifree--;
            //remover item da cache
            uint32_t inode_val =spb->ircache.ref[spb->ircache.idx];
            uint32_t inode_handler = soITOpenInode(spb->ircache.ref[spb->ircache.idx]);
            spb->ircache.ref[spb->ircache.idx] = NullReference;
            //inicializar o inode
            SOInode* inode = soITGetInodePointer(inode_handler);
            
            //set up inode
            inode->mode = type;
            inode->lnkcnt = 0;
            inode->owner = getuid(); 
            inode->group = getgid();
            inode->size = 0;
            inode->blkcnt = 0;
            inode->ctime = time(NULL);
            inode->mtime = time(NULL);
            inode->atime = time(NULL);
            int i;
            for(i = 0; i < N_DIRECT; i++){
                inode->d[i] = NullReference; /*put all direct references to the data array pointing null*/
            }
            for(i = 0; i < N_INDIRECT; i++){
                inode->i1[i] = NullReference; /*put all indirect references to the data array pointing null*/
            }
            for(i = 0;i < N_DOUBLE_INDIRECT;i++){
                inode->i2[i] = NullReference;  /*put double-indirect references to the data array pointing null*/
            }
            //increase cache idx
            spb->ircache.idx++;
            //save all changes
            soITSaveInode(inode_handler);
            soSBSave();
            
            //return da referencia do inode alocado
            return inode_val;
             
        }

    };

};

