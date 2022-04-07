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
};
