#include "dal.h"
#include "bin_dal.h"

namespace sofs18
{
    bool soCheckInodeAccess(int ih, int access)
    {
        return bin::soCheckInodeAccess(ih, access);
    }

};



