/**
 *  \file 
 *  \brief Functions to manage file blocks
 *
 *  \author Artur Pereira - 2008-2009, 2016-2018
 *  \author Miguel Oliveira e Silva - 2009, 2017
 *  \author António Rui Borges - 2010-2015
 *
 *  \remarks In case an error occurs, every function throws an SOException
 */

#ifndef __SOFS18_FILEBLOCKS__
#define __SOFS18_FILEBLOCKS__

#include <inttypes.h>

namespace sofs18
{
    /* *************************************************** */
    /** \defgroup fileblocks fileblocks
     *  \ingroup ilayers
     *  \brief Functions to manage file blocks
     *  \remarks In case an error occurs, every function throws an SOException
     * @{
     */
    /* *************************************************** */

    /**
     * \brief Get the data block number of the given file block
     *
     *  \param ih inode handler
     *  \param fbn file block number
     *  \return the number of the corresponding block
     */
    uint32_t soGetFileBlock(int ih, uint32_t fbn);

    /* *************************************************** */

    /**
     * \brief Associate a data block to the given file block position
     *
     *  \param ih inode handler
     *  \param fbn file block number
     *  \return the number of the allocated block
     */
    uint32_t soAllocFileBlock(int ih, uint32_t fbn);

    /* *************************************************** */

    /**
     * \brief Free all file blocks from the given position on 
     *  \param ih inode handler
     *  \param ffbn first file block number
     */
    void soFreeFileBlocks(int ih, uint32_t ffbn);

    /* *************************************************** */

    /**
     *  \brief Read a file block.
     *
     *  Data is read from a specific data block which is supposed to belong 
     *  to an inode associated to a file (a regular
     *  file, a directory or a symbolic link). 
     *
     *  If the referred file block has not been allocated yet, 
     *  the returned data will consist of a byte stream filled with the
     *  character null (ascii code 0).
     *
     *  \param ih inode handler
     *  \param fbn file block number
     *  \param buf pointer to the buffer where data must be read into
     */
    void soReadFileBlock(int ih, uint32_t fbn, void *buf);

    /* *************************************************** */

    /**
     *  \brief Write a data block.
     *
     *  Data is written into a specific data block which is supposed
     *  to belong to an inode associated to a file (a regular
     *  file, a directory or a symbolic link). 
     *
     *  If the referred block has not been allocated yet,
     *  it will be allocated now so that the data can be stored as its
     *  contents.
     *
     *  \param ih inode handler
     *  \param fbn file block number
     *  \param buf pointer to the buffer containing data to be written
     */
    void soWriteFileBlock(int ih, uint32_t fbn, void *buf);

    /* *************************************************** */
    /** @} close group fileblocks */
    /* *************************************************** */

};

#endif             /* __SOFS18_FILEBLOCKS__ */
