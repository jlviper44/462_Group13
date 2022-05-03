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

  //     else if( response == '2' )
  //     {
		// 		runScenarioTwo();
  //     }

      else if( response == '3' )
      {
				runScenarioThree();
      }
  //     else if( response == '4' )
  //     {
		// 		break;
  //     }
  //     else
  //     {
  //       std::cout << response << " is not available!\n";
  //     }

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

			long long listingId = _listingMgr.createListing();
			std::cout << "Listing has been created with id: " << listingId << std::endl;
			
			std::string jobName;
	    	std::string jobType;

	    	std::cout << "Please enter Job Listing Information as follows\n";
			std::cout << "Job Name and Job Type\n";
			std::cout << "Please enter Job Name (space) Job Type:\n";
	    	std::cin >> jobName >> jobType;

	    	bool isListingInfo = _listingMgr.writeListingInfo(jobName, jobType, listingId);
	    	if(isListingInfo)
	    	{
	    		std::cout << "Listing: " << listingId << " has the job name of: " << jobName <<
	    		" and job type of: " << jobType << std::endl;
	    	}
	    	else
	    	{
	    		std::cout << "Could not write to listing: " << listingId << std::endl;
	    	}

	    	bool isListingSaved = _listingMgr.confirmSavedListing(listingId);

	    	if(isListingSaved)
	    	{
	    		std::cout << "Listing: " << listingId << " has been saved!" << std::endl;
	    	}
	    	else
	    	{
	    		std::cout << "Could not find listing: " << listingId << std::endl;
	    	}

	    	bool isListingFound = _listingMgr.postListing(listingId);

	    	if(isListingFound)
	    	{
	    		std::cout << "Listing: " << listingId << " has been posted!" << std::endl;
	    	}
	    	else
	    	{
	    		std::cout << "Could not post listing: " << listingId << std::endl;
	    	}

	    	bool isListingPosted = _listingMgr.isListingPosted(listingId);
		 	
		 	if(isListingFound)
	    	{
	    		std::cout << "Listing: " << listingId << " is currently being posted!" << std::endl;
	    	}
	    	else
	    	{
	    		std::cout << "Listing: " << listingId << " is not being posted!" << std::endl;
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

			long long resumeId = _resumeMgr.buildResume();

			std::string contactInfo;
			std::cout << "Enter your contact information: ";
			std::cin.ignore();
			std::getline (std::cin, contactInfo);
			bool isContactCreated = _resumeMgr.createContactInfo(resumeId, contactInfo);

			
			std::string objStatement;
			std::cout << "Enter your objective statement: ";
			std::getline (std::cin, objStatement);
			bool isObjCreated = _resumeMgr.createObjInfo(resumeId, objStatement);

			std::string skills;
			std::cout << "List your skills: ";
			std::getline (std::cin, skills);
			bool isSkillCreated = _resumeMgr.createSkillInfo(resumeId, skills);

			std::string prevEducation;
			std::cout << "List your previous education: ";
			std::getline (std::cin, prevEducation);
			bool isEduCreated = _resumeMgr.createEduInfo(resumeId, prevEducation);

			std::string prevWorkExp;
			std::cout << "List your previous work experience: ";
			std::getline (std::cin, prevWorkExp);
			bool isWorkCreated = _resumeMgr.createWorkInfo(resumeId, prevWorkExp);


			std::cout << _resumeMgr.resumeToString(resumeId);

			std::cout << std::endl;
			_logger << "terminateUserSession(sessionID)";
			std::cout << std::endl;

			bool isSessionTerminated = _sessionMgr.terminateUserSession(sessionID);

			std::cout << std::endl;
			_logger << "User Session terminated!";
			std::cout << std::endl;
		}
	}
}