#include "work_fileblocks.h"

#include "freelists.h"
#include "dal.h"
#include "core.h"
#include "bin_fileblocks.h"

#include <errno.h>
#include <string.h>
#include <iostream>

namespace sofs18
{
    namespace work
    {

#if 1
        static uint32_t soAllocIndirectFileBlock(SOInode * ip, uint32_t afbn);
        static uint32_t soAllocDoubleIndirectFileBlock(SOInode * ip, uint32_t afbn);
#endif

        /* ********************************************************* */

        uint32_t soAllocFileBlock(int ih, uint32_t fbn)
        {
            soProbe(302, "%s(%d, %u)\n", __FUNCTION__, ih, fbn);
            
            /* change the following two lines by your code */
            //return bin::soAllocFileBlock(ih, fbn);
            uint32_t block;
            SOSuperBlock *spb = soSBGetPointer();
            SOInode* inode = soITGetInodePointer(ih);
           

            if((fbn < 0) || (fbn > (N_DIRECT + N_INDIRECT*ReferencesPerBlock + ReferencesPerBlock*ReferencesPerBlock))){
                throw SOException(EINVAL, __FUNCTION__);
            }
            
            if(fbn < N_DIRECT){
                uint32_t block = sofs18::soAllocDataBlock();
                
                if (inode->d[fbn]==NullReference){
        	        inode->blkcnt += 1;
                }
                inode->size += 512;
                inode->d[fbn] = block;
                inode->ctime = time(NULL);
                inode->mtime = time(NULL);
                inode->atime = time(NULL);

                spb->dz_free--;
                soITSaveInode(ih);
                soSBSave();
                return block;
            }
            else if(fbn < (N_DIRECT + N_INDIRECT*ReferencesPerBlock)){
                block = soAllocIndirectFileBlock(inode, fbn);
                
                inode->ctime = time(NULL);
                inode->mtime = time(NULL);
                inode->atime = time(NULL);

                soITSaveInode(ih);
                soSBSave();
                return block;
            }
            else{
                block = soAllocDoubleIndirectFileBlock(inode, fbn);
                inode->ctime = time(NULL);
                inode->mtime = time(NULL);
                inode->atime = time(NULL);

                soITSaveInode(ih);
                soSBSave();
                return block;
            }  
    
        }

        /* ********************************************************* */

#if 1
        /*
         */
        static uint32_t soAllocIndirectFileBlock(SOInode * ip, uint32_t afbn)
        {
            soProbe(302, "%s(%d, ...)\n", __FUNCTION__, afbn);

            /* change the following two lines by your code */
            //throw SOException(ENOSYS, __FUNCTION__); 
            SOSuperBlock *spb = soSBGetPointer();
            uint32_t fbn = afbn - N_DIRECT;
            uint32_t ref[ReferencesPerBlock];
            
            if(ip->i1[fbn / ReferencesPerBlock] == NullReference){
                memset(ref, NullReference, BlockSize);
                
                uint32_t block = sofs18::soAllocDataBlock();
                ip->i1[fbn / ReferencesPerBlock] = block;
                ip->blkcnt+=1;
                spb->dz_free--;
                sofs18::soWriteDataBlock(ip->i1[fbn / ReferencesPerBlock], ref);
            
            }
            sofs18::soReadDataBlock(ip->i1[fbn / ReferencesPerBlock], &ref);
            uint32_t block2  = sofs18::soAllocDataBlock(); 
            ip->blkcnt+=1;
            spb->dz_free--;

    	    ref[fbn % ReferencesPerBlock] = block2;
        
            soWriteDataBlock(ip->i1[fbn / ReferencesPerBlock], &ref);
            return block2;
            
            
        }
#endif

        /* ********************************************************* */

#if 1
        /*
         */
        static uint32_t soAllocDoubleIndirectFileBlock(SOInode * ip, uint32_t afbn)
        {
            soProbe(302, "%s(%d, ...)\n", __FUNCTION__, afbn);

            /* change the following two lines by your code */
            //throw SOException(ENOSYS, __FUNCTION__); 
            SOSuperBlock *spb = soSBGetPointer();
            uint32_t fbn = afbn-(N_DIRECT + N_INDIRECT*ReferencesPerBlock);
            uint32_t ref[ReferencesPerBlock];
            uint32_t ref2[ReferencesPerBlock];
            std::cout<< fbn/ReferencesPerBlock;
            if (ip->i2[fbn / ReferencesPerBlock] == NullReference) {

		        /* Alocar do primeiro bloco livre disponível */
	    	    uint32_t block = sofs18::soAllocDataBlock();
		
		        /* Colocar a primeira referencia indireta para alocar o número do data block */
	  	        ip->i2[fbn / ReferencesPerBlock] = block;
		
		        /* block iniciaçizado com refercias as NulReference*/
		        memset(ref, NullReference, BlockSize);
		
		        /* Guardar as referências do block no buffer */
	  	        sofs18::soWriteDataBlock(ip->i2[fbn / ReferencesPerBlock], &ref);

		        /* Incrementar o número total de blocks usados no inode */
   		        ip->blkcnt++;	
                spb->dz_free--;
                soSBSave();
	        }
	
	        /* Carregar a referência do block no buffer */
	        sofs18::soReadDataBlock(ip->i2[fbn / ReferencesPerBlock], &ref);

	        /* Verificar se existem referências na variável i2 */
            /* Se não houver é necessário alocar */
            if (ref[fbn / ReferencesPerBlock] == NullReference) 
	        {
		        /* Alocar do primeiro block livre disponível */	
		        uint32_t block3 = sofs18::soAllocDataBlock();

		        /* Colocar o número do block alocado na referência correspondente */
		        ref[fbn / ReferencesPerBlock] = block3;

		        /* block iniciaçizado com refercias as NullReference*/
		        memset(ref2, NullReference, BlockSize);

		        /* Guardar as referências do block no buffer */
	  	        sofs18::soWriteDataBlock(ref[fbn / ReferencesPerBlock], &ref2);
		        /* Incrementar o número total de blocks usados no inode */
   		        ip->blkcnt++;
                spb->dz_free--;
	        }

	        /* Guardar o valor do indice para a segunda referência */
	        uint32_t ref_clust_idx = ref[fbn / ReferencesPerBlock];

	        /* Guardar as referências do block no buffer */
	        sofs18::soWriteDataBlock(ip->i2[fbn / ReferencesPerBlock], &ref);	
	
	        /* Carregar a referência do block no buffer */
	        sofs18::soReadDataBlock(ref_clust_idx, &ref);

	        /* Alocar do primeiro block livre disponível */	
	        uint32_t block3 = sofs18::soAllocDataBlock();

	        /* Incrementar o número total de blocks usados no inode */
   	        ip->blkcnt++;
            spb->dz_free--;
	
	        /* Colocar o número do block alocado na referência correspondente */
	        ref[fbn % ReferencesPerBlock] = block3;

	        /* Guardar as referências do block no buffer */
            sofs18::soWriteDataBlock(ref_clust_idx, ref);
            soSBSave();
            return block3;
        }
#endif

    };

};

