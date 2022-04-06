#ifndef __RESUME__
#define __RESUME__

class Resume
{
	public:
		std::string _name;
		long long   _id;
		std::string _date;
		long long   _userID;
		std::string _description;

		Resume( std::string name,
				long long   id,
				std::string date,
				long long   userID,
				std::string description);
		~Resume();
};

#endif