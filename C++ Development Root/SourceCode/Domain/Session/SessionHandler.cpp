#include <memory>
#include <iostream>
#include "Domain/Session/SessionHandler.hpp"
#include "Domain/Session/SessionManager.hpp"


namespace Domain::SessionManager
{
    std::unique_ptr<SessionHandler> SessionHandler::createMgr()
    {
        std::cout << "SessionHandler running...";
        return std::make_unique<SessionManager>();
    }
    SessionHandler::~SessionHandler(){}
}