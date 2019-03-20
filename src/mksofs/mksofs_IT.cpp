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
    uint32_t fillInInodeTable(uint32_t first_block, uint32_t itotal, uint32_t rdsize)
    {
        if (soBinSelected(604))
            return bin::fillInInodeTable(first_block, itotal, rdsize);
        else
            return work::fillInInodeTable(first_block, itotal, rdsize);
    }

};

