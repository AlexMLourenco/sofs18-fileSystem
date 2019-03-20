#include "direntries.h"
#include "bin_direntries.h"
#include "work_direntries.h"

#include "core.h"

#include <errno.h>
#include <string.h>
#include <sys/stat.h>

namespace sofs18
{

    uint32_t soDeleteDirEntry(int pih, const char *name)
    {
        if (soBinSelected(203))
            return bin::soDeleteDirEntry(pih, name);
        else
            return work::soDeleteDirEntry(pih, name);
    }

};

