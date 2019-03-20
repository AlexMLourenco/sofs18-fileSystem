/**
 *  \file 
 *  \brief Binary version of function to manage file blocks
 *
 *  \author Artur Pereira - 2008-2009, 2016-2018
 *  \author Miguel Oliveira e Silva - 2009, 2017
 *  \author António Rui Borges - 2010-2015
 *
 */

#ifndef __SOFS18_FILEBLOCKS_BIN__
#define __SOFS18_FILEBLOCKS_BIN__

#include <inttypes.h>

namespace sofs18
{
    namespace bin
    {

        uint32_t soGetFileBlock(int ih, uint32_t fbn);

        uint32_t soAllocFileBlock(int ih, uint32_t fbn);

        void soFreeFileBlocks(int ih, uint32_t ffbn);

        void soReadFileBlock(int ih, uint32_t fbn, void *buf);

        void soWriteFileBlock(int ih, uint32_t fbn, void *buf);

    };

};

#endif             /* __SOFS18_FILEBLOCKS_BIN__ */
