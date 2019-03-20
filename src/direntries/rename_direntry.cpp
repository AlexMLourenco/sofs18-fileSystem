#include "direntries.h"
#include "bin_direntries.h"
#include "work_direntries.h"

#include "core.h"

#include <string.h>
#include <errno.h>
#include <sys/stat.h>

namespace sofs18
{

    void soRenameDirEntry(int pih, const char *name, const char *newName)
    {
        if (soBinSelected(204))
            return bin::soRenameDirEntry(pih, name, newName);
        else
            return work::soRenameDirEntry(pih, name, newName);
    }

};

