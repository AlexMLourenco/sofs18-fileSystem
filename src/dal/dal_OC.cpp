#include "dal.h"

#include "rawdisk.h"
#include "core.h"

#include <iostream>

namespace sofs18
{

    void soOpenDisk(const char * devname)
    {
        soProbe(SOPROBE_GREEN, 501, "%s(%s)\n", __FUNCTION__, devname);

        soOpenRawDisk(devname);
        soSBOpen();
        soITOpen();
    }

    void soCloseDisk()
    {
        soProbe(SOPROBE_GREEN, 502, "%s()\n", __FUNCTION__);

        soITClose();
        soSBClose();
        soCloseRawDisk();
    }

};

