#include "direntries.h"
#include "bin_direntries.h"
#include "work_direntries.h"

#include "core.h"

#include <errno.h>
#include <string.h>
#include <libgen.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

namespace sofs18
{

    uint32_t soTraversePath(char *path)
    {
        if (soBinSelected(221))
            return bin::soTraversePath(path);
        else
            return work::soTraversePath(path);
    }

};

