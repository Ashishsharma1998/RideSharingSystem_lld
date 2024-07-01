#pragma once

#include "../Ride.hpp"
#include "../RideType.hpp"
#include "PaymentStatus.hpp"
#include "PaymentInterface.hpp"

class PaymentContext{
   private:
    PaymentInterface *paymentInterface;  
   public:
    PaymentContext(PaymentInterface *payInterface=nullptr){
        this->paymentInterface = payInterface;
    }
    
   double getCalculatedFare(double amt){
    return this->paymentInterface->calculateFare(amt);
   } 
};