/*
 *  Station.h
 *  Tadhg Murray (tmurra01)
 *  2/4/26
 *
 *  CS 15 Project 1 metrosim
 *
 *  Station is a class that represents a station in the metro simulation. It
 *  starts empty, and passengers can be inserted/removed at
 *  the first index. It also supports getting its size and getting the front
 *  Passenger. It can also print the info of each Passenger it contains/ 
 *
 */

#ifndef __STATION__
#define __STATION__

#include <iostream>
#include <vector>
#include <string>

#include "Passenger.h"
#include "PassengerQueue.h"


class Station {
    public:
        Station(int num, std::string name);
        //getters
        int getStationNumber() const;
        std::string getStationName() const;
        PassengerQueue getPassengerList(int index);
        Passenger getFirstPassenger();
        int getQueueSize();
        //print functions
        void print(std::ostream &output);
        //passenger insertion/removal
        void addPassenger(Passenger p);
        void erasePassengers();
        void dequeue();
    private:
        PassengerQueue stationPassengers;
        int stationNumber;
        std::string stationName;

};

#endif