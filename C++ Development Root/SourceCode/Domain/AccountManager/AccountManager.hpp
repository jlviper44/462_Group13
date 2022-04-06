#ifndef __ACCOUNTMANAGER__
#define __ACCOUNTMANAGER_

#include "Domain/AccountManager/AccountHandler.hpp"

namespace Domain::AccountManager
{
    class AccountManager: public Domain::AccountManager::AccountHandler
    {
        public:
        AccountManager();



        ~AccountManager() noexcept override;
    };
}

#endif