/**
 *  \file 
 *  \brief Functions to manage directory entries
 *
 *  \author Artur Pereira 2008-2009, 2016-2018
 *  \author Miguel Oliveira e Silva 2009, 2017
 *  \author António Rui Borges - 2012-2015
 *
 *  \remarks In case an error occurs, every function throws an SOException
 */

#ifndef __SOFS18_DIRENTRIES__
#define __SOFS18_DIRENTRIES__

#include <inttypes.h>

namespace sofs18
{

    /* ************************************************** */
    /** \defgroup direntries direntries 
     *  \ingroup ilayers
     *  \brief Functions to manage directory entries
     *  \remarks In case an error occurs, every function throws an SOException
     * @{ 
     */
    /* ************************************************** */

    /**
     *  \brief Get the inode associated to a given path
     *
     *  The directory hierarchy of the file system is traversed to find
     *  an entry whose name is the rightmost component of
     *  <tt>path</tt>.
     *
     *  \param [in] path the path to be traversed
     *  
     *  \remarks
     *  
     *  \li \c path must be absolute and each of its components,
     *  with the exception of the rightmost one,
     *  must be a directory name or symbolic link name to a path.
     *
     * \li The process that calls the operation must have traverse
     *  (x) permission on all the components of the path with
     *  exception of the rightmost one.
     *  \li when calling a function of any layer, use the main version (sofs18::«func»(...)).
     *
     *  \return the corresponding inode number
     */
    uint32_t soTraversePath(char *path);

    /* ************************************************** */

    /**
     *  \brief Get the inode associated to a given name
     *
     *  The directory contents, seen as an array of directory entries,
     *  is parsed to find an entry whose name is the given one.
     *
     *  \param [in] pih inode handler of the parent directory
     *  \param [in] name the name of the entry to be searched for
     *
     * \remarks
     *
     * \li Error \c EINVAL must be thrown if \c name is not a <em>base name</em>,
     *     that is, if it contains the character '/'.
     * \li Error \c ENODIR must be thrown if \c pih does not represent a directory
     *  \li when calling a function of any layer, use the main version (sofs18::«func»(...)).
     *
     *  \return the corresponding inode number (even if it is \c NullReference)
     */
    uint32_t soGetDirEntry(int pih, const char *name);

    /* ************************************************** */

    /**
     *  \brief Add a new entry to the parent directory.
     *
     *  A direntry is added connecting the parent inode to the child inode.
     *
     *  \param [in] pih inode handler of the parent inode
     *  \param [in] name the name of the entry to be created
     *  \param [in] cin inode number of the entry to be created
     *  
     *  \remarks 
     *  
     *  \li Assume \c pih is a valid inode handler of a directory where the user has write access
     *  \li Error \c EEXIST should be thrown if \c name already exists
     *  \li Assume \c cin is a valid inode number
     *  \li The \c lnkcnt of the child inode is not incremented by this function.
     *  \li when calling a function of any layer, use the main version (sofs18::«func»(...)).
     */
    void soAddDirEntry(int pih, const char *name, uint32_t cin);

    /* ************************************************** */

    /**
     *  \brief Delete an entry from a parent directory.
     *
     *  A direntry associated from the given directory is deleted.
     *
     *  \param [in] pih inode handler of the parent inode
     *  \param [in] name name of the entry
     *
     *  \remarks 
     *  
     *  \li Assume \c pih is a valid inode handler of a directory where the user has write access
     *  \li Error \c ENOENT should be thrown if \c name does not exist
     *  \li The \c lnkcnt of the child inode is not decremented by this function.
     *  \li when calling a function of any layer, use the main version (sofs18::«func»(...)).
     *
     *  \return the inode number of the deleted entry
     */
    uint32_t soDeleteDirEntry(int pih, const char *name);

    /* ************************************************** */

    /**
     *  \brief Rename an entry of a directory.
     *
     *  A direntry associated from the given directory is renamed.
     *
     *  \param [in] pih inode handler of the parent inode
     *  \param [in] name current name of the entry
     *  \param [in] newName new name for the entry
     *
     *  \remarks 
     *  
     *  \li Assume \c pih is a valid inode handler of a directory where the user has write access
     *  \li Error \c ENOENT should be thrown if \c name does not exist
     *  \li when calling a function of any layer, use the main version (sofs18::«func»(...)).
     */
    void soRenameDirEntry(int pih, const char *name, const char *newName);

    /* ************************************************** */

    /**
     *  \brief Check directory emptiness
     *
     *  The directory is traversed to verified if the only existing entries are "." and "..".
     *
     *  \param [in] ih handler of the inode to be checked
     *  
     *  \remarks 
     *  
     *  \li Assume \c ih is a valid inode handler of a directory
     *  \li when calling a function of any layer, use the main version (sofs18::«func»(...)).
     */
    bool soCheckDirEmpty(int ih);

    /* ************************************************** */
    /** @} close group direntries */
    /* ************************************************** */

};

#endif             /* __SOFS18_DIRENTRIES__ */
