/*
 *  \authur Artur Pereira - 2009-2018
 */

#include "mksofs.h"
#include "bin_mksofs.h"
#include "work_mksofs.h"

#include "core.h"

#include <inttypes.h>

namespace sofs18
{

    /* see mksofs.h for a description */
    void fillInSuperBlock(const char *name, uint32_t ntotal, uint32_t itotal, uint32_t rdsize)
    {
        if (soBinSelected(602))
            bin::fillInSuperBlock(name, ntotal, itotal, rdsize);
        else
            work::fillInSuperBlock(name, ntotal, itotal, rdsize);
    }

};

