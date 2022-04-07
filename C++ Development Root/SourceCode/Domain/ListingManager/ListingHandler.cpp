#include <memory>
#include <iostream>
#include "ListingHandler.hpp"
#include "ListingManager.hpp"
#include "Listing.hpp"



namespace Domain::ListingManager
{
    std::unique_ptr<ListingHandler> ListingHandler::createMgr()
    {
        std::cout << "ListingHandler running...";
        std::vector<Listing> listings;
        return std::make_unique<ListingManager>(listings);
    }
    ListingHandler::~ListingHandler(){}
}