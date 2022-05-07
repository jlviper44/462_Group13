#pragma once

#include <memory>    // unique_ptr
#include <string>
#include <vector>

#include "TechnicalServices/Logging/LoggerHandler.hpp"
#include "TechnicalServices/Persistence/PersistenceHandler.hpp"

#include "Domain/AccountManager/Account.hpp"
#include "Domain/ListingManager/Listing.hpp"
#include "Domain/ResumeManager/Resume.hpp"

namespace TechnicalServices::Persistence
{
  class SimpleDB : public TechnicalServices::Persistence::PersistenceHandler
  {
    public:
      using PersistenceHandler::PersistenceHandler;    // inherit constructors
      SimpleDB();


      // Operations
      // std::vector<std::string> findRoles()                                       override;  // Returns list of all legal roles
      // UserCredentials          findCredentialsByName( const std::string & name ) override;  // Returns credentials for specified user, throws NoSuchUser if user not found

      //Account, Listing, Resume
      std::vector<std::vector<std::string>> getUserLogs() override;
      std::vector<Account> getAllAccounts() override;
      bool resetPassword(long long userID) override;

      std::vector<Account> accounts;
      std::vector<Listing> listings;
      std::vector<Resume>  resumes;

      std::vector<std::string> getResumeTypes() override;

      // Adaptation Data read only access.  Adaptation data is a Key/Value pair
      const std::string & operator[]( const std::string & key ) const override;


      ~SimpleDB() noexcept override;

    private:
      std::unique_ptr<TechnicalServices::Logging::LoggerHandler> _loggerPtr;

      // convenience reference object enabling standard insertion syntax
      // This line must be physically after the definition of _loggerPtr
      TechnicalServices::Logging::LoggerHandler & _logger = *_loggerPtr;


      // Property data (Key/Value pairs) off-line modifiable by the end-user
      using AdaptationData = std::map<std::string /*Key*/, std::string /*Value*/>;
      AdaptationData _adaptablePairs;

  }; // class SimpleDB
}  // namespace TechnicalServices::Persistence
