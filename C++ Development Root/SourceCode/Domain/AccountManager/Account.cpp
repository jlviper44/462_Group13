#include "Account.hpp"

Account::Account(std::string name,
				std::string userID,
				std::string accountCreated,
				std::string password)
{
	_name = name;
	_userID = userID;
	_accountCreated = accountCreated;
	_password = password;
};

std::string Account::getUserID()
{
	return _userID;
};
std::string Account::getPassword()
{
	return _password;
};