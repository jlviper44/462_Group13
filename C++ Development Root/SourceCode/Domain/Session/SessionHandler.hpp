#include "../Session/Session.hpp"

#ifndef _SESSIONHANDLER_HPP_
#define _SESSIONHANDLER_HPP_

class sessionHandler
{
	private:
		Session _currentSession;

	public:
		bool authenticateUser(std::string inputtedUsername, std::string inputtedPassword, std::string username, std::string password);
		bool terminateUserSession();
};

#endif