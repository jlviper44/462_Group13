#include "TechnicalServices/Persistence/PersistenceHandler.hpp"
#include "ListingManager.hpp"
#include "Listing.hpp"
#include <vector>
#include <iostream>

int jobID = 0;

namespace Domain::ListingManager{
	
	 std::string jobName;
     std::string jobType;
	 //int jobID = 0;


	ListingManager::ListingManager()
	: _persistentData( TechnicalServices::Persistence::PersistenceHandler::instance() ){}

	ListingManager::~ListingManager(){}

	long long ListingManager::createListing()
    {	
    	_persistentData.listings.push_back(Listing("", "", 000000));
        return 00000;
    }

    bool ListingManager::writeListingInfo(std::string jobName, std::string jobType, long long listingId)
    {
    	bool foundListing = false;
    	for (auto i : _persistentData.listings)
		{
			if(i._id == listingId)
			{
				foundListing = true;
				i._name = jobName;
				i._type = jobType;
			}
		}

		return foundListing;
	}

	bool ListingManager::confirmSavedListing(long long listingId)
    {
    	bool foundListing = false;
    	for (auto i : _persistentData.listings)
		{
			if(i._id == listingId)
			{
				foundListing = true;
			}
		}

		return foundListing;
	}

	bool ListingManager::postListing(long long listingId)
    {
    	bool foundListing = false;
    	for (auto i : _persistentData.listings)
		{
			if(i._id == listingId)
			{
				foundListing = true;
				i._isPosted = true;
			}
		}

		return foundListing;
	}

	bool ListingManager::isListingPosted(long long listingId)
    {
    	bool isListingPosted = false;
    	for (auto i : _persistentData.listings)
		{
			if(i._id == listingId)
			{
				isListingPosted = i._isPosted;
			}
		}

		return isListingPosted;
	}
}