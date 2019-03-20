/*
 *  \author Artur Pereira - 2016-2018
 */

#include "bin_syscalls.h"
#include "core.h"

namespace sofs18
{
    int soMkdir(const char *path, mode_t mode)
    {
        if (soBinSelected(102))
            return bin::soMkdir(path, mode);
        else
            /* replace bin:: with work:: if you implement this syscall */
            return bin::soMkdir(path, mode);
    }

};

