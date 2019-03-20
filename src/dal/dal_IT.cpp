#include "dal.h"
#include "bin_dal.h"

#include "core.h"

#include <inttypes.h>

namespace sofs18
{
    /* ************************************** */

    void soITOpen()
    {
        bin::soITOpen();
    }

    /* ***************************************** */

    void soITClose()
    {
        bin::soITClose();
    }

    /* ************************************** */

    int soITOpenInode(uint32_t in)
    {
        return bin::soITOpenInode(in);
    }

    /* ************************************** */

    void soITSaveInode(int ih)
    {
        bin::soITSaveInode(ih);
    }

    /* ************************************** */

    void soITCloseInode(int ih)
    {
        bin::soITCloseInode(ih);
    }

    /* ************************************** */

    SOInode* soITGetInodePointer(int ih)
    {
        return bin::soITGetInodePointer(ih);
    }

    /* ************************************** */

    uint32_t soITGetInodeID(int ih)
    {
        return bin::soITGetInodeID(ih);
    }

    /* ************************************** */

};


