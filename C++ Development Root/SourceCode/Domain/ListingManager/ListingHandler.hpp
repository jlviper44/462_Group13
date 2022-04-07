#ifndef __LISTINGHANDLER__
#define __LISTINGHANDLER__
#include <vector>


#include <memory>

namespace Domain::ListingManager
{
    class ListingHandler{
        public:

            //Manager Factory
            static std::unique_ptr<ListingHandler> createMgr();
          
            //Destructor
            virtual ~ListingHandler() noexcept = 0;
    };

}

#endif