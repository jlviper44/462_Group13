#include <memory>
#include <iostream>
#include "Domain/ListingManager/ListingHandler.hpp"
#include "Domain/ListingManager/ListingManager.hpp"



namespace Domain::ListingManager
{
    std::unique_ptr<ListingHandler> ListingHandler::createMgr()
    {
        return std::make_unique<ListingManager>();
    }
    ListingHandler::~ListingHandler(){}
}