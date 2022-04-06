#ifndef __ACCOUNT__
#define __ACCOUNT__

#include <any>
#include <memory>
#include <string>
#include <vector>
#include "TechnicalServices/Logging/LoggerHandler.hpp"


class Account
{
	public:
		std::string _name;
		long long   _userID;

		Account(std::string name,
				long long   userID,
				std::string accountCreated,
				std::string password);
		~Account();

		std::string getPassword();
		void addToLog(std::string log);

	private:
		std::string _accountCreated;
		std::string _password;
		std::vector<std::string> _log;
};

#endif