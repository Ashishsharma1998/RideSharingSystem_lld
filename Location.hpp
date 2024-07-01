#pragma once

class Location{
   private: 
    double longitude;
    double latitude;
   public: 
    Location(double longitude , double latitude){
        this->latitude=latitude;
        this->longitude=longitude;
    }
};