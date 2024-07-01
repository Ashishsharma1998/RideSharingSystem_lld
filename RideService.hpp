#pragma once

#include<map>
#include<queue>
#include<iostream>
#include "Drivers.hpp"
#include "Passenger.hpp"
#include "Ride.hpp"
#include "./Payment/PaymentContext.hpp"
#include "./Payment/PaymentRegular.hpp"
#include "./Payment/PaymentPremium.hpp"
#include "./Payment/Payment.hpp"


class RideService{
  private:
   static RideService *instance;
   std::map<int,Ride*> rides;
   std::map<int,Passenger*> passengers;
   std::map<int,Driver*> drivers;
   std::map<int,Payment*> payments;
   std::queue<Ride*> requestedRide;
   RideService(){
    std::cout<<"instance has been instantiated "<<std::endl;
   } 
  public:
   static RideService* getInstance(){
     if(instance==nullptr){
         instance = new RideService();
     }
     return instance;
   }

   void registerDriver(Driver *driver){
     drivers[driver->getId()] = driver;
   }

   void registerPassenger(Passenger *passenger){
     passengers[passenger->getId()] = passenger; 
   }

   void requestRide(Passenger *passenger , Location *src , Location *dest , RideType type){
      Ride * ride  = new Ride(genearateRandomId(),passenger,nullptr,src,dest,0.0,REQUESTED,type);
      requestedRide.push(ride);
      notifyDrivers(ride);
   }

   
   void acceptRide(Ride *ride,Driver *driver){
       if(ride->getStatus()==REQUESTED){
          driver->setDriverStatus(BUSY);
          ride->setRideStatus(ACCEPTED);
          ride->setDriver(driver);
          notifyPassenger(ride);
       }
   }

   void startRide(Ride *ride){
     if(ride->getStatus()==ACCEPTED){
        ride->setRideStatus(IN_PROGRESS);
        notifyPassenger(ride);
     }
   }

   void completeRide(Ride *ride){
     if(ride->getStatus()==IN_PROGRESS){
        ride->setRideStatus(COMPLETED);
        ride->getDriver()->setDriverStatus(AVAILABLE);
        double fare = calculateFare(ride);
        ride->setFare(fare);
        notifyDriver(ride);
        notifyPassenger(ride);
        processPayment(ride);
     }
   }

   void cancelRide(Ride *ride){
      if(ride->getStatus()==REQUESTED || ride->getStatus()==ACCEPTED){
         ride->setRideStatus(CANCELLED);
         notifyDriver(ride);
         notifyPassenger(ride);
         if(ride->getDriver()!=nullptr){
            ride->getDriver()->setDriverStatus(AVAILABLE);
         }
      }   
   }

   void notifyDrivers(Ride *ride){
       for(auto driver:drivers){
          if(driver.second->getDriverStatus()==AVAILABLE){
            double distance = calculateDistance(ride->getSource(),ride->getDestination());
            //notify driver within 5km radius 
            if(distance<=5){
                std::cout<<"Notifying Driver:--> "<<driver.second->getName()<<" about requested ride "<<ride->getId()<<std::endl; 
            }
          }
       }
   }

   //send notification to passenger
   void notifyPassenger(Ride *ride){
       Passenger *passenger = ride->getPassenger();
       std::string message = "";
       switch(ride->getStatus())
       {
       case ACCEPTED: 
        message="Your ride has been booked by driver " + ride->getDriver()->getName();
        break;

       case IN_PROGRESS:
        message="Your ride is in progress";
        break;

       case COMPLETED:
        message="Your ride has been completed with fare " + std::to_string(ride->getFare());
        break;  

       case CANCELLED:
        message="Your ride has been cancelled";
        break; 
       }
     std::cout<<"Notifying passenger:--> "<<passenger->getName()<<" "<<message<<std::endl;
   }
   
   //send notification to driver
   void notifyDriver(Ride *ride){
      Driver *driver = ride->getDriver();
      if(driver!=nullptr){
      std::string message = "";
      switch (ride->getStatus())
      {
      case COMPLETED:
        message="Ride has been completed with fare:- " + std::to_string(ride->getFare());
        break;
      
      case CANCELLED:
        message="Ride has been cancelled by passenger";
        break;
      }
     std::cout<<"Notifying driver:--> "<<driver->getName()<<" "<<message<<std::endl;
   } 
  }
   
   double calculateFare(Ride *ride){
        double baseFare = 2.0;
        double perKmFare = 1.5;
        double perMinuteFare = 0.25;

        double distance = calculateDistance(ride->getSource(), ride->getDestination());
        double duration = calculateDuration(ride->getSource(), ride->getDestination());

        double fare = baseFare + (distance * perKmFare) + (duration * perMinuteFare);
        if(ride->getRideType()==REGULAR){
             PaymentContext *payment = new PaymentContext(new RegularFare());
             fare = payment->getCalculatedFare(fare);
        }

        if(ride->getRideType()==PREMIUM){
             PaymentContext *payment = new PaymentContext(new PremiumFare());
             fare = payment->getCalculatedFare(fare);
        }
       return fare; 
   }

   double calculateDistance(Location *src , Location *dest){
       // Calculate the distance between two locations using a distance formula (e.g., Haversine formula)
        // For simplicity, let's assume a random distance between 1 and 20 km
        return rand() * 20 + 1;
   }

   double calculateDuration(Location *src , Location *dest){
        // Calculate the estimated duration between two locations based on distance and average speed
        // For simplicity, let's assume an average speed of 30 km/h
        double distance = calculateDistance(src, dest);
        return (distance / 30) * 60; // Convert hours to minutes
   } 

   void processPayment(Ride *ride){
     Payment *payment = new Payment(genearateRandomId(),ride,ride->getFare(),DONE);
     payments[ride->getId()]=payment;
     std::cout<<"payment is done with transaction id "<<payment->getId()<<" ride type --> "<<ride->getRideType()<<std::endl;
   }

   std::map<int,Ride*> getRides(){
     return rides;
   }

   std::queue<Ride*> getRequestedRides(){
     return requestedRide;
   }
   
   int genearateRandomId(){
    int x = rand()%99999999;
    return x;
   }
};

RideService* RideService::instance=nullptr;