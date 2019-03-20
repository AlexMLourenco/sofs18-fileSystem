/*
 *  \file 
 *  \brief Student version of the functions to manage directory entries
 *
 *  \author Artur Pereira 2008-2009, 2016-2018
 *
 *  \remarks See the main \c direntries header file for documentation
 */

#ifndef __SOFS18_DIRENTRIES_WORK__
#define __SOFS18_DIRENTRIES_WORK__

#include <inttypes.h>

namespace sofs18
{
    namespace work
    {
        uint32_t soTraversePath(char *path);

        uint32_t soGetDirEntry(int pih, const char *name);

        void soAddDirEntry(int pih, const char *name, uint32_t cin);

        uint32_t soDeleteDirEntry(int pih, const char *name);

        void soRenameDirEntry(int pih, const char *name, const char *newName);

        bool soCheckDirEmpty(int ih);

    };

};

#endif             /* __SOFS18_DIRENTRIES_WORK__ */
