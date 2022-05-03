#ifndef __LISTINGMANAGER__
#define __LISTINGMANAGER__
#include <vector>
#include <iostream>
#include "ListingHandler.hpp"
#include "TechnicalServices/Persistence/PersistenceHandler.hpp"

namespace Domain::ListingManager
{
    class ListingManager : public Domain::ListingManager::ListingHandler
    {
        public:

           

            // std::vector<Listing> _listings;

            ListingManager();
            ~ListingManager() noexcept override;

            long long createListing();
            bool writeListingInfo(std::string jobName, std::string jobType, long long listingId);
            bool confirmSavedListing(long long listingId);
            bool postListing(long long listingId);
            bool isListingPosted(long long listingId);

        private:
            TechnicalServices::Persistence::PersistenceHandler & _persistentData;
     
    };
}

#endif