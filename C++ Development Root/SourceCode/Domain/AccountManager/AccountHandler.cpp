#include <memory>
#include <iostream>
#include "Domain/AccountManager/AccountHandler.hpp"
#include "Domain/AccountManager/AccountManager.hpp"


namespace Domain::AccountManager
{
    std::unique_ptr<AccountHandler> AccountHandler::createMgr()
    {
        std::cout << "AccountHandler running...";
        return std::make_unique<AccountManager>();
    }
    AccountHandler::~AccountHandler(){}
}