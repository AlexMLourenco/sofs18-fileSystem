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
    void resetBlocks(uint32_t first_block, uint32_t cnt)
    {
        if (soBinSelected(607))
            bin::resetBlocks(first_block, cnt);
        else
            work::resetBlocks(first_block, cnt);
    }

};

