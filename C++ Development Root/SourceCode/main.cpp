#include <exception>    // exception
#include <iostream>
#include <locale>       // touuper(), locale()
#include <new>          // bad_alloc
#include <typeinfo>     // typeinfo.name()

#include "Domain/SessionManager/SessionHandler.hpp"
#include "Domain/AccountManager/Account.hpp"

int main()
{
  std::cout << "Available ssd tests:\n" 
            << "1: Post Job Listing\n"
            << "4: Promote Job Listing\n"
            << "5: Manage and Monitor Logs\n"
            << "Enter the ssd number you would like to test: ";

  char response;
  std::cin >> response;

  if (response == '1')
  {
    auto acc = Account("Justin", "0000XX", "01/01/2022 12:00 AM", "JustinLee");
    auto session = sessionHandler();
    bool auth = session.authenticateUser(acc, "0000XX", "JustinLee");
    if(auth == true)
    {
      std::cout<<"Account Successfully Authenticated\n";
    }
    else
    {
      std::cout<<"Account Failed Authentication\n";
    }

  }

  else if (response == '4')
  {

  }

  else if (response == '5')
  {

  }
  else
  {
    std::cout << response << " is not available!\n";
  }

};
