#include "direntries.h"

#include "core.h"
#include "dal.h"
#include "fileblocks.h"
#include "direntries.h"
#include "bin_direntries.h"

#include <errno.h>
#include <string.h>
#include <libgen.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <iostream>

namespace sofs18
{
    namespace work
    {

        uint32_t soTraversePath(char *path)
        {
            soProbe(221, "%s(%s)\n", __FUNCTION__, path);

            /* change the following line by your code */
            
            uint32_t ih = soITOpenInode(0);
            SOInode* inode = soITGetInodePointer(ih);
            char *pch = strtok (path, "/");  
            int temp;
            while (pch != NULL){
                temp =  sofs18::soGetDirEntry(ih,pch);
                ih = soITOpenInode(temp);
                pch = strtok (NULL, " ,");
            }
            
    
            return temp;
        }

    };

};

