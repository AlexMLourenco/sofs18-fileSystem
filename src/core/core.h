/**
 *  \file
 *  \brief Some global constants and aggregation of core header files
 *
 *  \author Artur Pereira - 2016-2018
 */

#ifndef __SOFS18_CORE__
#define __SOFS18_CORE__

#include "exception.h"
#include "probing.h"
#include "bin_selection.h"
#include "superblock.h"
#include "inode.h"
#include "direntry.h"
#include "blockviews.h"

#include <inttypes.h>

/** \defgroup core core
 *  \brief Core functions and constants
 */

/** \defgroup constants constants 
 * \brief Core constants
 */

/** @{ */

/** \brief block size (in bytes) */
#define BlockSize 512U 

/** \brief number of inodes per block */
#define InodesPerBlock (BlockSize / sizeof(SOInode))

/** \brief number of references per block */
#define ReferencesPerBlock (BlockSize / sizeof (uint32_t))

/** \brief number of direntries per block */
#define DirentriesPerBlock     (BlockSize / sizeof(SODirEntry))

/** \brief null reference to an inode or to a data block */
#define NullReference 0xFFFFFFFF

/** @} */

#endif				/* __SOFS18_CORE__ */

