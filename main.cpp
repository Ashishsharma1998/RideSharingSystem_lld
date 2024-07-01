#include "RideService.hpp"
#include "Passenger.hpp"
#include "Drivers.hpp"
#include "Location.hpp"
#include "Ride.hpp"
#include<queue>



int main(){

    RideService *instance = RideService::getInstance();

    Passenger *p1 = new Passenger(instance->genearateRandomId(),"ashish","8887888789",new Location(12.21,12.2)); 
    Passenger *p2 = new Passenger(instance->genearateRandomId(),"Tilu","8887888789",new Location(12.1,12.2)); 
    
    instance->registerPassenger(p1);
    instance->registerPassenger(p2);

    Driver *d1 = new Driver(instance->genearateRandomId(),"Parwez","HR12-1998",new Location(3.3,5.78),AVAILABLE);

    instance->requestRide(p1,p1->getLocation(),new Location(45.6,76.9),PREMIUM);
    instance->requestRide(p2,p2->getLocation(),new Location(23.5,2.6),REGULAR);
    
    std::queue<Ride*> q = instance->getRequestedRides();
    Ride *ride1 = q.front();
    q.pop();
    instance->acceptRide(ride1,d1);

    instance->startRide(ride1);

    instance->completeRide(ride1);

    Ride *ride2 = q.front();
    q.pop();

    instance->acceptRide(ride2,d1);

    instance->cancelRide(ride2);
    
 return 0;
}