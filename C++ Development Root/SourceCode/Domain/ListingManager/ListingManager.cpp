#include "TechnicalServices/Persistence/PersistenceHandler.hpp"
#include "Domain/ListingManager/ListingManager.hpp"
#include "Domain/ListingManager/Listing.hpp"
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
    	long long listingID = _persistentData.listings.size();
    	_persistentData.listings.push_back(Listing("", "", listingID));
        return listingID;
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