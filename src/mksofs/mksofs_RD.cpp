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
    uint32_t fillInRootDir(uint32_t first_block, uint32_t rdsize)
    {
        if (soBinSelected(606))
            return bin::fillInRootDir(first_block, rdsize);
        else
            return work::fillInRootDir(first_block, rdsize);
    }

};

