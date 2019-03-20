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
    void computeStructure(uint32_t ntotal, uint32_t & itotal, uint32_t & btotal, uint32_t & rdsize)
    {
        if (soBinSelected(601))
            bin::computeStructure(ntotal, itotal, btotal, rdsize);
        else
            work::computeStructure(ntotal, itotal, btotal, rdsize);
    }

};

