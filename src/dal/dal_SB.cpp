#include "dal.h"
#include "bin_dal.h"

#include <string.h>
#include <inttypes.h>

namespace sofs18
{
    /* ***************************************** */

    void soSBOpen()
    {
        bin::soSBOpen();
    }

    /* ***************************************** */

    void soSBSave()
    {
        bin::soSBSave();
    }

    /* ***************************************** */

    void soSBClose()
    {
        bin::soSBClose();
    }

    /* ***************************************** */

    SOSuperBlock * soSBGetPointer()
    {
        return bin::soSBGetPointer();
    }

    /* ***************************************** */
};

