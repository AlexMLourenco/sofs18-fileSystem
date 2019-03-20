/*
 *  \author Artur Pereira - 2016-2018
 */

#include "bin_syscalls.h"
#include "core.h"

namespace sofs18
{

    int soLink(const char *path, const char *newPath)
    {
        if (soBinSelected(104))
            return bin::soLink(path, newPath);
        else
            /* replace bin:: with work:: if you implement this syscall */
            return bin::soLink(path, newPath);
    }

};

