/**
 *  \file
 *  \brief Definition of the directory entry data type.
 *
 *  \author Artur Pereira - 2008-2009, 2016-2018
 *  \author Miguel Oliveira e Silva - 2009, 2017
 *  \author António Rui Borges - 2010-2015
 */

#ifndef __SOFS18_DIRENTRY__
#define __SOFS18_DIRENTRY__

#include <inttypes.h>

namespace sofs18
{
    /**
     * \defgroup direntry direntry
     * \ingroup core
     * \brief The SODirEntry data type
     * @{
     */

    /** 
     * \brief maximum length of a file name (in characters)
     */
#define SOFS18_MAX_NAME 27

    /** \brief Definition of the directory entry data type. */
    struct SODirEntry
    {
        /** \brief the associated inode number */
        uint32_t in;
        /** \brief the name of a file (NULL-terminated string) */
        char name[SOFS18_MAX_NAME + 1];
    };

    /** @} */

};

#endif				/* __SOFS18_DIRENTRY__ */
