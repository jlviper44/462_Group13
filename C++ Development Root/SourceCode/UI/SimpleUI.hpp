#pragma once

#include <memory>    // std::unique_ptr

#include "TechnicalServices/Logging/LoggerHandler.hpp"
#include "TechnicalServices/Persistence/PersistenceHandler.hpp"
#include "UI/UserInterfaceHandler.hpp"

#include "Domain/Session/SessionManager.hpp"
#include "Domain/AccountManager/AccountHandler.hpp"
#include "Domain/ListingManager/ListingHandler.hpp"
#include "Domain/ResumeManager/ResumeHandler.hpp"


namespace UI
{
  /*****************************************************************************
  ** Simple UI definition
  **   Simple UI is a console application meant only as a driver to the Domain Layer
  **   application. This UI will someday be replaced by a more sophisticated, user
  **   friendly implementation
  ******************************************************************************/
  class SimpleUI : public UI::UserInterfaceHandler
  {
    public:
      // Constructors
      SimpleUI();


      // Operations
      void launch() override;

      void runScenarioOne();
      // void runScenarioTwo();
      void runScenarioThree();
      
      // Destructor
      ~SimpleUI() noexcept override;


    private:
      // These smart pointers hold pointers to lower architectural layer's interfaces
      std::unique_ptr<TechnicalServices::Logging::LoggerHandler>            _loggerPtr;
      TechnicalServices::Persistence::PersistenceHandler                  & _persistentData;
      // convenience reference object enabling standard insertion syntax
      // This line must be physically after the definition of _loggerPtr
      TechnicalServices::Logging::LoggerHandler                            & _logger = *_loggerPtr;

      std::unique_ptr<Domain::SessionManager::SessionHandler> _sessionMgrPtr;
      Domain::SessionManager::SessionHandler & _sessionMgr = *_sessionMgrPtr;

      std::unique_ptr<Domain::AccountManager::AccountHandler> _accountMgrPtr;
      Domain::AccountManager::AccountHandler & _accountMgr = *_accountMgrPtr;
      
      std::unique_ptr<Domain::ListingManager::ListingHandler> _listingMgrPtr;
      Domain::ListingManager::ListingHandler & _listingMgr = *_listingMgrPtr;

      std::unique_ptr<Domain::ResumeManager::ResumeHandler> _resumeMgrPtr;
      Domain::ResumeManager::ResumeHandler & _resumeMgr = *_resumeMgrPtr;
  };
} // namespace UI
