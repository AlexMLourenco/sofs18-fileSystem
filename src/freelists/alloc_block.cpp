/*
 *  \authur Artur Pereira - 2009-2018
 */

#include "freelists.h"
#include "bin_freelists.h"
#include "work_freelists.h"

#include "core.h"

namespace sofs18
{

    uint32_t soAllocDataBlock()
    {
        if (soBinSelected(441))
            return bin::soAllocDataBlock();
        else
            return work::soAllocDataBlock();
    }

};

