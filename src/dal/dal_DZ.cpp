#include "dal.h"
#include "bin_dal.h"

#include "rawdisk.h"
#include "core.h"

#include <inttypes.h>

namespace sofs18
{

    void soReadDataBlock(uint32_t bn, void *buf)
    {
        bin::soReadDataBlock(bn, buf);
    }

    /* ***************************************** */

    void soWriteDataBlock(uint32_t bn, void *buf)
    {
        bin::soWriteDataBlock(bn, buf);
    }

    /* ***************************************** */
};

