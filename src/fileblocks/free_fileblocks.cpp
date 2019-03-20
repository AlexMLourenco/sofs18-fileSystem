#include "fileblocks.h"
#include "bin_fileblocks.h"
#include "work_fileblocks.h"

#include "core.h"

#include <inttypes.h>
#include <errno.h>
#include <assert.h>

namespace sofs18
{

    void soFreeFileBlocks(int ih, uint32_t ffbn)
    {
        if (soBinSelected(303))
            bin::soFreeFileBlocks(ih, ffbn);
        else
            work::soFreeFileBlocks(ih, ffbn);
    }

};

