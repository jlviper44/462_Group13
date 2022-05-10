#include "TechnicalServices/PaymentAuth/PaymentAuthHandler.hpp"
#include "TechnicalServices/PaymentAuth/PaymentAuth.hpp"

#include <memory>    // unique_ptr, make_unique

#include "TechnicalServices/Persistence/PersistenceHandler.hpp"


namespace TechnicalServices::PaymentAuth
{
  PaymentAuthHandler::~PaymentAuthHandler() noexcept = default;

  std::unique_ptr<PaymentAuthHandler> PaymentAuthHandler::createPaymentAuth()
  {
    auto & persistantData = TechnicalServices::Persistence::PersistenceHandler::instance();
    auto   requestedPaymentAuth     = persistantData["PaymentAuthMethod"];



    if     ( requestedPaymentAuth == "Debit" ) return std::make_unique<Debit>();
    else if( requestedPaymentAuth == "Credit" ) return std::make_unique<Credit>();
    else if( requestedPaymentAuth == "Paypal" ) return std::make_unique<Paypal>();

    

    //throw BadPaymentAuthRequest( "Unknown Payment Auth object requested: \"" + requestedPaymentAuth + "\"\n  detected in function " + __func__);
  }
}    // namespace PaymentAuth
