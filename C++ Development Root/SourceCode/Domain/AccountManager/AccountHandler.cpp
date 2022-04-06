#include <memory>

#include "Domain/AccountManager/AccountHandler.hpp"
#include "Domain/AccountManager/AccountManager.hpp"


namespace Domain::AccountManager
{
    std::unique_ptr<AccountHandler> AccountHandler::createMgr()
    {
        return std::make_unique<Domain::AccountManager::AccountManager>();
    }
}