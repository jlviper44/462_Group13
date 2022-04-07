#include "Resume.hpp"

Resume::Resume( std::string name,
				long long id,
				std::string date,
				long long userID,
				std::string description)
{
	_name        = name;
	_id          = id;
	_date        = date;
	_userID      = userID;
	_description = description; 

}

Resume::~Resume(){}