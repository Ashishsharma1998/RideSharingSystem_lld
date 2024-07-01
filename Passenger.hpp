#pragma once

#include<string>
#include "Location.hpp"

class Passenger{
  private:
    int id;
    std::string name;
    std::string contact;
    Location *location;
  public:
    Passenger(int id,std::string name,std::string contact,Location *location){
       this->id=id;
       this->name=name;
       this->contact=contact;
       this->location=location;
    }

    int getId(){
        return id;
    }

    Location* getLocation(){
        return location;
    }

    std::string getName(){
       return name;
    }

    std::string getContact(){
        return contact;
    }

   void setId(int id){
     this->id=id;
   }

   void setName(std::string name){
     this->name=name;
   }

   void setContact(std::string contact){
    this->contact=contact;
   }

   void setLocation(Location* location){
      this->location=location;
   }
};