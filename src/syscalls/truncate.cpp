/*
 *  \author Artur Pereira - 2016-2018
 */

#include "bin_syscalls.h"
#include "core.h"

namespace sofs18
{

    int soTruncate(const char *path, off_t length)
    {
        if (soBinSelected(110))
            return bin::soTruncate(path, length);
        else
            /* replace bin:: with work:: if you implement this syscall */
            return bin::soTruncate(path, length);
    }

};

