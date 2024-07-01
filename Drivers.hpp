#pragma once

#include<string>
#include "Location.hpp"
#include "DriverStatus.hpp"

class Driver{
 private:
   int id;
   std::string name;
   std::string lincenseNumber;
   Location *location;
   DriverStatus status;
 public:
   Driver(int id,std::string name,std::string lincenseNumber,Location *location,DriverStatus status){
    this->id=id;
    this->name=name;
    this->lincenseNumber=lincenseNumber;
    this->location=location;
    this->status=status;
   }

   void setId(int id){
     this->id=id;
   }

   void setName(std::string name){
     this->name=name;
   }

   void setLicenseNumber(std::string number){
      this->lincenseNumber=number;
   }

   void setLocation(Location* location){
      this->location=location;
   }

   void setDriverStatus(DriverStatus status){
     this->status=status;
   }

   int getId(){
     return id;
   }

   std::string getName(){
     return name;
   }

   std::string getLicenseNumber(){
      return lincenseNumber;
   }

   Location* getLocation(){
      return location;
   }

   DriverStatus getDriverStatus(){
     return status;
   }
};