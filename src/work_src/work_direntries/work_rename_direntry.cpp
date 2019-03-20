#include "direntries.h"

#include "core.h"
#include "dal.h"
#include "fileblocks.h"
#include "bin_direntries.h"

#include <string.h>
#include <errno.h>
#include <sys/stat.h>

namespace sofs18
{
    namespace work
    {

        void soRenameDirEntry(int pih, const char *name, const char *newName)
        {
            soProbe(204, "%s(%d, %s, %s)\n", __FUNCTION__, pih, name, newName);

            /* change the following line by your code */
            //bin::soRenameDirEntry(pih, name, newName);
            SODirEntry block[BlockSize];
            uint32_t z,i,fbn;
            bool found=false;
            for(fbn=0;fbn<(N_DIRECT + N_INDIRECT*ReferencesPerBlock + N_DOUBLE_INDIRECT*(ReferencesPerBlock*ReferencesPerBlock)-1);fbn++){
                if(!(sofs18::soGetFileBlock(pih,fbn)== NullReference)){
                    sofs18::soReadFileBlock(pih,fbn,&block);
                    for(z = 0; z<DirentriesPerBlock; z++){
                        if(strcmp(block[z].name,name)==0){
                            found = true;
                            for (i=0; i<SOFS18_MAX_NAME && newName[i]!='\0'; i++){
                                if(newName[i]=='/'){
					                throw SOException(EINVAL, __FUNCTION__);
                                }
                                block[z].name[i] = newName[i];
                            }
                            sofs18::soWriteFileBlock(pih,fbn, &block);
                        }
                    }
                } 
            }
            if(!found){
                throw SOException(ENOENT,__FUNCTION__);
            }
            soITSaveInode(pih);
            

        }

    };

};

