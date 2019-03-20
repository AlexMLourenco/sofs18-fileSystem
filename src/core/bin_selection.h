/**
 *  \file 
 *  \brief The bin IDs selection toolkit.
 *
 *  This toolkit provides a simple way to select what binary version of
 *  the functions to use in a given moment.
 *  The selection can be done in run time.
 *  The IDs of the functions are the same used by the probing system.
 *
 *  \author Artur Pereira - 2018
 *
 *  \remarks In case an error occurs, every function throws an error code (an int)
 */

#ifndef __SOFS18_BIN_SELECTION__
#define __SOFS18_BIN_SELECTION__

#include <inttypes.h>

namespace sofs18
{
    /** 
     * \defgroup bin_selection bin ids selection
     *  \brief The bin IDs selection toolkit.
     *  \ingroup core
     *  \details This toolkit allows to select the binary functions to be used
     **/

    /** @{ */

    /* *************************************** */

    /**
     *  \brief Set bin IDs.
     *  \details reset current configuration and set given range
     *    as the bin IDs to activate.
     *  \param lower left margin of the range to be activated
     *  \param upper right margin of the range to be activated
     */
    void soBinSetIDs(uint32_t lower, uint32_t upper);

    /* *************************************** */

    /**
     *  \brief Add bin IDs to the current configuration.
     *  \param lower left margin of the range to be activated
     *  \param upper right margin of the range to be activated
     */
    void soBinAddIDs(uint32_t lower, uint32_t upper);

    /* *************************************** */

    /**
     *  \brief Remove bin IDs from the current configuration.
     *  \param lower left margin of the range to be deactivated
     *  \param upper right margin of the range to be deactivated
     */
    void soBinRemoveIDs(uint32_t lower, uint32_t upper);

    /* *************************************** */

    /**
     *  \brief Check if given ID is activated.
     *  \details IDs covered by the current configuration represent binary functions 
     *    to be used.
     *  \param id ID of the function to be checked
     */
    bool soBinSelected(uint32_t id);

    /* *************************************** */

    /** @} */

};

#endif				/* __SOFS18_BIN_SELECTION__ */
