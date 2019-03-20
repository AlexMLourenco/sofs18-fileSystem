/*
 *  \author Artur Pereira - 2016-2018
 */

#include "bin_syscalls.h"
#include "core.h"

namespace sofs18
{
    int soMknod(const char *path, mode_t mode)
    {
        if (soBinSelected(101))
            return bin::soMknod(path, mode);
        else
            /* replace bin:: with work:: if you implement this syscall */
            return bin::soMknod(path, mode);
    }

};

