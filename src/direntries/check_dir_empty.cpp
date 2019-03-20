#include "direntries.h"
#include "bin_direntries.h"
#include "work_direntries.h"

#include "core.h"

#include <errno.h>
#include <string.h>
#include <sys/stat.h>

namespace sofs18
{

    bool soCheckDirEmpty(int ih)
    {
        if (soBinSelected(205))
            return bin::soCheckDirEmpty(ih);
        else
            return work::soCheckDirEmpty(ih);
    }

};

