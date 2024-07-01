#pragma once

#include "Passenger.hpp"
#include "Drivers.hpp"
#include "Location.hpp"
#include "RideStatus.hpp"
#include "RideType.hpp"

class Ride{
  private: 
   int id;
   Passenger *passenger;
   Driver *driver;
   Location *source;
   Location *destination;
   double fare;
   RideStatus status;
   RideType ridetype;
  public:
   Ride(int id,Passenger *passenger,Driver *driver,Location *src,Location *dest,double fare,RideStatus status,RideType type){
     this->id=id;
     this->passenger=passenger;
     this->driver=driver;
     this->source=src;
     this->destination=dest;
     this->fare=fare;
     this->status=status; 
     this->ridetype=type;
   }  
   
   RideType getRideType(){
    return ridetype;
   }

   void setId(int id){
     this->id=id;
   }

   void setPassenger(Passenger *p){
      this->passenger=p;
   }

   void setDriver(Driver *d){
     this->driver=d;
   }

   void setSource(Location *src){
      this->source=src;
   }

   void setFare(double fare){
     this->fare=fare;
   }

   void setDestination(Location *dest){
      this->destination=dest;
   }

   void setRideStatus(RideStatus status){
     this->status=status;
   }

   int getId(){
    return id;
   }

   Passenger* getPassenger(){
    return passenger;
   }

   Driver* getDriver(){
    return driver;
   }

   double getFare(){
    return fare;
   }

   Location* getSource(){
     return source;
   }

   Location* getDestination(){
     return destination;
   }
   
   RideStatus getStatus(){
    return status;
   }

};