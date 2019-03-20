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

        void soReplenishBRCache(void)
        {
            soProbe(443, "%s()\n", __FUNCTION__);

            /* change the following line by your code */
            //bin::soReplenishBRCache();
            SOSuperBlock * sup = soSBGetPointer();
            SOBlockReferenceCache* brcache = &(sup->brcache);
            SOBlockReferenceCache* bicache = &(sup->bicache);
           
          
            if(brcache->idx != BLOCK_REFERENCE_CACHE_SIZE  ){
                   return;
            }


            //copiar da  insertion cache para retrivel no caso de filt vazia
            if(sup->fblt_tail == sup->fblt_head)
            {

                memcpy(&brcache->ref[BLOCK_REFERENCE_CACHE_SIZE - bicache->idx],&bicache->ref[0],bicache->idx*sizeof(uint32_t));
                memset(bicache->ref,NullReference,bicache->idx*sizeof(uint32_t));
                bicache->idx = 0;
                brcache->idx=BLOCK_REFERENCE_CACHE_SIZE - bicache->idx;
                soSBSave();
                return;
            }
           
    
           
            uint32_t pos = (sup->fblt_head % ReferencesPerBlock);
            uint32_t *sup_fblt = soFILTOpenBlock(sup->fblt_head/ReferencesPerBlock);
            
            uint32_t n = ReferencesPerBlock - pos;
            n= n <=BLOCK_REFERENCE_CACHE_SIZE ?n : BLOCK_REFERENCE_CACHE_SIZE;  //verifica primeiro  n <= cs sendo n rrpb - j 
            
            //verificar se filt esta vazia se sim por head e tail a pontar para 0
            memcpy(&brcache->ref[BLOCK_REFERENCE_CACHE_SIZE-n], sup_fblt+(pos*sizeof(uint32_t)),n*(sizeof(uint32_t)));
            brcache->idx-=n;
            sup->fblt_head= ((pos+n)%ReferencesPerBlock);
            soFILTSaveBlock();
            soFILTCloseBlock();
            soSBSave();

        }

    };

};

