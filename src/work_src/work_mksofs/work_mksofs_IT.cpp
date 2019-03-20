#include "work_mksofs.h"

#include "rawdisk.h"
#include "core.h"
#include "bin_mksofs.h"

#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <inttypes.h>

namespace sofs18
{
    namespace work
    {

        uint32_t fillInInodeTable(uint32_t first_block, uint32_t itotal, uint32_t rdsize)
        {
            soProbe(604, "%s(%u, %u, %u)\n", __FUNCTION__, first_block, itotal, rdsize);
            
            uint32_t i = 0, j = 0;
            uint32_t rdnodes = 512*rdsize;

            uint32_t total_blocks = itotal/InodesPerBlock;
            if(itotal%InodesPerBlock != 0) total_blocks++;

            time_t data;
            data = time(0);
            uint32_t at;
            at = static_cast<uint32_t> (data);

            struct tm t;
            time_t t_of_day;

            t.tm_year = 70;
            t.tm_mon = 0;
            t.tm_mday = 1;
            t.tm_hour = 1;
            t.tm_min = 0;
            t.tm_sec = 0;
            t.tm_isdst = 1;
            t_of_day = mktime(&t);

            SOInode inodes[InodesPerBlock];

            uint32_t block = first_block;

            for(i=0; i<total_blocks;i++){
                
                for(j=0; j<InodesPerBlock;j++){
                    if(i==0 && j ==0){
                        inodes[j].mode      = S_IFDIR | 0775;
                        inodes[j].owner     = 1000;
                        inodes[j].group     = 1000;
                        inodes[j].lnkcnt    = 2;
                        inodes[j].atime     = at;
                        inodes[j].mtime     = at;
                        inodes[j].ctime     = at; 

                        inodes[j].d[0]      = 0;
                        if(rdsize == 2)     inodes[j].d[1] = 1;
                        else                inodes[j].d[1] = NullReference;
                        inodes[j].d[2]      = NullReference;
                        inodes[j].d[3]      = NullReference;

                        inodes[j].i1[0]     = NullReference;
                        inodes[j].i1[1]     = NullReference;
                        inodes[j].i2[0]     = NullReference;
                        inodes[j].i2[1]     = NullReference;

                        inodes[j].blkcnt    = rdsize;
                        inodes[j].size      = rdnodes;
                    }
                    else{
                        inodes[j].mode      = INODE_FREE;
                        inodes[j].owner     = 0;
                        inodes[j].group     = 0;
                        inodes[j].lnkcnt    = 0;

                        inodes[j].atime     = t_of_day;
                        inodes[j].mtime     = t_of_day;
                        inodes[j].ctime     = t_of_day; 

                        inodes[j].d[0]      = NullReference;
                        inodes[j].d[1]      = NullReference;
                        inodes[j].d[2]      = NullReference;
                        inodes[j].d[3]      = NullReference;

                        inodes[j].i1[0]     = NullReference;
                        inodes[j].i1[1]     = NullReference;
                        inodes[j].i2[0]     = NullReference;
                        inodes[j].i2[1]     = NullReference;

                        inodes[j].blkcnt    = 0;
                        inodes[j].size      = 0;
                    }
                }
                soWriteRawBlock((block),inodes);
                block++;
            }

            return total_blocks;            

            /* change the following line by your code */
            //return bin::fillInInodeTable(first_block, itotal, rdsize);
        }

    };

};

