#ifndef __LISTINGHANDLER__
#define __LISTINGHANDLER__
#include <vector>
#include "Listing.hpp"



#include <memory>

namespace Domain::ListingManager
{
    class ListingHandler{
        public:

            //Manager Factory
            static std::unique_ptr<ListingHandler> createMgr();
          
            //Destructor
            virtual ~ListingHandler() noexcept = 0;

            virtual void showFormatting() = 0;
            virtual Listing writeListingInfo(std::string jobName, std::string jobType) = 0;
            virtual bool confirmSavedListing(Listing listing) = 0;
            virtual bool postListing(Listing listing) = 0;
           
            virtual void confirmPostedListing(Listing listing, std::vector<Listing> listings) = 0;
    };

}

#endif