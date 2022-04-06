#ifndef __ACCOUNT__
#define __ACCOUNT__

class Account
{
	public:
		Account(std::string name,
				std::string userID,
				std::string accountCreated,
				std::string password);
		std::string _name;
		std::string getUserID();
		std::string getPassword();
	private:
		std::string _userID;
		std::string _accountCreated;
		std::string _password;


};

#endif