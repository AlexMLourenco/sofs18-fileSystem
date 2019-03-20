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

#include "core.h"
#include "dal.h"
#include "freelists.h"
#include "bin_freelists.h"

namespace sofs18
{
    namespace work
    {

        void soFreeInode(uint32_t in)
        {
            soProbe(402, "%s(%u)\n", __FUNCTION__, in);

            /* change the following line by your code */

            uint32_t i, handler_inode;
            SOSuperBlock *spb = soSBGetPointer();
            //check if cache is full
            if(spb->iicache.idx == INODE_REFERENCE_CACHE_SIZE){     
                sofs18::soDepleteIICache(); //deplete if full
            }

            handler_inode = soITOpenInode(in);
            SOInode *inode = soITGetInodePointer(handler_inode);
            
            //check if inode is already free
            if(inode->mode==INODE_FREE)
                return;
            
            //increment number of free inodes
            spb->ifree++;
            //change inode status
            inode->mode = INODE_FREE; //put the flag signaling the inode in is free
            inode->lnkcnt = 0;
            inode->owner = getuid();
            inode->group = getuid();
            inode->size = 0;
            inode->blkcnt = 0;            
            inode->ctime = time(NULL);
            inode->mtime = time(NULL);
            for(i = 0; i < N_DIRECT; i++){
                inode->d[i] = NullReference; /*put all direct references to the data array pointing null*/
            }
            for(i = 0; i < N_INDIRECT; i++){
                inode->i1[i] = NullReference; /*put all indirect references to the data array pointing null*/
            }
            for(i = 0;i < N_DOUBLE_INDIRECT;i++){
                inode->i2[i] = NullReference;  /*put double-indirect references to the data array pointing null*/
            }
            //reference stored in cache
            spb->iicache.ref[spb->iicache.idx]=in;
            //increment cache idx
            spb->iicache.idx++;
            //save
            soITSaveInode(handler_inode);
            soSBSave();
        }

    };

};

