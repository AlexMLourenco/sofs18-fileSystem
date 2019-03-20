/**
 *  \file
 *  \brief Student version of the \b sofs18 formatting functions.
 *
 *  \author Artur Pereira - 2018
 *
 *  \remarks See the main \c mksofs header file for documentation
 */

#ifndef __SOFS18_MKSOFS_WORK__
#define __SOFS18_MKSOFS_WORK__

#include <inttypes.h>

namespace sofs18
{
    namespace work
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

#endif   /* __SOFS18_MKSOFS_WORK__ */
