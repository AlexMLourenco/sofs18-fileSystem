/*
 *  \author Artur Pereira - 2016-2018
 */

#include "bin_syscalls.h"
#include "core.h"

namespace sofs18
{
    int soReadlink(const char *path, char *buf, size_t bufsz)
    {
        if (soBinSelected(112))
            return bin::soReadlink(path, buf, bufsz);
        else
            /* replace bin:: with work:: if you implement this syscall */
            return bin::soReadlink(path, buf, bufsz);
    }

};

