#include "fileblocks.h"
#include "bin_fileblocks.h"
#include "work_fileblocks.h"

#include "core.h"

#include <errno.h>

namespace sofs18
{

    uint32_t soGetFileBlock(int ih, uint32_t fbn)
    {
        if (soBinSelected(301))
            return bin::soGetFileBlock(ih, fbn);
        else
            return work::soGetFileBlock(ih, fbn);
    }

};

