#include <exception>    // exception
#include <iostream>
#include <locale>       // touuper(), locale()
#include <new>          // bad_alloc
#include <typeinfo>     // typeinfo.name()

// #include "Domain/SessionManager/SessionHandler.hpp"
// #include "Domain/AccountManager/Account.hpp"
#include "UI/UserInterfaceHandler.hpp"
#include "Domain/ListingManager/ListingHandler.hpp"
#include "Domain/ListingManager/ListingManager.hpp"
#include "Domain/ListingManager/Listing.hpp"
#include "Domain/Session/SessionHandler.hpp"
#include "Domain/Session/Session.hpp"

#include "Domain/AccountManager/AccountHandler.hpp"

#include <vector>



int main()
{


/*
  std::vector<Listing> listings;
  ListingManager listingManager(listings);
  

  std::cout << "attempting to run createNewJob";
  listingManager.createNewJobObj("test", "test", 1234);
  */

 std::vector<Listing> listings;
 

  try
  {
    auto userInterface = UI::UserInterfaceHandler::createUI();

    std::cout << "\nInitialization completed successfully\n";

    char response;
    do
    {
      std::cout << "Ready to transition into Operational State? (Q/Y/N) ";
      std::cin >> response;
      response = std::toupper( response, std::locale() );
    } while( response != 'Y' && response != 'Q' );

    if( response == 'Y' ) userInterface->launch();


    std::cout << "\nProgram complete, initiating shutdown\n";
  }



  catch( const std::bad_alloc & ex )
  {
    std::cerr << "Fatal:  Uncaught memory allocation exception\n\n"
              << ex.what() << '\n';
  }

  catch( const std::exception & ex )
  {
    std::cerr << "Fatal:  Uncaught standard exception\n"
              << typeid( ex ).name() << '\n'
              << ex.what() << '\n';
  }

  catch( ... )
  {
    std::cerr << "Fatal:  Uncaught (unknown type) exception\n";
  }


  std::cout << "Available tests:\n" 
            << "1: Post Job Listing\n"
            << "2: Build Resume\n"
            << "3: Manage and Monitor Logs\n"
            << "4: Quit\n"
            << "Enter the ssd number you would like to test: ";

  char response;
  std::cin >> response;

  if (response == '1')
  {
    /*auto acc = Account("Justin", "0000XX", "01/01/2022 12:00 AM", "JustinLee");
    auto session = sessionHandler();
    bool auth = session.authenticateUser(acc, "0000XX", "JustinLee");*/
    bool auth = true;
    if(auth == true)
    {
      std::cout<<"Account Successfully Authenticated\n";
    }
    else
    {
      std::cout<<"Account Failed Authentication\n";
    }

  }

  else if (response == '2')
  {

  }

  else if (response == '3')
  {

  }
  else if (response == '4')
  {
    
  }
  else
  {
    std::cout << response << " is not available!\n";
  }

};
