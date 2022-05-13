#ifndef __SESSIONHANDLER__
#define __SESSIONHANDLER__

#include <memory>
#include "Domain/AccountManager/Account.hpp"

namespace Domain::SessionManager
{
    class SessionHandler
    {
        public:
        
        //Manager Factory
        static std::unique_ptr<SessionHandler> createMgr();

        //Operations
        virtual long long authenticateUser(std::string name, std::string password) = 0;
        virtual bool terminateUserSession(long long sessionID) = 0;
        
        //Destructor
        virtual ~SessionHandler() noexcept = 0;
    };
}

#endif