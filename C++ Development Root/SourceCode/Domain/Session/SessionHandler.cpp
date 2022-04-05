#include "SessionHandler.hpp"

bool sessionHandler::authenticateUser(Account user, std::string userName, std::string password)
{
	// std::cout<<user.getPassword() << user.getUserID() << std::endl;
	if (user.getUserID() == userName && user.getPassword() == password)
	{
		return true;
	}
	return false;
};