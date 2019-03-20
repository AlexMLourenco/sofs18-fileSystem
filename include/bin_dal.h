/**
 * \file
 * \brief Binary version of the disk abstraction layer module
 */

#ifndef __SOFS18_BIN_DAL__
#define __SOFS18_BIN_DAL__

#include <inttypes.h>

#include "superblock.h"
#include "inode.h"

namespace sofs18
{
    namespace bin
    {
        void soSBOpen();

        void soSBClose();

        void soSBSave();

        SOSuperBlock * soSBGetPointer();

        /* ***************************************** */

        uint32_t * soFILTOpenBlock(uint32_t bn);

        void soFILTSaveBlock();

        void soFILTCloseBlock();

        /* ***************************************** */

        void soITOpen();

        void soITClose();

        int soITOpenInode(uint32_t in);

        SOInode* soITGetInodePointer(int ih);

        void soITSaveInode(int ih);

        void soITCloseInode(int ih);

        uint32_t soITGetInodeID(int ih);

        /* ***************************************** */

        bool soCheckInodeAccess(int ih, int access);
        
        /* ***************************************** */

        uint32_t * soFBLTOpenBlock(uint32_t bn);

        void soFBLTSaveBlock();

        void soFBLTCloseBlock();

        /* ***************************************** */

        void soReadDataBlock(uint32_t bn, void *buf);

        void soWriteDataBlock(uint32_t bn, void *buf);
    };

};


#endif    /* __SOFS18_BIN_DAL__ */
