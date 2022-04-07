#ifndef __SESSION__
#define __SESSION__

#include "Domain/AccountManager/Account.hpp"

class Session
{
	public:
		long long _id;
		std::string _date;

		Session();
		~Session();
};

#endif