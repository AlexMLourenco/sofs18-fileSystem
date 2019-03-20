#include "direntries.h"

#include "core.h"
#include "dal.h"
#include "fileblocks.h"
#include "bin_direntries.h"

#include <errno.h>
#include <string.h>
#include <iostream>
#include <sys/stat.h>

namespace sofs18
{
    namespace work
    {

        bool soCheckDirEmpty(int ih)
        {
            soProbe(205, "%s(%d)\n", __FUNCTION__, ih);

            /* change the following line by your code */
            //return bin::soCheckDirEmpty(ih);
            //fbn to traverse direct|indirect|double_indirect entries
            uint32_t fbn,z;
            SODirEntry block[BlockSize];
            SOInode *inode = soITGetInodePointer(ih);
            bool last = false;
            for(fbn=0;fbn<(N_DIRECT + N_INDIRECT*ReferencesPerBlock + N_DOUBLE_INDIRECT*(ReferencesPerBlock*ReferencesPerBlock));fbn++){
                if(!last && sofs18::soGetFileBlock(ih,fbn)!= NullReference){
                    sofs18::soReadFileBlock(ih,fbn,&block);
                    for(z = 0; z<DirentriesPerBlock; z++){
                        if(block[z].in != NullReference ){
                            if(!(strcmp(block[z].name, ".")==0 || strcmp(block[z].name, ".")==0)){
                                if(!((block[z].in | 0) == 0)){
                                    return false;
                                }
                            }
                        }
                    }
                }
                else{
                    last = true;
                }       
            }
            return true;
        }

    };

};

