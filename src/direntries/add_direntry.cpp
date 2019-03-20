#include "direntries.h"
#include "bin_direntries.h"
#include "work_direntries.h"

#include "core.h"

#include <errno.h>
#include <string.h>
#include <sys/stat.h>

namespace sofs18
{

    void soAddDirEntry(int pih, const char *name, uint32_t cin)
    {
        if (soBinSelected(202))
            return bin::soAddDirEntry(pih, name, cin);
        else
            return work::soAddDirEntry(pih, name, cin);
    }

};

