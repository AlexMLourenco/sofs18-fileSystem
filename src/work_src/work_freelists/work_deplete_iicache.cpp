/*
 *  \author António Rui Borges - 2012-2015
 *  \authur Artur Pereira - 2016-2018
 */

#include "work_freelists.h"

#include "core.h"
#include "dal.h"
#include "freelists.h"
#include "bin_freelists.h"

#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <iostream>
using namespace std;

namespace sofs18
{
namespace work
{

/*
         */
void soDepleteIICache(void)
{
    soProbe(404, "%s()\n", __FUNCTION__);

    /* change the following line by your code */
    // bin::soDepleteIICache();

    SOSuperBlock *sp = soSBGetPointer();
    uint32_t pos = (sp->filt_tail % ReferencesPerBlock);


    uint32_t *sp_filt = soFILTOpenBlock((sp->filt_tail / ReferencesPerBlock)); //devolve uo bloco a ser processado.

    /*n is the number of references can be added to the block*/
    uint32_t n = ReferencesPerBlock - pos;
    n = n <=INODE_REFERENCE_CACHE_SIZE ? n : INODE_REFERENCE_CACHE_SIZE; //source JM
    memcpy(sp_filt + (pos * sizeof(uint32_t)), &sp->iicache.ref[0],n * sizeof(uint32_t));
    memset(sp->iicache.ref,NullReference,sp->iicache.idx*sizeof(uint32_t));
    sp->iicache.idx -= n;
    sp->filt_tail = (pos + n) /ReferencesPerBlock;
    soSBSave();
    soFILTSaveBlock();
    soFILTCloseBlock();
}

}; // namespace work

}; // namespace sofs18
