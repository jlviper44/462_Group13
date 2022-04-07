#include "Listing.hpp"
#include <iostream>

Listing::Listing(std::string name,
				 std::string type,
				 long long   id)
{
	_name = name;
	_type = type;
	_id   = id;
	isPosted = false;

}

Listing::~Listing(){}