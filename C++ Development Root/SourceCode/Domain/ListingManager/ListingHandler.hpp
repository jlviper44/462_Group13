#ifndef __LISTINGHANDLER__
#define __LISTINGHANDLER__
#include <vector>
// #include "Listing.hpp"



#include <memory>

namespace Domain::ListingManager
{
    class ListingHandler{
        public:

            //Manager Factory
            static std::unique_ptr<ListingHandler> createMgr();
          
            //Destructor
            virtual ~ListingHandler() noexcept = 0;

            virtual long long createListing() = 0;
            virtual bool writeListingInfo(std::string jobName, std::string jobType, long long listingId) = 0;
            virtual bool confirmSavedListing(long long listingId) = 0;
            virtual bool postListing(long long listingId) = 0;
            virtual bool isListingPosted(long long listingId) = 0;
    };

}

#endif