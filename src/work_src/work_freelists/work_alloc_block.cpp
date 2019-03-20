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

        uint32_t soAllocDataBlock()

        {

            soProbe(441, "%s()\n", __FUNCTION__);

            SOSuperBlock *sp;

                    sp = soSBGetPointer();

                    if(sp->dz_free == 0) throw SOException( ENOSPC, __FUNCTION__);        

                    if(sp->bicache.ref[sp->bicache.idx] == NullReference) 

                            soReplenishBRCache();        // Is this right?

                    sp->bicache.ref[sp->bicache.idx] = NullReference;

                    if(++sp->bicache.idx == BLOCK_REFERENCE_CACHE_SIZE-1)

                            sp->bicache.idx = 0;

                    sp->dz_free--;

                    return sp->dz_total - sp->dz_free;

        }

    };

};

