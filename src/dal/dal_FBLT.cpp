#include "dal.h"
#include "bin_dal.h"

#include <inttypes.h>

namespace sofs18
{
    /* ***************************************** */

    uint32_t * soFBLTOpenBlock(uint32_t bn)
    {
        return bin::soFBLTOpenBlock(bn);
    }

    /* ***************************************** */

    void soFBLTSaveBlock()
    {
        bin::soFBLTSaveBlock();
    }

    /* ***************************************** */

    void soFBLTCloseBlock()
    {
        bin::soFBLTCloseBlock();
    }

    /* ***************************************** */
};

