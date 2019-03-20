#include "fileblocks.h"
#include "bin_fileblocks.h"
#include "work_fileblocks.h"

#include "core.h"

#include <string.h>
#include <inttypes.h>

namespace sofs18
{

    void soWriteFileBlock(int ih, uint32_t fbn, void *buf)
    {
        if (soBinSelected(332))
            bin::soWriteFileBlock(ih, fbn, buf);
        else
            work::soWriteFileBlock(ih, fbn, buf);
    }

};

