#include "work_mksofs.h"
#include <math.h>
#include "core.h"
#include "bin_mksofs.h"

#include <inttypes.h>
#include <iostream>

namespace sofs18
{
namespace work
{
/*multiplo-função aux*/
int roundUp(int numToRound, int multiple)
{
    if (multiple == 0)
        return numToRound;

    int remainder = numToRound % multiple;
    if (remainder == 0)
        return numToRound;
    return numToRound + multiple - remainder;
}

void computeStructure(uint32_t ntotal, uint32_t &itotal, uint32_t &btotal, uint32_t &rdsize)
{
    soProbe(601, "%s(%u, %u, ...)\n", __FUNCTION__, ntotal, itotal);

    /* change the following line by your code */
    // bin::computeStructure(ntotal, itotal, btotal, rdsize);
   //  std::cout << "ntotal = " << ntotal << "\nitotal = " << itotal << "\nbtotal = " << btotal << "\n"
     ///         << "\rdSize = " << rdsize << "\n";
    /*itotal has maximum ntotal/4*/
    rdsize = 1;
    if (itotal > (ntotal >> 2))
    {
        std::cerr << "Can't be lorger than ntotal/4";
    }
    /*itotal gets the value divide by 8(2³) */
    itotal = (itotal == 0) ? roundUp(ntotal >> 3, 8) : roundUp(itotal, 8);
    /*The disk has at least 8blocks*/
    if (itotal < 8)
    {
        std::cerr << "The disk should have at least 8 blocks";
        return;
    }
    //itotal-nºtotal de inodes
    //itotal/inodePerBlock - nºde blocos para guardar os inodes
    //itotal/ReferencePerBlock - nº de referencias por bloco
    uint32_t N3N4 = (ntotal - 1 - (itotal / ((double)ReferencesPerBlock)) - itotal / ((double)InodesPerBlock));
    uint32_t resto = N3N4 % (ReferencesPerBlock + 1);
    uint32_t n3 = N3N4 / (ReferencesPerBlock + 1 * 1.0);
    if (resto != 0)
    {
        n3 = n3 + 1;
    }
    btotal = N3N4 - n3;
    if (resto == 1)
    {
        rdsize++;
        btotal = N3N4 - (n3 + 1);
    }
     //std::cout << "ntotal = " << ntotal << "\nitotal = " << itotal << "\nbtotal = " << btotal << "\n";
}

}; // namespace work

}; // namespace sofs18
