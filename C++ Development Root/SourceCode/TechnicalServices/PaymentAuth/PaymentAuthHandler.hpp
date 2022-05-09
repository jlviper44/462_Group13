#ifndef __PAYMENTAUTHHANDLER__
#define __PAYMENTAUTHHANDLER__

//#pragma once

#include <memory>       // unique_ptr
#include <stdexcept>    // runtime_error
#include <set>
#include <iostream>
#include <string>



namespace TechnicalServices::PaymentAuth
{
  // User Interface Layer Interface class
  class PaymentAuthHandler
  {
    public:

      static std::set<PaymentAuthHandler *> & allPaymentMethods()
      { return paymentMethods; }
      // Payment Auth Factory
      static std::unique_ptr<PaymentAuthHandler> createPaymentAuth();                                 // must be static

      virtual void newCharge() = 0;

      // Interface class destructor
      virtual ~PaymentAuthHandler() noexcept = 0;                                            // must be virtual, best practice to be pure

    protected:
      PaymentAuthHandler( PaymentAuthHandler * paymentMethod )
      { paymentMethods.insert( paymentMethod ); }


      inline static std::set<PaymentAuthHandler *> paymentMethods;
  };
} // namespace PaymentAuth



#endif