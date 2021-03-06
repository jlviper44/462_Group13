#ifndef __ACCOUNTMANAGER__
#define __ACCOUNTMANAGER_

#include "Domain/AccountManager/AccountHandler.hpp"
#include "TechnicalServices/Persistence/PersistenceHandler.hpp"


namespace Domain::AccountManager
{


    class AccountManager : public Domain::AccountManager::AccountHandler
    {
        public:
        AccountManager();

        //operations
        std::vector<Account> getAllAccounts() override;
        std::vector<std::string> getAccountLogsByID(long long) override;
        bool resetPassword(long long userID) override;

        ~AccountManager() noexcept override;

        private:
        TechnicalServices::Persistence::PersistenceHandler & _persistentData;

    };
}

#endif