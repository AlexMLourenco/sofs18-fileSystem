/*
 *  \author Artur Pereira - 2016-2018
 */

#include "bin_syscalls.h"
#include "core.h"

namespace sofs18
{

    int soReaddir(const char *path, void *buf, int32_t pos)
    {
        if (soBinSelected(111))
            return bin::soReaddir(path, buf, pos);
        else
            /* replace bin:: with work:: if you implement this syscall */
            return bin::soReaddir(path, buf, pos);
    }

};

