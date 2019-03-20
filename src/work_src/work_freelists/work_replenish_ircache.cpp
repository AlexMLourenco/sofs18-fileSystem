/*
 *  \author António Rui Borges - 2012-2015
 *  \authur Artur Pereira - 2016-2018
 */

#include "work_freelists.h"

#include <string.h>
#include <errno.h>
#include <iostream>

#include "core.h"
#include "dal.h"
#include "freelists.h"
#include "bin_freelists.h"

namespace sofs18
{
    namespace work
    {

        using namespace std;

        void soReplenishIRCache(void)
        {
            soProbe(403, "%s()\n", __FUNCTION__);

            /* change the following line by your code */
            //bin::soReplenishIRCache();


            SOSuperBlock * sup = soSBGetPointer();
            SOInodeReferenceCache* ircache = &(sup->ircache);
            SOInodeReferenceCache* iicache = &(sup->ircache);



            if(ircache->idx != INODE_REFERENCE_CACHE_SIZE  ){
                   return;
            }


            //copiar da  insertion cache para retrivel no caso de filt vazia
            if(sup->filt_tail == sup->filt_head)
            {

                memcpy(&ircache->ref[INODE_REFERENCE_CACHE_SIZE - iicache->idx],&iicache->ref[0],iicache->idx*sizeof(uint32_t));
                memset(iicache->ref,NullReference,iicache->idx*sizeof(uint32_t));
                iicache->idx = 0;
                ircache->idx=INODE_REFERENCE_CACHE_SIZE - sup ->iicache.idx;
                soSBSave();
                return;
            }

           
            uint32_t pos = (sup->filt_head % ReferencesPerBlock);
            uint32_t *sup_filt = soFILTOpenBlock(sup->filt_head/ReferencesPerBlock);

            uint32_t n = ReferencesPerBlock - pos;
            n= n <=INODE_REFERENCE_CACHE_SIZE ?n : INODE_REFERENCE_CACHE_SIZE;  //verifica primeiro  n <= cs sendo n rrpb - j

            //verificar se filt esta vazia se sim por head e tail a pontar para 0
            memcpy(&ircache->ref[INODE_REFERENCE_CACHE_SIZE-n], sup_filt+(pos*sizeof(uint32_t)),n*(sizeof(uint32_t)));
            ircache->idx-=n;
            sup->filt_head= ((pos+n)%ReferencesPerBlock);
            soFILTSaveBlock();
            soFILTCloseBlock();
            soSBSave();

            





        }

    };

};

