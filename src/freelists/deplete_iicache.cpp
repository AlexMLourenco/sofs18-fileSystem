/*
 *  \authur Artur Pereira - 2009-2018
 */

#include "freelists.h"
#include "bin_freelists.h"
#include "work_freelists.h"

#include "core.h"

namespace sofs18
{

    void soDepleteIICache(void)
    {
        if (soBinSelected(404))
            bin::soDepleteIICache();
        else
            work::soDepleteIICache();
    }

};

