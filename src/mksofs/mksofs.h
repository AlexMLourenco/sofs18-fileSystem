/**
 *  \file
 *  \brief The \b sofs18 formatting functions.
 *
 *  \author Artur Pereira - 2007-2009, 2016-2018
 *  \author Miguel Oliveira e Silva - 2009, 2017
 *  \author António Rui Borges - 2010-2015
 */

#ifndef __SOFS18_MKSOFS__
#define __SOFS18_MKSOFS__

#include <inttypes.h>

namespace sofs18
{

    /**
     * \defgroup mksofs mksofs
     * \brief Auxiliary formatting functions
     * @{ 
     * */

    /* ******************************************************************* */

    /**
     * \brief computes the structural division of the disk
     * \details The following rules should be observed:
     *     \li if \c itotal is zero, the value <code>ntotal / 8</code>
     *          should be used as a start value,
     *          where / stands for the integer division;
     *     \li \c itotal must be always lower than or equal to <code>ntotal / 4</code>;
     *     \li \c itotal must be rounded up to be multiple of \c InodesPerBlock;
     *     \li \c rdsize represents the number of blocks used by the root dir for formatting;
     *          it is normally \c 1, but can be \c 2 if a block can not be assigned to any other 
     *          purpose.
     *          The procedure should be the following: if a remaining block can not be assigned to
     *          the data zone because the last block of the FBLT is already full, 
     *          it should be assigned to the inode table, tentatively;
     *          but, if the FILT is also full, the remaining block should be assigned to the 
     *          root directory.
     *          Note that, when the number of blocks of the root directory is 2,
     *          the number of blocks in the data zone exceeds in one unity the number of
     *          references in the FBLT.
     * \param [in] ntotal Total number of blocks of the disk
     * \param [in, out] itotal Total number of inodes
     * \param [out] btotal Total number of data blocks
     * \param [out] rdsize Initial number of blocks of the root directory
     */
    void computeStructure(uint32_t ntotal, uint32_t & itotal, uint32_t & btotal, uint32_t & rdsize);


    /**
     * \brief Fill in the fields of the superblock.
     * \details The magic number should be put at \c 0xFFFF.
     *      All caches should be put empty.
     * \param [in] name volume name
     * \param [in] ntotal the total number of blocks in the device
     * \param [in] itotal the total number of inodes
     * \param [in] rdsize initial number of blocks for the root directory
     */
    void fillInSuperBlock(const char *name, uint32_t ntotal, uint32_t itotal, uint32_t rdsize);


    /**
     * \brief Fill in the blocks of the free inode list table.
     * \details The list should represent the sequence <code>1..itotal-1</code>
     *      and the table should be filled with the sequence from the beginning.
     *      Non used cells should be filled with \c NullReference.
     * \param [in] first_block physical number of the first block used by the table
     * \param [in] itotal the total number of inodes
         * \return The number of blocks occupied by the table
     */
    uint32_t fillInFreeInodeListTable(uint32_t first_block, uint32_t itotal);
    

    /**
     * \brief Fill in the blocks of the inode table.
     * \details The inode 0 must be filled assuming it is used by the root directory.
     *      The other inodes are free.
     * \param [in] first_block physical number of the first block used by the table
     * \param [in] itotal the total number of inodes
     * \param [in] rdsize initial number of blocks for the root directory
     * \return The number of blocks occupied by the table
     */
    uint32_t fillInInodeTable(uint32_t first_block, uint32_t itotal, uint32_t rdsize);


    /**
     * \brief Fill in the blocks of the free block list table.
     * \details The list should represent the sequence <code>rdsize..btotal-1</code>
     *      and the table should be filled with the sequence from the beginning.
     *      Non used cells should be filled with \c NullReference.
     * \param [in] first_block physical number of the first block used by the table
     * \param [in] btotal the total number of inodes
     * \param [in] rdsize Initial number of blocks of the root directory
     * \return The number of blocks occupied by the table
     */
    uint32_t fillInFreeBlockListTable(uint32_t first_block, uint32_t btotal, uint32_t rdsize);
    

    /** 
     * \brief Fill in the root directory
     * \details The root directory occupies one or two contiguous blocks,
     *      with the first two slots filled in with
     *      \c "." and \c ".." directory entries.
     *      The other slots must be cleaned: field \c name filled with zeros and field \c inode
     *      filled with \c NullReference.
     * \param [in] fist_block number of the block where the root cluster starts.
     * \param [in] rdsize initial number of blocks for the root directory
     * \return The number of blocks occupied by the root directory
     */
    uint32_t fillInRootDir(uint32_t fist_block, uint32_t rdsize);


    /**
     * \brief Fill with zeros the given set of blocks.
     * \param[in] first_block number of the first block to be reseted
     * \param[in] cnt number of blocks to be reseted
     */
    void resetBlocks(uint32_t first_block, uint32_t cnt);

    /* ***************************************** */

    /* ******************************************************************* */
    /** @} close group mksofs */
    /* ******************************************************************* */
};

#endif   /* __SOFS18_MKSOFS__ */
