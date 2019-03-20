#include "work_fileblocks.h"

#include "freelists.h"
#include "dal.h"
#include "core.h"
#include "bin_fileblocks.h"

#include <inttypes.h>
#include <errno.h>
#include <assert.h>

namespace sofs18
{
    namespace work
    {

#if 1
        /* free all blocks between positions ffbn and ReferencesPerBlock - 1
         * existing in the block of references given by i1.
         * Return true if, after the operation, all references become NullReference.
         * It assumes i1 is valid.
         */
        static bool soFreeIndirectFileBlocks(SOInode * ip, uint32_t i1, uint32_t ffbn);
        
        /* free all blocks between positions ffbn and ReferencesPerBloc**2 - 1
         * existing in the block of indirect references given by i2.
         * Return true if, after the operation, all references become NullReference.
         * It assumes i2 is valid.
         */
        static bool soFreeDoubleIndirectFileBlocks(SOInode * ip, uint32_t i2, uint32_t ffbn);
#endif

        /* ********************************************************* */

        void soFreeFileBlocks(int ih, uint32_t ffbn)
        {
                soProbe(303, "%s(%d, %u)\n", __FUNCTION__, ih, ffbn);

                /* change the following line by your code */
               //bin::soFreeFileBlocks(ih, ffbn);

               
                if(ffbn>=N_DIRECT+ReferencesPerBlock*N_INDIRECT+ReferencesPerBlock*ReferencesPerBlock)
                {
                        throw SOException(ENOSYS, __FUNCTION__);
                }

                SOInode *ip =  soITGetInodePointer(ih);
                uint32_t bn ;  // block number
                uint32_t rb ;  // block reference 

                for(bn = ffbn ; bn < N_DIRECT ; bn ++)
                {
                        rb = ip->d[bn];
                        if(rb != NullReference)
                        {
                                soFreeDataBlock(rb);
                                ip->d[bn] = NullReference;
                                ip->blkcnt--;
                        }

                }

                uint32_t *i1 = ip->i1;
                uint32_t *i2 = ip->i2;
                uint32_t indx ;
                for(indx =1 ; indx < N_INDIRECT ; indx ++)
                {
                        if((i1[indx] !=NullReference) & (ffbn<(N_DIRECT+ (indx*ReferencesPerBlock))))
                                soFreeIndirectFileBlocks(ip,indx,ffbn);
                        
                }
                
                for(indx =1; indx < N_DOUBLE_INDIRECT;indx ++)
                {       
                        if((i2[indx] != NullReference) & (ffbn<(N_DIRECT +(N_INDIRECT*ReferencesPerBlock) + (indx)*(ReferencesPerBlock*ReferencesPerBlock)))){
                                soFreeDoubleIndirectFileBlocks(ip,indx , ffbn);
                        }
                                
                }
              
        }

        /* ********************************************************* */

#if 1
        static bool soFreeIndirectFileBlocks(SOInode * ip, uint32_t i1, uint32_t ffbn)
        {
                soProbe(303, "%s(..., %u, %u)\n", __FUNCTION__, i1, ffbn);
               /* change the following line by your code */
              
                uint32_t ref[ReferencesPerBlock];

                soReadDataBlock(ip->i1[i1],ref);
                uint32_t refi;
                for(refi=0;refi< ReferencesPerBlock ; refi++)
                {
                       if(ip->blkcnt <=0)
                               return false;
                        if((N_DIRECT+refi*i1) >= ffbn){
                                if(ref[refi] != NullReference){
                                        soFreeDataBlock(ref[refi]);
                                        ref[refi]= NullReference;
                                        ip->blkcnt--;

                                }
                        }
                }
         
                soWriteDataBlock(ip->i1[i1],ref);
                
                // verificar se esta vazia para limpar
                uint32_t flagg = 1;
                uint32_t i ;
                for(i = 0; i < ReferencesPerBlock ; i ++)      
                {
                        if(ref[i]!=NullReference){
                           flagg=0;
                        }
     

                } 
                if(flagg==1){
                        soFreeDataBlock(ip->i1[i1]);
                        ip->blkcnt--;
                }
               
                return true;
        }       
#endif

        /* ********************************************************* */

#if 1
        static bool soFreeDoubleIndirectFileBlocks(SOInode * ip, uint32_t i2, uint32_t ffbn)
        {
                soProbe(303, "%s(..., %u, %u)\n", __FUNCTION__, i2, ffbn);

          
            uint32_t r1[ReferencesPerBlock];
            uint32_t r2[ReferencesPerBlock];

            uint32_t refi;
            uint32_t refdi;

            soReadDataBlock(ip->i2[i2], r1);

                for(refi = 0; refi < ReferencesPerBlock; refi++){
                        if(r1[refi] != NullReference){ 
                                soReadDataBlock(r1[refi], r2);                      
                                for(refdi = 0; refdi < ReferencesPerBlock; refdi++){
                                        if(r2[refdi] != NullReference){              
                                                soFreeDataBlock(r2[refdi]);
                                                r2[refdi] = NullReference;
                                                ip->blkcnt--;
                                        }
                                }

                        soFreeDataBlock(r1[refi]);
                        r1[refi] = NullReference;
                        ip->blkcnt--;

                        soWriteDataBlock(r1[refi], r2);                      
                }
        }
        soWriteDataBlock(ip->i2[i2],r1);
        uint32_t flag = 1;
        uint32_t flagi ;
        uint32_t i;
        uint32_t j;
        // verificar se esta vazia para limpar 
        for(i =0 ; i < ReferencesPerBlock ; i ++){
                if(r1[i]!=NullReference){
                        flag=0;
                        flagi=1;
                        soReadDataBlock(r1[j],r2);
                        for(j = 0 ; j < ReferencesPerBlock ; j ++)
                        {
                                if(r2[j]!=NullReference)   
                                        flagi=0;
                        }
                        if(flagi==1)
                        {
                                soFreeDataBlock(r1[j]);
                                r1[refi] = NullReference;
                                ip->blkcnt--;       
                        }
                }
                if(flag == 1){
                        ip->i2[i2]=NullReference;
                        soFreeDataBlock(ip->i2[i2]);
                        ip->blkcnt--;
                }

        }

        return true;

}
#endif

        /* ********************************************************* */

    };

};

