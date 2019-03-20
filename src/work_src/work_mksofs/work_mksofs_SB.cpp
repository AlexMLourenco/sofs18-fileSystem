#include "work_mksofs.h"
#include <math.h>
#include "rawdisk.h"
#include <iostream>
#include "core.h"
#include "bin_mksofs.h"

#include <string.h>
#include <inttypes.h>

namespace sofs18
{

    namespace work
    {
     
        uint32_t round(uint32_t dive , uint32_t divis){
            return (dive+divis-1)/divis;

        }

        void fillInSuperBlock(const char *name, uint32_t ntotal, uint32_t itotal, uint32_t rdsize)
        {

            //bin::fillInSuperBlock(name, ntotal, itotal, rdsize);
            
            soProbe(602, "%s(%s, %u, %u, %u)\n", __FUNCTION__, name, ntotal, itotal, rdsize);
            
            /* change the following line by your code */

            SOSuperBlock sup;

            soReadRawBlock(0 , &sup); // superblock starts 0 

            sup.magic =0xFFFF;
            sup.version = VERSION_NUMBER;
            memset(sup.name , '\0' , PARTITION_NAME_SIZE +1);
            for(int c =0 ; c<PARTITION_NAME_SIZE;c++ )
            {
                sup.name[c] = *name;
                name++; 
            }

            sup.name[PARTITION_NAME_SIZE+1]='\0';

            sup.mntstat = 1; // proply unmounted=1 ? :otherwise
            sup.mntcnt = 0; // start point
            sup.ntotal = ntotal; // number of blocks in the device
            
            //free inode list table

            sup.filt_start = 1;
            sup.filt_size = round(itotal,ReferencesPerBlock); 
            sup.filt_head= 0;
            sup.filt_tail= itotal-1;


            //inode table

            sup.it_size=itotal/InodesPerBlock;
             /** \brief physical number of the block where the inode table starts */
            sup.it_start=sup.filt_size + sup.filt_start;

            //inode 
            sup.itotal= itotal;
            sup.ifree = itotal-1;


            // Data blocks' metadata
            uint32_t n3n4=ntotal-round(itotal,ReferencesPerBlock)-round(itotal,InodesPerBlock)-rdsize-1;
            n3n4 = rdsize==2?n3n4+1:n3n4;//verificar tamanho rtsizie
            //std::cout <<itotal/ReferencesPerBlock << "/n"<< round(itotal,ReferencesPerBlock);
            sup.fblt_start=sup.it_start + sup.it_size;
            sup.fblt_size=round(n3n4,ReferencesPerBlock);
            sup.fblt_head=0;
            sup.dz_total=n3n4-sup.fblt_size + rdsize;
            sup.fblt_tail=sup.dz_total - 1;//+1 ??

            //DATA ZONE

             /** \brief physical number of the block where the data zone starts */
            sup.dz_start=sup.fblt_start+sup.fblt_size;

            /** \brief total number of blocks in data zone */
            

            /** \brief number of free blocks in data zone */
            sup.dz_free=sup.dz_total-rdsize;


            

            //cache 

            SOInodeReferenceCache irCch;               // Retrieval cache
            SOInodeReferenceCache iiCch;               // Insert cache

            irCch.idx = INODE_REFERENCE_CACHE_SIZE;
            iiCch.idx = 0;

            for (uint32_t c = 0 ; c < INODE_REFERENCE_CACHE_SIZE; c++ )
            {
                irCch.ref[c] = NullReference;
                iiCch.ref[c] = NullReference;
            }

            sup.ircache = irCch;
            sup.iicache = iiCch;

            SOBlockReferenceCache brCch;              // Retrieval cache 
            SOBlockReferenceCache biCch;              // Insert cache 

            brCch.idx = BLOCK_REFERENCE_CACHE_SIZE;
            biCch.idx = 0;

            for (uint32_t c =0 ;c < BLOCK_REFERENCE_CACHE_SIZE; c++ )
            {
                brCch.ref[c] = NullReference;
                biCch.ref[c] = NullReference;
            }

            sup.brcache = brCch; 
            sup.bicache = biCch;

            soWriteRawBlock(0,&sup);

           
        }

    };

};

