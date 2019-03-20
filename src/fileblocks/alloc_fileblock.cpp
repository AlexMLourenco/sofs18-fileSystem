#include "fileblocks.h"
#include "bin_fileblocks.h"
#include "work_fileblocks.h"

#include "core.h"

#include <errno.h>

#include <iostream>

namespace sofs18
{

    uint32_t soAllocFileBlock(int ih, uint32_t fbn)
    {
        if (soBinSelected(302))
            return bin::soAllocFileBlock(ih, fbn);
        else
            return work::soAllocFileBlock(ih, fbn);
    }

};

