#ifndef __ACCOUNTHANDLER__
#define __ACCOUNTHANDLER__

#include <memory>

#include "Domain/AccountManager/Account.hpp"
#include "TechnicalServices/Persistence/PersistenceHandler.hpp"

namespace Domain::AccountManager
{

    //using TechnicalServices::Persistence::Account;


    class AccountHandler
    {
        public:
        
        //Manager Factory
        static std::unique_ptr<AccountHandler> createMgr();

        //Operations
        //virtual std::string getUserLogByID(std::long long userID) = 0;
        virtual std::vector<Account> getAllAccounts() = 0;
        virtual std::vector<std::string> getAccountLogsByID(long long) = 0;
        virtual bool resetPassword(long long userID) = 0;
        //Destructor
        virtual ~AccountHandler() noexcept = 0;
    };
}

#endif