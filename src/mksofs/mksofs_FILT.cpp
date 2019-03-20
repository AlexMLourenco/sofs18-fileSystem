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
    uint32_t fillInFreeInodeListTable(uint32_t first_block, uint32_t itotal)
    {
        if (soBinSelected(603))
            return bin::fillInFreeInodeListTable(first_block, itotal);
        else
            return work::fillInFreeInodeListTable(first_block, itotal);
    }

};

