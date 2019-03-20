/*
 *  \authur Artur Pereira - 2009-2018
 */

#include "freelists.h"
#include "bin_freelists.h"
#include "work_freelists.h"

#include "core.h"

namespace sofs18
{

    uint32_t soAllocInode(uint32_t type)
    {
        if (soBinSelected(401))
            return bin::soAllocInode(type);
        else
            return work::soAllocInode(type);
    }

};

