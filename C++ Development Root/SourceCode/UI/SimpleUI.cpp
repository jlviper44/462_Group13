#include "UI/SimpleUI.hpp"

#include <any>         // any_cast()
#include <iomanip>     // setw()
#include <iostream>    // streamsize
#include <limits>      // numeric_limits
#include <memory>      // unique_ptr, make_unique<>()
#include <string>      // string, getline()
#include <vector>

#include "Domain/Session/SessionHandler.hpp"

#include "TechnicalServices/Logging/LoggerHandler.hpp"
#include "TechnicalServices/Persistence/PersistenceHandler.hpp"
#include "Domain/AccountManager/AccountHandler.hpp"

namespace UI
{
	SimpleUI::SimpleUI()
	: _loggerPtr( TechnicalServices::Logging::LoggerHandler::create() ),
	_persistentData( TechnicalServices::Persistence::PersistenceHandler::instance() ),
	_accountMgrPtr( Domain::AccountManager::AccountHandler::createMgr() )
	{
		_logger << "Simple UI being used and has been successfully initialized";
	}
	
	SimpleUI::~SimpleUI() noexcept
	{
		_logger << "Simple UI shutdown successfully";
	}

	void SimpleUI::launch()
	{	
		// std::vector<Account> accounts = _persistentData.getAllAccounts();
		// std::cout << accounts.back().getUserID();
		
		Account newAccount = Account("Justin", 0000, "today", "Lee");
		_persistentData.accounts.push_back(newAccount);
		std::cout << _persistentData.accounts.back().getPassword() << std::endl;
		
	}
}