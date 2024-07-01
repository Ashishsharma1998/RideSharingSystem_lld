#pragma once

#include "../Ride.hpp"
#include "PaymentStatus.hpp"
#include "PaymentInterface.hpp"

class RegularFare:public PaymentInterface {
   public:
    double calculateFare(double fare){
         double actualFare  = fare - fare*0.2;
         return actualFare;
    }
};