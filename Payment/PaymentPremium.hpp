#pragma once

#include "../Ride.hpp"
#include "PaymentStatus.hpp"
#include "PaymentInterface.hpp"

class PremiumFare:public PaymentInterface {
   public:
    double calculateFare(double fare){
         double actualFare  = fare - fare*0.3;
         return actualFare;
    }
};