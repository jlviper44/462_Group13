#ifndef __PAYMENTAUTH__
#define __PAYMENTAUTH__

#include <memory>
#include <set>

#include "TechnicalServices/PaymentAuth/PaymentAuthHandler.hpp"

namespace TechnicalServices::PaymentAuth
{
    class Debit : public PaymentAuthHandler
    {
        public:
            Debit() : PaymentAuthHandler( this ){}

            void newCharge(){ std::cout << "This will charge your debit card" << std::endl; };
    };
    class Credit : public PaymentAuthHandler
    {
        public:
            Credit() : PaymentAuthHandler( this ){}

            void newCharge(){ std::cout << "This will charge your credit card" << std::endl; };
    };
    class Paypal : public PaymentAuthHandler
    {
        public:
            Paypal() : PaymentAuthHandler( this ){}

            void newCharge(){ std::cout << "This will charge your paypal account" << std::endl; };
    };
}



#endif