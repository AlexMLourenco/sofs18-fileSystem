#include "dal.h"
#include "bin_dal.h"

#include <inttypes.h>

namespace sofs18
{

    uint32_t * soFILTOpenBlock(uint32_t bn)
    {
        return bin::soFILTOpenBlock(bn);
    }

    /* ***************************************** */

    void soFILTSaveBlock()
    {
        bin::soFILTSaveBlock();
    }

    /* ***************************************** */

    void soFILTCloseBlock()
    {
        bin::soFILTCloseBlock();
    }

    /* ***************************************** */
};

