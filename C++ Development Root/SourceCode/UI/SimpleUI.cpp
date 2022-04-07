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
#include "Domain/ListingManager/ListingHandler.hpp"

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

		runScenarioFive();
		

		Account newAccount = Account("Justin", 0000, "today", "Lee");
		_persistentData.accounts.push_back(newAccount);
		std::cout << _persistentData.accounts.back().getPassword() << std::endl;
		
	}
	void SimpleUI::runScenarioFive()
	{

		std::vector<Account> allAccounts = _accountMgr.getAllAccounts();
		//std::cout << allAccounts.size();
		for(unsigned i=0; i < allAccounts.size(); i++){
			std::cout << allAccounts[i]._userID << " " << allAccounts[i]._name << std::endl;
		}

		std::vector<std::string> userLogs = _accountMgr.getAccountLogsByID(001);
		for(unsigned i=0; i < userLogs.size(); i++){
			std::cout << userLogs[i] << std::endl;
		}

		if(_accountMgr.resetPassword(001))
		{
			std::cout << "Password has been reset" << std::endl;
		}
	}
}