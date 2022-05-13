#include "Domain/AccountManager/Account.hpp"

Account::Account(std::string name,
				 long long   userID,
				 std::string accountCreated,
				 std::string password)
{
	_name           = name;
	_userID         = userID;
	_accountCreated = accountCreated;
	_password       = password;
};
Account::~Account(){};

std::string Account::getPassword()
{
	return _password;
};

void addToLog(std::string log)
{

}