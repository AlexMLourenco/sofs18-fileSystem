#include "work_mksofs.h"

#include "rawdisk.h"
#include "core.h"
#include "bin_mksofs.h"

#include <string.h>
#include <inttypes.h>

namespace sofs18
{
    namespace work
    {

        void resetBlocks(uint32_t first_block, uint32_t cnt)
        {
            soProbe(607, "%s(%u, %u)\n", __FUNCTION__, first_block, cnt);
            
            /* change the following line by your code */
            //bin::resetBlocks(first_block, cnt);

            uint32_t block[BlockSize];

            memset(block , 0 , BlockSize);

            for( uint32_t i = 0 ; i < cnt ; i++  )
            {
                soWriteRawBlock((first_block+i) ,block);
            }
        }

    };

};

