/*
 *  Train.h
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

#ifndef __TRAIN__
#define __TRAIN__

#include <iostream>
#include <vector>

#include "Passenger.h"
#include "PassengerQueue.h"
#include "Station.h"

class Train {
    public:
        void unloadPassengers(const Station &s, std::ostream &log);
        void loadPassengers(Station s);
        void print(std::ostream &output);
    private:
        PassengerQueue trainPassengers;
        int getLowestStation(PassengerQueue pq);
        void sortPassengerQueue(PassengerQueue correctOrder);
};

#endif