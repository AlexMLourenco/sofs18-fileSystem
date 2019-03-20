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

        void soFreeDataBlock(uint32_t bn)

        {

            soProbe(442, "%s(%u)\n", __FUNCTION__, bn);

            /* change the following line by your code */

           // bin::soFreeDataBlock(bn);

            

            SOSuperBlock *spb = soSBGetPointer();

            if(bn <0 || bn >= spb->dz_total){

                throw SOException(EINVAL,__FUNCTION__);

            }

            //check if cache is full

            if(spb->bicache.idx == INODE_REFERENCE_CACHE_SIZE){     

                sofs18::soDepleteBICache(); //deplete if full

            }

            

            spb->bicache.ref[spb->bicache.idx] = bn;

            spb->bicache.idx++;

            spb->ifree++;

        }

    };

};


