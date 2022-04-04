#include "../AccountManager/Account.hpp"

#ifndef _SESSIONHANDLER_HPP_
#define _SESSIONHANDLER_HPP_

class sessionHandler
{
	private:
		std::string sessionID;
		std::string sessionDate;

	public:
		bool authenticateUser(Account user, std::string userName, std::string password);
		bool terminateUserSession();
};

#endif