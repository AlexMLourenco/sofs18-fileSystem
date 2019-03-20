/*
 *  \author Artur Pereira - 2016-2018
 */

#include "bin_syscalls.h"
#include "core.h"

namespace sofs18
{

    int soWrite(const char *path, void *buf, uint32_t count, int32_t pos)
    {
        if (soBinSelected(109))
            return bin::soWrite(path, buf, count, pos);
        else
            /* replace bin:: with work:: if you implement this syscall */
            return bin::soWrite(path, buf, count, pos);
    }

};

