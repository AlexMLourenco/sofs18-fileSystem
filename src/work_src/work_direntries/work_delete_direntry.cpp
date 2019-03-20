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

        uint32_t soDeleteDirEntry(int pih, const char *name)
        {

            soProbe(203, "%s(%d, %s, %s)\n", __FUNCTION__, pih, name);
            SOInode* inode = soITGetInodePointer(pih);
            SODirEntry dir[DirentriesPerBlock];
            uint32_t tmp;
            for(uint32_t i =0; i < inode->size/BlockSize; i++)
            {
                sofs18::soReadFileBlock(pih, i, dir
                );
                for(uint32_t j = 0; j <DirentriesPerBlock; j++)
                {
                    tmp = dir[j].in;
                    if(strcmp(dir[j].name, name) == 0)
                    {
                        memset(dir[j].name, '\0', SOFS18_MAX_NAME);
                        dir[j].in = NullReference;
                        sofs18::soWriteFileBlock(pih, i, dir);
                        return tmp;
                    }
                }
            /* change the following line by your code */
            }
        }
    };

};
