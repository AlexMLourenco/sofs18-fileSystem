#include "work_fileblocks.h"

#include "dal.h"

#include "core.h"

#include "fileblocks.h"

#include "bin_fileblocks.h"

#include <string.h>

#include <inttypes.h>

namespace sofs18

{

    namespace work

    {

        /**

         *  \brief Write a data block.

         *

         *  Data is written into a specific data block which is supposed

         *  to belong to an inode associated to a file (a regular

         *  file, a directory or a symbolic link). 

         *

         *  If the referred block has not been allocated yet,

         *  it will be allocated now so that the data can be stored as its

         *  contents.

         *

         *  \param ih inode handler

         *  \param fbn file block number

         *  \param buf pointer to the buffer containing data to be written

         */

        void soWriteFileBlock(int ih, uint32_t fbn, void *buf)

        {

            soProbe(332, "%s(%d, %u, %p)\n", __FUNCTION__, ih, fbn, buf);

            /* change the following line by your code */

            //bin::soWriteFileBlock(ih, fbn, buf);

            uint32_t bn;

            bn = sofs18::soGetFileBlock(ih, fbn);

            if(bn == NullReference){

                bn = sofs18::soAllocFileBlock(ih, fbn);

            }

            sofs18::soWriteDataBlock(bn, buf);

        }

    };

};
