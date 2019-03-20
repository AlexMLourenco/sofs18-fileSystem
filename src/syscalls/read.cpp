/*
 *  \author Artur Pereira - 2016-2018
 */

#include "bin_syscalls.h"
#include "core.h"

namespace sofs18
{
    int soRead(const char *path, void *buf, uint32_t count, int32_t pos)
    {
        if (soBinSelected(108))
            return bin::soRead(path, buf, count, pos);
        else
            /* replace bin:: with work:: if you implement this syscall */
            return bin::soRead(path, buf, count, pos);
    }

};

