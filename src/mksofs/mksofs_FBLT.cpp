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
    uint32_t fillInFreeBlockListTable(uint32_t first_block, uint32_t btotal, uint32_t rdsize)
    {
        if (soBinSelected(605))
            return bin::fillInFreeBlockListTable(first_block, btotal, rdsize);
        else
            return work::fillInFreeBlockListTable(first_block, btotal, rdsize);
    }

};

