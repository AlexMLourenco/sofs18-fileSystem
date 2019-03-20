/*
 *  \author Artur Pereira - 2016-2018
 */

#include "bin_syscalls.h"
#include "core.h"

namespace sofs18
{

    int soUnlink(const char *path)
    {
        if (soBinSelected(105))
            return bin::soUnlink(path);
        else
            /* replace bin:: with work:: if you implement this syscall */
            return bin::soUnlink(path);
    }

};

