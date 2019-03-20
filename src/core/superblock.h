/**
 *  \file 
 *  \brief Definition of the superblock data type.
 *
 *  \author Artur Pereira - 2008-2009, 2016-2018
 *  \author Miguel Oliveira e Silva - 2009, 2017
 *  \author António Rui Borges - 2010-2015
 */

#ifndef __SOFS18_SUPERBLOCK__
#define __SOFS18_SUPERBLOCK__

#include <inttypes.h>

namespace sofs18
{
    /** \defgroup superblock superblock
     * \brief The \c SOSuperBlock data type
     * \ingroup core
     */

    /** \brief sofs18 magic number 
     * \ingroup superblock
     */
#define MAGIC_NUMBER 0x50F5

    /** \brief sofs18 version number 
     * \ingroup superblock
     */
#define VERSION_NUMBER 0x2018

    /** \brief maximum length of volume name 
     * \ingroup superblock
     */
#define PARTITION_NAME_SIZE 17

    /** \brief size of caches in superblock for inode references
     * \ingroup superblock
     */
#define INODE_REFERENCE_CACHE_SIZE 20

    /** \brief size of caches in superblock for block references
     * \ingroup superblock
     */
#define BLOCK_REFERENCE_CACHE_SIZE 31

    /**
     *  \ingroup superblock
     *  \brief Definition of the inode cache data type.
     *  \details It describes a cache area within the superblock for references to free inodes.
     */
    struct SOInodeReferenceCache {
        /** \brief storage area whose elements are references of free inodes */
        uint32_t ref[INODE_REFERENCE_CACHE_SIZE];  ///< the cache area
        uint32_t idx;                        ///< retrieval/insertion point
    };

    /**
     *  \ingroup superblock
     *  \brief Definition of the data block cache data type.
     *  \details It describes a cache area within the superblock for references to free data blocks.
     */
    struct SOBlockReferenceCache {
        /** \brief storage area whose elements are references of free data blocks */
        uint32_t ref[BLOCK_REFERENCE_CACHE_SIZE];  ///< the cache area
        uint32_t idx;                        ///< retrieval/insertion point
    };

    /** \addtogroup superblock 
     * @{ 
     */

    /**
     *  \brief Definition of the superblock data type.
     */
    struct SOSuperBlock
    {
        /* Header */

        /** \brief magic number - file system identification number */
        uint16_t magic;

        /** \brief version number */
        uint16_t version;

        /** \brief volume name */
        char name[PARTITION_NAME_SIZE + 1];

        /** \brief mount status (1: properly unmounted; 0: otherwise) */
        uint8_t mntstat;

        /** \brief number of mounts since last file system check */
        uint8_t mntcnt;

        /** \brief total number of blocks in the device */
        uint32_t ntotal;


        /* Inodes' metadata */

        /** \brief physical number of the block where the free inode list table starts */
        uint32_t filt_start;

        /** \brief number of blocks that the free inode list table comprises */
        uint32_t filt_size;

        /** \brief first filled FILT position */
        uint32_t filt_head;

        /** \brief first empty FILT position */
        uint32_t filt_tail;

        /** \brief number of blocks that the inode table comprises */
        uint32_t it_size;

        /** \brief physical number of the block where the inode table starts */
        uint32_t it_start;

        /** \brief total number of inodes */
        uint32_t itotal;

        /** \brief number of free inodes */
        uint32_t ifree;


        /* Data blocks' metadata */

        /** \brief physical number of the block where the free block list table starts */
        uint32_t fblt_start;

        /** \brief number of blocks that the free block list table comprises */
        uint32_t fblt_size;

        /** \brief first filled FBLT position */
        uint32_t fblt_head;

        /** \brief first empty FBLT position */
        uint32_t fblt_tail;

        /** \brief physical number of the block where the data zone starts */
        uint32_t dz_start;

        /** \brief total number of blocks in data zone */
        uint32_t dz_total;

        /** \brief number of free blocks in data zone */
        uint32_t dz_free;



        /* caches of free inodes and free blocks */
        
        /** \brief retrieval cache of references to free inodes */
        SOInodeReferenceCache ircache;

        /** \brief insert cache of references to free inodes */
        SOInodeReferenceCache iicache;
        
        /** \brief retrieval cache of references to free blocks */
        SOBlockReferenceCache brcache;

        /** \brief insert cache of references to free blocks */
        SOBlockReferenceCache bicache;
    };

    /** @} */

};

#endif /*__SOFS18_SUPERBLOCK__ */
