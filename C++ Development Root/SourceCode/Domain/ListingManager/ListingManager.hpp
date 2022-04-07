#ifndef __LISTINGMANAGER__
#define __LISTINGMANAGER__
#include <vector>
#include <iostream>
#include "Listing.hpp"
#include "ListingHandler.hpp"

namespace Domain::ListingManager
{
    class ListingManager : public Domain::ListingManager::ListingHandler
    {
        public:

           

            std::vector<Listing> _listings;

            ListingManager(std::vector<Listing> listings);

            ~ListingManager() noexcept override;

            //func def



            Listing createNewJobObj(std::string name,
                    std::string type,
                    long long   id);

            
            Listing writeListingInfo(std::string jobName, std::string jobType);

           bool confirmSavedListing(Listing listing);

           bool postListing(Listing listing);

           void confirmPostedListing(Listing listing, std::vector<Listing> listings); 

            void showFormatting();

            void showVector(std::vector<Listing> listings);

     
    };
}

#endif