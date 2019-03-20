/**
 *  \file 
 *  \brief Binary version of functions to manage directories and directory entries
 *
 *  \author Artur Pereira 2008-2009, 2016-2018
 *  \author Miguel Oliveira e Silva 2009, 2017
 *  \author António Rui Borges - 2012-2015
 *
 */

#ifndef __SOFS18_DIRENTRIES_BIN__
#define __SOFS18_DIRENTRIES_BIN__

#include <inttypes.h>

namespace sofs18
{
    namespace bin
    {

        uint32_t soTraversePath(char *path);

        uint32_t soGetDirEntry(int pih, const char *name);

        void soAddDirEntry(int pih, const char *name, uint32_t cin);

        uint32_t soDeleteDirEntry(int pih, const char *name);

        void soRenameDirEntry(int pih, const char *name, const char *newName);

        bool soCheckDirEmpty(int ih);

    };

};

#endif             /* __SOFS18_DIRENTRIES_BIN__ */
