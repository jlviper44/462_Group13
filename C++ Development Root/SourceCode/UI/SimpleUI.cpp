  #include "UI/SimpleUI.hpp"

#include <any>         // any_cast()
#include <iomanip>     // setw()
#include <iostream>    // streamsize
#include <limits>      // numeric_limits
#include <memory>      // unique_ptr, make_unique<>()
#include <string>      // string, getline()
#include <vector>



#include "TechnicalServices/Logging/LoggerHandler.hpp"
#include "TechnicalServices/Persistence/PersistenceHandler.hpp"
#include "Domain/Session/SessionManager.hpp"
#include "Domain/AccountManager/AccountHandler.hpp"
#include "Domain/ListingManager/ListingHandler.hpp"
#include "Domain/ResumeManager/ResumeHandler.hpp"


namespace UI
{
	SimpleUI::SimpleUI()
	: _loggerPtr( TechnicalServices::Logging::LoggerHandler::create() ),
	_persistentData( TechnicalServices::Persistence::PersistenceHandler::instance() ),

	_sessionMgrPtr( Domain::SessionManager::SessionHandler::createMgr() ),
	_accountMgrPtr( Domain::AccountManager::AccountHandler::createMgr() ),
	_listingMgrPtr( Domain::ListingManager::ListingHandler::createMgr()),
	_resumeMgrPtr(  Domain::ResumeManager::ResumeHandler::createMgr() )
	{
		_logger << "Simple UI being used and has been successfully initialized";
	}
	
	SimpleUI::~SimpleUI() noexcept
	{
		_logger << "Simple UI shutdown successfully";
	}

	void SimpleUI::launch()
	{	
		char response;
		do
		{
      std::cout << "Available tests:\n"
                << "1: Post Job Listing\n"
                << "2: Manage and Monitor Logs\n"
                << "3: Build Resume\n"
                << "4: Quit\n"
                << "Enter the ssd number you would like to test: ";

      
      std::cin >> response;

      if( response == '1' )
      {
				runScenarioOne();
      }

      else if( response == '2' )
      {
				runScenarioTwo();
      }

      else if( response == '3' )
      {
				runScenarioThree();
      }
      else if( response == '4' )
      {
				break;
      }
      else
      {
        std::cout << response << " is not available!\n";
      }

    } while (response != '4');
	}
	void SimpleUI::runScenarioOne()
	{

		std::string name;
		std::string password;
		std::cout << "Enter your name: ";
		std::cin >> name;
		std::cout << "Enter your password: ";
		std::cin >> password;
		long long sessionID = _sessionMgr.authenticateUser(name, password);

		if(sessionID != 0)
		{
			std::cout << std::endl;
			_logger << "User Authenticated with sessionID: " + std::to_string(sessionID);
			std::cout << std::endl;

			std::string jobName;
	    std::string jobType;
		 	int jobID = 0;
			_listingMgr.showFormatting();


			std::cin >> jobName >> jobType;
			
			Listing currlisting = _listingMgr.writeListingInfo(jobName, jobType);

			std::cout << std::endl;
			_logger << "Listing currlisting created with jobName: " + jobName + " jobType: " + jobType;


			currlisting.isPosted = _listingMgr.confirmSavedListing(currlisting);


			if (currlisting.isPosted == true){
				_listingMgr.postListing(currlisting);

				_persistentData.listings.push_back(currlisting);
				_listingMgr.confirmPostedListing(currlisting, _persistentData.listings);
			}

			std::cout << std::endl;
			_logger << "terminateUserSession(sessionID)";
			std::cout << std::endl;

			bool isSessionTerminated = _sessionMgr.terminateUserSession(sessionID);

			std::cout << std::endl;
			_logger << "User Session terminated!";
			std::cout << std::endl;
		}
	}
	
	void SimpleUI::runScenarioTwo()
	{

		std::string name;
		std::string password;
		std::cout << "Enter your name: ";
		std::cin >> name;
		std::cout << "Enter your password: ";
		std::cin >> password;
		long long sessionID = _sessionMgr.authenticateUser(name, password);

		
		if(sessionID != 0)
			{
				std::cout << std::endl;
				_logger << "User Authenticated with sessionID: " + std::to_string(sessionID);
				std::cout << std::endl;

				std::cout << "Manage Accounts:\nY|N\n";
				char response;
				std::cin >> response;
				if(response == 'Y' || response == 'y')
				{
					std::vector<Account> allAccounts = _accountMgr.getAllAccounts();
					for(unsigned i=0; i < allAccounts.size(); i++){
						std::cout << allAccounts[i]._userID << " " << allAccounts[i]._name << std::endl;
					}
					std::cout << "Enter the number of the account to view account logs:\n";
					std::string userID;
					std::cin >> userID;
					long long userIDLL = std::stoll(userID);
					std::vector<std::string> userLogs = _accountMgr.getAccountLogsByID(userIDLL);
					for(unsigned i=0; i < userLogs.size(); i++){
						std::cout << userLogs[i] << std::endl;
					}
					std::cout << "Choose an action to take:\n"
								<< "1. Reset Account Password\n"
								<< "2. Lockdown Account\n"
								<< "3. Delete Account\n";
					char adminChoice;
					std::cin >> adminChoice;
					if(adminChoice == '1')
					{
						if(_accountMgr.resetPassword(userIDLL))
						{
							std::cout << "Password has been reset" << std::endl;
						}
					}
				} 
			std::cout << std::endl;
			_logger << "terminateUserSession(sessionID)";
			std::cout << std::endl;

			bool isSessionTerminated = _sessionMgr.terminateUserSession(sessionID);

			std::cout << std::endl;
			_logger << "User Session terminated!";
			std::cout << std::endl;
		}
	}
	void SimpleUI::runScenarioThree()
	{
		std::string name;
		std::string password;
		std::cout << "Enter your name: ";
		std::cin >> name;
		std::cout << "Enter your password: ";
		std::cin >> password;
		long long sessionID = _sessionMgr.authenticateUser(name, password);
		if(sessionID != 0)
		{
			std::cout << std::endl;
			_logger << "User Authenticated with sessionID: " + std::to_string(sessionID);
			std::cout << std::endl;
			
			Resume currentResume = _resumeMgr.buildResume();

			std::string contactInfo;
      std::cout << "Enter your contact information: ";
      std::cin.ignore();
      std::getline (std::cin, contactInfo);
      currentResume = _resumeMgr.createContactInfo(currentResume, contactInfo);

      std::string objStatement;
      std::cout << "Enter your objective statement: ";
      std::getline (std::cin, objStatement);
      currentResume = _resumeMgr.createObjInfo(currentResume, objStatement);

      std::string skills;
      std::cout << "List your skills: ";
      std::getline (std::cin, skills);
      currentResume = _resumeMgr.createSkillInfo(currentResume, skills);

      std::string prevEducation;
      std::cout << "List your previous education: ";
      std::getline (std::cin, prevEducation);
      currentResume = _resumeMgr.createEduInfo(currentResume, prevEducation);

      std::string prevWorkExp;
      std::cout << "List your previous work experience: ";
      std::getline (std::cin, prevWorkExp);
      currentResume = _resumeMgr.createWorkInfo(currentResume, prevWorkExp);


			std::cout << _resumeMgr.resumeToString(currentResume);

			std::cout << std::endl;
			_logger << "terminateUserSession(sessionID)";
			std::cout << std::endl;

			bool isSessionTerminated = _sessionMgr.terminateUserSession(sessionID);

			std::cout << std::endl;
			_logger << "User Session terminated!";
			std::cout << std::endl;
		}
	}
}//