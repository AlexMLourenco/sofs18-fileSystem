/*
 *  \author Artur Pereira - 2016-2018
 */

#include "bin_syscalls.h"

namespace sofs18
{
    int soOpenFileSystem(const char *devname)
    {
        return bin::soOpenFileSystem(devname);
    }

    /* ********************************************************* */

    int soCloseFileSystem(void)
    {
        return bin::soCloseFileSystem();
    }

    /* ********************************************************* */

    int soStatFS(const char *path, struct statvfs *st)
    {
        return bin::soStatFS(path, st);
    }

    /* ********************************************************* */

    int soStat(const char *path, struct stat *st)
    {
        return bin::soStat(path, st);
    }

    /* ********************************************************* */

    int soAccess(const char *path, int opRequested)
    {
        return bin::soAccess(path, opRequested);
    }

    /* ********************************************************* */

    int soChmod(const char *path, mode_t mode)
    {
        return bin::soChmod(path, mode);
    }

    /* ********************************************************* */

    int soChown(const char *path, uid_t owner, gid_t group)
    {
        return bin::soChown(path, owner, group);
    }

    /* ********************************************************* */

    int soUtime(const char *path, const struct utimbuf *times)
    {
        return bin::soUtime(path, times);
    }

    /* ********************************************************* */

    int soUtimens(const char *path, const struct timespec tv[2])
    {
        return bin::soUtimens(path, tv);
    }

    /* ********************************************************* */

    int soOpen(const char *path, int flags)
    {
        return bin::soOpen(path, flags);
    }

    /* ********************************************************* */

    int soClose(const char *path)
    {
        return bin::soClose(path);
    }

    /* ********************************************************* */

    int soFsync(const char *path)
    {
        return bin::soFsync(path);
    }

    /* ********************************************************* */

    int soOpendir(const char *path)
    {
        return bin::soOpendir(path);
    }

    int soClosedir(const char *path)
    {
        return bin::soClosedir(path);
    }

};

