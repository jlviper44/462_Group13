#include "Domain/AccountManager/AccountManager.hpp"

#include <iostream>

namespace Domain::AccountManager
{
    AccountManager::AccountManager() 
    : _persistentData( TechnicalServices::Persistence::PersistenceHandler::instance() )
    {
        std::cout << "Account Manager says hello";
    }
    AccountManager::~AccountManager(){}

    std::vector<Account> getAllAccounts(){
        
    }
}