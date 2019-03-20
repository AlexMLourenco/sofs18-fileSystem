/**
 *  \file
 *  \brief Binary version of the \b sofs18 formatting functions.
 *
 *  \author Artur Pereira - 2007-2009, 2016-2018
 *  \author Miguel Oliveira e Silva - 2009, 2017
 *  \author António Rui Borges - 2010-2015
 */

#ifndef __SOFS18_MKSOFS_BIN__
#define __SOFS18_MKSOFS_BIN__

#include <inttypes.h>

namespace sofs18
{
    namespace bin
    {

        void computeStructure(uint32_t ntotal, uint32_t & itotal, uint32_t & btotal, uint32_t & rdsize);

        void fillInSuperBlock(const char *name, uint32_t ntotal, uint32_t itotal, uint32_t rdsize);

        uint32_t fillInFreeInodeListTable(uint32_t first_block, uint32_t itotal);

        uint32_t fillInInodeTable(uint32_t first_block, uint32_t itotal, uint32_t rdsize);

        uint32_t fillInFreeBlockListTable(uint32_t first_block, uint32_t btotal, uint32_t rdsize);

        uint32_t fillInRootDir(uint32_t first_block, uint32_t rdsize);

        void resetBlocks(uint32_t first_block, uint32_t cnt);

    };

};

#endif   /* __SOFS18_MKSOFS_BIN__ */
