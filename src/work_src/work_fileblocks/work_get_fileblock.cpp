#include "work_fileblocks.h"

#include "dal.h"
#include "core.h"
#include "bin_fileblocks.h"
#include <errno.h>

namespace sofs18
{
namespace work
{

/* ********************************************************* */

#if 1
static uint32_t soGetIndirectFileBlock(SOInode *ip, uint32_t fbn);
static uint32_t soGetDoubleIndirectFileBlock(SOInode *ip, uint32_t fbn);
#endif

/* ********************************************************* */

uint32_t soGetFileBlock(int ih, uint32_t fbn)
{
    soProbe(301, "%s(%d, %u)\n", __FUNCTION__, ih, fbn);

    /* change the following line by your code */
    //  return bin::soGetFileBlock(ih, fbn);
    SOInode *inode;
    inode = soITGetInodePointer(ih);
    if (fbn < N_DIRECT)
    {
        return inode->d[fbn];
    }
    else if (fbn < (N_DIRECT + (N_INDIRECT)*ReferencesPerBlock - 1))
    {
        return soGetIndirectFileBlock(inode, fbn - N_DIRECT);
    }
    else
    {
        return soGetDoubleIndirectFileBlock(inode, fbn - N_DIRECT -(N_INDIRECT *ReferencesPerBlock)- N_INDIRECT);
    }
}

/* ********************************************************* */

#if 1
static uint32_t soGetIndirectFileBlock(SOInode *ip, uint32_t afbn)
{
    soProbe(301, "%s(%d, ...)\n", __FUNCTION__, afbn);
    uint32_t d[ReferencesPerBlock];
    /*verifica se é menor que 128, se sim vai para i1[0] senao acede ao i1[1]*/
    soReadDataBlock(ip->i1[afbn / ReferencesPerBlock], &d);
    /*retona o valor associado a pos*/
    return d[afbn % ReferencesPerBlock];
    /* change the following two lines by your code */
    throw SOException(ENOSYS, __FUNCTION__);
}
#endif

/* ********************************************************* */

#if 1
static uint32_t soGetDoubleIndirectFileBlock(SOInode *ip, uint32_t afbn)
{
    soProbe(301, "%s(%d, ...)\n", __FUNCTION__, afbn);
    uint32_t d[ReferencesPerBlock];
    soReadDataBlock(ip->i2[afbn / (ReferencesPerBlock * ReferencesPerBlock)], &d);
    soReadDataBlock(d[afbn / ReferencesPerBlock], &d);
    return d[afbn%ReferencesPerBlock];
    /* change the following two lines by your code */
    throw SOException(ENOSYS, __FUNCTION__);
    
}
#endif

}; // namespace work

}; // namespace sofs18
