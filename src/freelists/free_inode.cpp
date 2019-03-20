/*
 *  \authur Artur Pereira - 2009-2018
 */

#include "freelists.h"
#include "bin_freelists.h"
#include "work_freelists.h"

#include "core.h"

namespace sofs18
{

    void soFreeInode(uint32_t in)
    {
        if (soBinSelected(402))
            bin::soFreeInode(in);
        else
            work::soFreeInode(in);
    }

};

