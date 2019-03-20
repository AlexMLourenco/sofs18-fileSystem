/*
 *  \author Artur Pereira - 2016-2018
 */

#include "bin_syscalls.h"
#include "core.h"

namespace sofs18
{
    int soRename(const char *path, const char *newPath)
    {
        if (soBinSelected(107))
            return bin::soRename(path, newPath);
        else
            /* replace bin:: with work:: if you implement this syscall */
            return bin::soRename(path, newPath);
    }

};

