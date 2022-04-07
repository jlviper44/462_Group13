#ifndef __LISTING__
#define __LISTING__
#include <iostream>

class Listing
{
	public:
		std::string _name;
		std::string _type;
		long long   _id;

		Listing(std::string name,
				std::string type,
				long long   id);
		~Listing();
};

#endif