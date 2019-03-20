#include "fileblocks.h"
#include "bin_fileblocks.h"
#include "work_fileblocks.h"

#include "core.h"

#include <string.h>
#include <inttypes.h>

namespace sofs18
{

    void soReadFileBlock(int ih, uint32_t fbn, void *buf)
    {
        if (soBinSelected(331))
            bin::soReadFileBlock(ih, fbn, buf);
        else
            work::soReadFileBlock(ih, fbn, buf);
    }

};

