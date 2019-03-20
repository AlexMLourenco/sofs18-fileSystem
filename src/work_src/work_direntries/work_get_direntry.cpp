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

        uint32_t soGetDirEntry(int pih, const char *name)

        {

            soProbe(201, "%s(%d, %s)\n", __FUNCTION__, pih, name);

            /* change the following line by your code */

            

            SOInode *inode = soITGetInodePointer(pih);

            uint32_t dpb = DirentriesPerBlock;

            uint32_t i, j, str;

            SODirEntry dir[dpb];

            for(i = 0; name[i] != '\0'; i++)

                if(name[i] == '/') throw SOException(EINVAL, __FUNCTION__);

            if(i-1 > SOFS18_MAX_NAME) throw(ENAMETOOLONG, __FUNCTION__);

            if((inode->mode & S_IFDIR) != S_IFDIR || (inode->mode & INODE_FREE) == INODE_FREE)

                throw SOException(ENOENT, __FUNCTION__);

            for(i=0; i< inode->size; i++){

                soReadFileBlock(pih, i, &dir);

                for(j = 0; j < inode->size/sizeof(SODirEntry); j++){

                    str = dir[j].in;

                    return str;

                }

            }           

            //return bin::soGetDirEntry(pih, name);

        }

    };

};



