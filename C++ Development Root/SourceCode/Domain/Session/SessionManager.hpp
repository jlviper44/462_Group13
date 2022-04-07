#ifndef _SESSIONMANAGER_HPP_
#define _SESSIONMANAGER_HPP_

#include "Domain/Session/SessionHandler.hpp"
#include "Domain/Session/Session.hpp"
#include "Domain/AccountManager/Account.hpp"
#include "TechnicalServices/Persistence/PersistenceHandler.hpp"

namespace Domain::SessionManager
{
	class SessionManager: public Domain::SessionManager::SessionHandler
	{
		private:
			TechnicalServices::Persistence::PersistenceHandler & _persistentData;
			Session _currentSession;

		public:
			SessionManager();
			long long authenticateUser(std::string name, std::string password);
			// bool authenticateUser(std::string inputtedUsername, std::string inputtedPassword, std::string username, std::string password);
			bool terminateUserSession(long long sessionID);
			~SessionManager() noexcept override;
	};
}
#endif