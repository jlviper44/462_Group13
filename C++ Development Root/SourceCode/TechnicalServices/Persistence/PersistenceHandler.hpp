#pragma once

#include <map>
#include <stdexcept>    // domain_error, runtime_error
#include <string>
#include <vector>

#include "Domain/AccountManager/Account.hpp"
#include "Domain/ListingManager/Listing.hpp"
#include "Domain/ResumeManager/Resume.hpp"


namespace TechnicalServices::Persistence
{
  // Persistence Package within the Technical Services Layer Abstract class
  // Singleton Class - only one instance of the DB exists for the entire system
  class PersistenceHandler
  {
    public:
      // Exceptions
      struct PersistenceException : std::runtime_error   {using runtime_error       ::runtime_error;};
      struct   NoSuchUser         : PersistenceException {using PersistenceException::PersistenceException;};
      struct   NoSuchProperty     : PersistenceException {using PersistenceException::PersistenceException;};

      // Creation (Singleton)
      PersistenceHandler            (                            ) = default;
      PersistenceHandler            ( const PersistenceHandler & ) = delete;
      PersistenceHandler & operator=( const PersistenceHandler & ) = delete;
      static  PersistenceHandler & instance();


      // Operations
      std::vector<Account> accounts;
      std::vector<Listing> listings;
      std::vector<Resume>  resumes;
      virtual std::vector<std::vector<std::string>> getUserLogs() = 0;
      virtual std::vector<std::string> getResumeTypes() = 0;
      virtual std::vector<Account> getAllAccounts() = 0;
      virtual bool resetPassword(long long userID) = 0;

      // Adaptation Data read only access.  Adaptation data is a Key/Value pair
      // Throws NoSuchProperty
      virtual const std::string & operator[]( const std::string & key ) const = 0;


      // Destructor
      // Pure virtual destructor helps force the class to be abstract, but must still be implemented
      virtual ~PersistenceHandler() noexcept = 0;
  };
} // namespace TechnicalServices::Persistence
