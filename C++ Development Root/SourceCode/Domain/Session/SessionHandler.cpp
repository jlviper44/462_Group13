#include "SessionHandler.hpp"

bool sessionHandler::authenticateUser(Account user, std::string userName, std::string password)
{
	if (user.getUserID() == userName && user.getPassword() == password)
	{
		return true;
	}
	return false;
};

bool sessionHandler::terminateUserSession(Account user)
{
	// std::cout<<user.getPassword() << user.getUserID() << std::endl;
	
	return true;
};