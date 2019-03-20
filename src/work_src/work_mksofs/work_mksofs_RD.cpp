#include "work_mksofs.h"

#include "rawdisk.h"
#include "core.h"
#include "bin_mksofs.h"
#include "iostream"
#include <string.h>
#include <inttypes.h>

namespace sofs18
{
    namespace work
    {

        /*
         filling in the contents of the root directory:
         the first 2 entries are filled in with "." and ".." references
         the other entries are empty.
         If rdsize is 2, a second block exists and should be filled as well.
         */
        uint32_t fillInRootDir(uint32_t first_block, uint32_t rdsize)
        {
            soProbe(606, "%s(%u, %u)\n", __FUNCTION__, first_block, rdsize);
            
            /* change the following line by your code*/
            //return bin::fillInRootDir(first_block, rdsize);
           
            /* Array com todos os diretórios inicializados*/    
            SODirEntry array_dir[BlockSize];
                        /* Diretórios iniciais já atualizados */
            char root[2];
            char root2[3];
            strcpy(root,".\0");
            strcpy(root2,"..\0");

            unsigned int i;
            for (i=0; i<SOFS18_MAX_NAME && root[i]!='\0'; i++){
                 array_dir[0].name[i] = root[i];
            }

            array_dir[0].name[i] = '\0';
            array_dir[0].in = 0;

            for (i=0; i<SOFS18_MAX_NAME && root2[i]!='\0'; i++){
                array_dir[1].name[i] = root2[i];
            } 
            array_dir[1].name[i] = '\0';
            array_dir[1].in = 0;
            for (i=2; i<BlockSize; i++){
                memset(&array_dir[i].name[0], '\0',SOFS18_MAX_NAME+1);
                array_dir[i].in = NullReference;
            }
            
            if(rdsize<2){
                soWriteRawBlock(first_block, &array_dir);
                return 1;
            }
            else{
                int count = 0;
                for(uint32_t i=0;i<rdsize;i++){
                soWriteRawBlock(first_block+i, &array_dir[i]);
                count++;
                }
                return count;
            }

            
            
        }

    };

};


