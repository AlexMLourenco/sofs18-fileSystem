/*
 *  \authur Artur Pereira - 2009-2018
 */

#include "freelists.h"
#include "bin_freelists.h"
#include "work_freelists.h"

#include "core.h"

namespace sofs18
{

    void soFreeDataBlock(uint32_t bn)
    {
        if (soBinSelected(442))
            bin::soFreeDataBlock(bn);
        else
            work::soFreeDataBlock(bn);
    }

};

