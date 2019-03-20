/**
 * \file
 * \brief Binary version of functions to manage the list of free inodes 
 *      and the list of free blocks
 * 
 *  \author Artur Pereira 2008-2009, 2016-2018
 *  \author Miguel Oliveira e Silva 2009, 2017
 *  \author António Rui Borges - 2010-2015
 *
 */

/*
 * \defgroup freelists freelists
 *
 * @{
 *
 *  \remarks In case an error occurs, every function throws an SOException
 */

#ifndef __SOFS18_FREELISTS_BIN__
#define __SOFS18_FREELISTS_BIN__

#include <inttypes.h>

namespace sofs18
{
    namespace bin
    {

        uint32_t soAllocInode(uint32_t type);

        void soFreeInode(uint32_t in);

        uint32_t soAllocDataBlock();

        void soReplenishIRCache();

        void soReplenishBRCache();

        void soFreeDataBlock(uint32_t cn);

        void soDepleteIICache();

        void soDepleteBICache();

    };

};

#endif				/* __SOFS18_FREELISTS_BIN__ */
