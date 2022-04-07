#include "ListingManager.hpp"
#include "Listing.hpp"
#include <vector>
#include <iostream>

int jobID = 0;

namespace Domain::ListingManager{
	
	 std::string jobName;
     std::string jobType;
	 //int jobID = 0;


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

	void ListingManager::showFormatting(){
		std::cout << "Please enter Job Listing Information as follows\n";
		std::cout << "Job Name and Job Type\n";
		std::cout << "Please enter Job Name (space) Job Type:\n";
	}



	void ListingManager::confirmPostedListing(Listing listing, std::vector<Listing> listings){
		if (listing.isPosted == true) {
			Listing key = listings.back();
			if (listing._id == key._id){
				std::cout << "Job Listing was successfully POSTED!\n";
				std::cout << "The data of the newly posted job listing is as follows:\n";
				if (key.isPosted == true){
					std::cout << "Job Name: " << key._name;
					std::cout << "\nJob Type: " << key._type;
					std::cout << "\nJob ID: " << key._id;
				} else {
					std::cout << "Job Listing could not be posted.";
				}
			} else {
				return;
			}
		} else return;
	}


	void ListingManager::postListing(Listing listing){

		_listings.push_back(listing);
	}

	bool ListingManager::confirmSavedListing(Listing listing){
		if (listing._id == 0 || listing._name == "" || listing._type == ""){
			std::cout << "Job Listing was NOT successfully saved!";
			return false;
		} else {
			std::string userAnswer;
			std::cout << "Job Listing was successfully SAVED! Would you like to post the listing to the public?\n";
			std::cout << "\nY | N:\n";
			std::cin >> userAnswer;
			if(userAnswer == "Y" || userAnswer == "y"){
				listing.isPosted = true;
				return true;
			} else {
				std::cout << "Job listing discarded!";
				return false;
			}
		}
	}

	Listing ListingManager::writeListingInfo(std::string jobName, std::string jobType){
		jobID = jobID + 1;
		Listing listing(jobName, jobType, jobID);

		return listing;
	}

}