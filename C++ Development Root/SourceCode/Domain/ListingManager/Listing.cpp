#include "Listing.hpp"

Listing::Listing(std::string name,
				 std::string type,
				 long long   id)
{
	_name = name;
	_type = type;
	_id   = id;
}

Listing::~Listing(){}