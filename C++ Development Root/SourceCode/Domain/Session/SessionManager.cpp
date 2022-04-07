#include "SessionManager.hpp"
#include "Domain/AccountManager/Account.hpp"
#include "Domain/Session/Session.hpp"
#include "TechnicalServices/Persistence/PersistenceHandler.hpp"

namespace Domain::SessionManager
{
	SessionManager::SessionManager()
	: _persistentData( TechnicalServices::Persistence::PersistenceHandler::instance() )
	{
		std::cout << "Account Manager says hello";
	}

	SessionManager::~SessionManager(){}

	long long SessionManager::authenticateUser(std::string name, std::string password)
	{
		static std::vector<Account> allAccounts = _persistentData.getAllAccounts();

		std::string accountName = "";
		std::string accountPassword = "";
		for(Account i : allAccounts)
		{
			if(i._name == name)
			{
				accountName = i._name;
				accountPassword = i.getPassword();
			}
		}
		if(accountName == "")
		{
			return 0;
		}

		if(accountName == name && accountPassword == password)
		{
			_currentSession = Session();
			return _currentSession._id;
		}
		return 0;
	}

	bool SessionManager::terminateUserSession(long long sessionID)
	{
		if(sessionID == _currentSession._id)
		{
			return true;
		}
		return false;
	}
}
