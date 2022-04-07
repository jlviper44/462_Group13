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
	_accountMgrPtr( Domain::AccountManager::AccountHandler::createMgr() ),
	_listingMgrPtr( Domain::ListingManager::ListingHandler::createMgr())
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

		
		
		std::string jobName;
     	std::string jobType;
	 	int jobID = 0;
		_listingMgr.showFormatting();
		std::cin >> jobName >> jobType;
	
		Listing currlisting = _listingMgr.writeListingInfo(jobName, jobType);
		currlisting.isPosted = _listingMgr.confirmSavedListing(currlisting);
		if (currlisting.isPosted == true){
			_listingMgr.postListing(currlisting);
			_persistentData.listings.push_back(currlisting);
			_listingMgr.confirmPostedListing(currlisting, _persistentData.listings);
		}

	
	}
}