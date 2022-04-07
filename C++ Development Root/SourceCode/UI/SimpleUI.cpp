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
#include "Domain/ResumeManager/ResumeHandler.hpp"


namespace UI
{
	SimpleUI::SimpleUI()
	: _loggerPtr( TechnicalServices::Logging::LoggerHandler::create() ),
	_persistentData( TechnicalServices::Persistence::PersistenceHandler::instance() ),
	_accountMgrPtr( Domain::AccountManager::AccountHandler::createMgr() ),
	_listingMgrPtr( Domain::ListingManager::ListingHandler::createMgr()),
	_resumeMgrPtr( Domain::ResumeManager::ResumeHandler::createMgr() )
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

		
		//Satish's code
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
		//kevin's code
		Resume currentResume = _resumeMgr.buildResume();
		currentResume._contactInfo = _resumeMgr.createContactInfo();
		currentResume._eduInfo = _resumeMgr.createEduInfo();
		currentResume._objInfo = _resumeMgr.createObjInfo();
		currentResume._skillInfo = _resumeMgr.createSkillInfo();
		currentResume._workInfo = _resumeMgr.createWorkInfo();
		std::cout << _resumeMgr.resumeToString(currentResume);
	}
}