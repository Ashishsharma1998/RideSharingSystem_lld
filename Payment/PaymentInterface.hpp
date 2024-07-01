#pragma once

#include "../Ride.hpp"
#include "../RideType.hpp"
#include "PaymentStatus.hpp"

class PaymentInterface{
  public:
    virtual double calculateFare(double amount)=0;
};