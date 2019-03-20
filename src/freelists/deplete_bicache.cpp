/*
 *  \authur Artur Pereira - 2009-2018
 */

#include "freelists.h"
#include "bin_freelists.h"
#include "work_freelists.h"

#include "core.h"

namespace sofs18
{

    void soDepleteBICache(void)
    {
        if (soBinSelected(444))
            bin::soDepleteBICache();
        else
            work::soDepleteBICache();
    }

};

