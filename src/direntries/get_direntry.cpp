#include "direntries.h"
#include "bin_direntries.h"
#include "work_direntries.h"

#include "core.h"

#include <errno.h>
#include <string.h>
#include <sys/stat.h>

namespace sofs18
{

    uint32_t soGetDirEntry(int pih, const char *name)
    {
        if (soBinSelected(201))
            return bin::soGetDirEntry(pih, name);
        else
            return work::soGetDirEntry(pih, name);
    }

};

