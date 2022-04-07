#include "ListingManager.hpp"
#include "Listing.hpp"
#include <vector>
#include <iostream>

namespace Domain::ListingManager{
	
	ListingManager::ListingManager(std::vector<Listing> listings)
	{
		std::cout << "Listing Manager says hello";
		 _listings = listings;
	}

	ListingManager::~ListingManager(){}

	Listing ListingManager::createNewJobObj(std::string name,
					std::string type,
					long long   id)
	{
		Listing listing(name, type, id);
		std::cout << "\nListing made successfully\n";
		_listings.push_back(listing);
		return listing;

	}

}