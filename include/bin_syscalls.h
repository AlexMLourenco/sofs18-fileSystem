/**
 * \file
 * \brief Binary version of the \b sofs18 system calls
 *
 * The set of system calls are divided into two subsets:
 * \li one, contains the set of system calls for group work;
 * \li the other, constains the remaining required system calls
 *
 *  \author Artur Carneiro Pereira 2007-2009, 2016-2018
 *  \author Miguel Oliveira e Silva 2009, 2017
 *  \author António Rui Borges - 2010--2015
 *
 */

#ifndef __SOFS18_BIN_SYSCALLS__
#define __SOFS18_BIN_SYSCALLS__

#include <unistd.h>
#include <fcntl.h>
#include <inttypes.h>
#include <sys/types.h>
#include <sys/statvfs.h>
#include <sys/stat.h>
#include <time.h>
#include <utime.h>
#include <libgen.h>

namespace sofs18
{
    namespace bin
    {

        int soLink(const char *path, const char *newPath);

        int soUnlink(const char *path);

        int soRename(const char *path, const char *newPath);

        int soMknod(const char *path, mode_t mode);

        int soRead(const char *path, void *buff, uint32_t count, int32_t pos);

        int soWrite(const char *path, void *buff, uint32_t count, int32_t pos);

        int soTruncate(const char *path, off_t length);

        int soMkdir(const char *path, mode_t mode);

        int soRmdir(const char *path);

        int soReaddir(const char *path, void *buff, int32_t pos);

        int soSymlink(const char *effPath, const char *path);

        int soReadlink(const char *path, char *buff, size_t size);

        /* ******************************************************************* */

        int soOpenFileSystem(const char *devname);

        int soCloseFileSystem(void);

        int soStatFS(const char *path, struct statvfs *st);

        int soStat(const char *path, struct stat *st);

        int soAccess(const char *path, int opRequested);

        int soChmod(const char *path, mode_t mode);

        int soChown(const char *path, uid_t owner, gid_t group);

        int soUtime(const char *path, const struct utimbuf *times);

        int soUtimens(const char *path, const struct timespec tv[2]);

        int soOpen(const char *path, int flags);

        int soClose(const char *path);

        int soFsync(const char *path);

        int soOpendir(const char *path);

        int soClosedir(const char *path);

    };

};

#endif                          /* __SOFS18_BIN_SYSCALLS__ */
