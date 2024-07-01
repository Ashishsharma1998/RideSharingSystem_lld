#pragma once

#include "../Ride.hpp"
#include "PaymentStatus.hpp"

class Payment{
  private:
    int id;
    Ride *ride;
    double amount;
    PaymentStatus status;
  public:
    Payment(int id,Ride *ride , double amt,PaymentStatus status){
        this->id=id;
        this->ride=ride;
        this->amount=amt;
        this->status=status;
    }

     void setAmount(double amt=0.0){
         this->amount=amt;
    }

    void setPaymentStatus(PaymentStatus status=PENDING){
       this->status=status;
    }

    void setRide(Ride *ride=nullptr){
        this->ride=ride;
    }

    void setId(int id=0){
        this->id=id;
    }

    int getId(){
        return id;
    }

    Ride *getRide(){
        return ride;
    }

    double getFare(){
        return amount;
    }

    PaymentStatus getPaymentStatus(){
        return status;
    } 
};

