#include "work_mksofs.h"

#include "rawdisk.h"
#include "core.h"
#include "bin_mksofs.h"

#include <inttypes.h>
#include <string.h>
#include <math.h>
namespace sofs18
{
namespace work
{

uint32_t fillInFreeInodeListTable(uint32_t first_block, uint32_t itotal)
{
    soProbe(603, "%s(%u, %u)\n", __FUNCTION__, first_block, itotal);

    /* change the following line by your code */
    //return bin::fillInFreeInodeListTable(first_block, itotal);
    uint32_t block = ceil(itotal / ReferencesPerBlock);

    uint32_t ref[ReferencesPerBlock];

    uint32_t cnt = itotal;

    uint32_t i, k, j;

    for (i = 0; i < block; i++)
    {

        for (k = 0; k < ReferencesPerBlock; k++)
        {

            ref[k] = cnt++;
        }

        soWriteRawBlock(first_block + i, ref);
    }

    if (itotal % ReferencesPerBlock != 0)
    {

        for (j = 0; j < ReferencesPerBlock; j++)
        {

            if (cnt <= itotal - 1)

                ref[j] = cnt++;

            else

                ref[j] = NullReference;
        }

        soWriteRawBlock(first_block + block, ref);

        block++;
    }

    return block;
}

}; // namespace work

}; // namespace sofs18
