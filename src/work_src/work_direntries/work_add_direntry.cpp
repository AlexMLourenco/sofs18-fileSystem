#include "direntries.h"

#include "core.h"

#include "dal.h"

#include "fileblocks.h"

#include "bin_direntries.h"

#include <errno.h>

#include <string.h>

#include <sys/stat.h>

namespace sofs18

{

    namespace work

    {

        /**

     *  \brief Add a new entry to the parent directory.

     *

     *  A direntry is added connecting the parent inode to the child inode.

     *  The refcount of the child inode is not incremented by this function.

     *

     *  \param [in] pih inode handler of the parent inode

     *  \param [in] name the name of the entry to be created

     *  \param [in] cin inode number of the entry to be created

     */

        void soAddDirEntry(int pih, const char *name, uint32_t cin)

        {

            soProbe(202, "%s(%d, %s, %u)\n", __FUNCTION__, pih, name, cin);

            SOInode* parentNode = sofs18::soITGetInodePointer(pih);

            uint32_t block = NullReference;

            uint32_t node = NullReference;

            SODirEntry dir[DirentriesPerBlock];

            node = sofs18::soGetDirEntry(pih, name);

            uint32_t lastBlock = ((parentNode->size/sizeof(SODirEntry)))/DirentriesPerBlock;

            uint32_t lastIndex = ((parentNode->size/sizeof(SODirEntry)))%DirentriesPerBlock;

            if(node == NullReference){

                block = sofs18::soAllocFileBlock(pih,lastBlock);

                for(uint32_t i = 0; i<DirentriesPerBlock; i++){

                    dir[i].in = NullReference;

                    memset(&dir[i].name, '\0', SOFS18_MAX_NAME+1);

                }

                strcpy(dir[0].name, name);

                dir[0].in = cin;

                sofs18::soWriteFileBlock(pih, block, &dir);

                parentNode -> size+=sizeof(SODirEntry);

                return;

            }

            else{

                sofs18::soReadFileBlock(pih, lastBlock, &dir);

                strcpy(dir[lastIndex].name, name);

                dir[lastIndex].in = cin;

                sofs18::soWriteFileBlock(pih, block, &dir);

                parentNode -> size+=sizeof(SODirEntry);

                return;

            }

        }

    };

};


