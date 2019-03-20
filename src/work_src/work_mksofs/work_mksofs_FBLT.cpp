#include "work_mksofs.h"

#include "rawdisk.h"
#include "core.h"
#include "bin_mksofs.h"

#include <inttypes.h>
#include <string.h>
#include <math.h>
#include <iostream>
namespace sofs18
{
namespace work
{

uint32_t fillInFreeBlockListTable(uint32_t first_block, uint32_t btotal, uint32_t rdsize)
{
    soProbe(605, "%s(%u, %u, %u)\n", __FUNCTION__, first_block, btotal, rdsize);

    /* change the following line by your code */
    //return bin::fillInFreeBlockListTable(first_block, btotal, rdsize);
    std::cout << "estou aqui!";

    uint32_t block = ceil(btotal / ReferencesPerBlock);

    uint32_t ref[ReferencesPerBlock];

    uint32_t cnt = rdsize;

    uint32_t i, k, j;

    for (i = 0; i < block; i++)
    {

        for (k = 0; k < ReferencesPerBlock; k++)
        {

            ref[k] = cnt++;
        }

        soWriteRawBlock(first_block + i, ref);
    }

    if (btotal % ReferencesPerBlock != 0)
    {

        for (j = 0; j < ReferencesPerBlock; j++)
        {

            if (cnt <= btotal - 1)

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
