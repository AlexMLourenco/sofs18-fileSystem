/**
 * \file 
 * \brief The \b sofs18 exception support
 * \author Artur Pereira - 2016-2018
 */
#ifndef __SOFS18_EXCEPTION__
#define __SOFS18_EXCEPTION__

#include <exception>

namespace sofs18
{

    /**
     * \defgroup exception exception
     * \brief \c sofs18 exception data type
     * \ingroup core
     * @{
     */

    /**
     * \brief The \b sofs18 exception class
     */
    class SOException : public std::exception
    {
    public:
        int en;             ///< (system) error number
        const char *func;   ///< name of function that has thrown the exception
        char msg[100];      ///< buffer to store the exception message
        
        /**
         * \brief the constructor
         * \param _en (system) error number 
         * \param _func name of function throwing the exception
         */
        SOException(int _en, const char *_func);

        /**
         * \brief default exception message
         * \return pointer to exception message
         */
        const char *what() const throw();
    };

    /** @} */

};

#endif                          /* __SOFS18_EXCEPTION__ */
