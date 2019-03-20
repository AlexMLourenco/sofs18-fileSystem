/*
 *  \author Artur Pereira - 2016-2018
 */

#include "bin_syscalls.h"
#include "core.h"

namespace sofs18
{

    int soSymlink(const char *effPath, const char *path)
    {
        if (soBinSelected(103))
            return bin::soSymlink(effPath, path);
        else
            /* replace bin:: with work:: if you implement this syscall */
            return bin::soSymlink(effPath, path);
    }

};

