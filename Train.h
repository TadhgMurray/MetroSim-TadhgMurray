/*
 *  Train.h
 *  Tadhg Murray (tmurra01)
 *  2/4/26
 *
 *  CS 15 Project 1 metrosim
 *
 *  Train is a class that represents a train in the metro simulation. It
 *  starts empty, and passengers can be loaded/unloaded based on what station
 *  the train is at. It also supports printing the information of the 
 *  passengers on the train.
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
        Train(int numStations);
        void unloadPassengers(const Station &s, std::ostream &log);
        void loadPassengers(Station &s);
        void print(std::ostream &output);
        ~Train();
    private:
        std::vector <PassengerQueue> trainPassengers;
        int numStations;
        //private helper functions
        int getLowestStation(PassengerQueue pq);
        void sortPassengerQueue(PassengerQueue correctOrder);
        bool compareById(Passenger& p0, Passenger& p1);
};

#endif