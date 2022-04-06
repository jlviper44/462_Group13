#include "SessionHandler.hpp"

bool sessionHandler::authenticateUser(std::string inputtedUsername, std::string inputtedPassword, std::string username, std::string password)
{
	// if (user.getUserID() == userName && user.getPassword() == password)
	// {
	// 	return true;
	// }
	if(inputtedUsername != username && inputtedPassword != password)
	{
		return false;
	}

	_currentSession = Session();
	return true;
};

bool sessionHandler::terminateUserSession()
{
	// std::cout<<user.getPassword() << user.getUserID() << std::endl;
	
	return true;
};