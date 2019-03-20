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

        void soReadFileBlock(int ih, uint32_t fbn, void *buf)

        {

            soProbe(331, "%s(%d, %u, %p)\n", __FUNCTION__, ih, fbn, buf);

            if(fbn > N_DIRECT + ReferencesPerBlock)

                    throw SOException(ENOSPC, __FUNCTION__);

            uint32_t bn = soGetFileBlock(ih, fbn); // Get the data block number of the given file block

            if(bn == NullReference) // if the referred file block has not been allocated yet

                    memset(buf, '\0', 1); // byte stream filled with the character null

            else

                    soReadDataBlock(bn, buf); // Read a block of the data zone

        }

    };

};



