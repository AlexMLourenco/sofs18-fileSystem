/*
 *  \author Artur Pereira - 2016-2018
 */

#include "bin_syscalls.h"
#include "core.h"

namespace sofs18
{
    int soRmdir(const char *path)
    {
        if (soBinSelected(106))
            return bin::soRmdir(path);
        else
            /* replace bin:: with work:: if you implement this syscall */
            return bin::soRmdir(path);
    }

};

