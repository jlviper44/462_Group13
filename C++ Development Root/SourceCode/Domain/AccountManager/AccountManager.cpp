#include "Domain/AccountManager/AccountManager.hpp"
#include "TechnicalServices/Persistence/PersistenceHandler.hpp"
#include <iostream>

namespace Domain::AccountManager
{
    AccountManager::AccountManager() 
    : _persistentData( TechnicalServices::Persistence::PersistenceHandler::instance() )
    {
    }

    AccountManager::~AccountManager(){}

    // std::vector<TechnicalServices::Persistence::Account> getAllAccounts(){

    //     std::vector<TechnicalServices::Persistence::Account> acc = {{"", 0, "", ""}};
    //     return acc;
    // }
    std::vector<Account> AccountManager::getAllAccounts(){

        //std::vector<TechnicalServices::Persistence::Account> acc = {{"", 0, "", ""}};
        static std::vector<Account> allAccounts = _persistentData.getAllAccounts();

        return allAccounts;
    }

    std::vector<std::string> AccountManager::getAccountLogsByID(long long logUserID){
        std::vector<std::vector<std::string>> userLogObjs = _persistentData.getUserLogs();
        std::vector<std::string> userLogs;
        for(unsigned i=0; i < userLogObjs.size(); i++){
            if (logUserID == std::stoll(userLogObjs[i][0])){
                userLogs.push_back(userLogObjs[i][1]);
            }
        }
        return userLogs;
    }
    bool AccountManager::resetPassword(long long userID)
    {
       bool doesReset = _persistentData.resetPassword(userID);
       return doesReset;
    }
}