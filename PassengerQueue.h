/*
 *  PassengerQueu.h
 *  Tadhg Murray (tmurra01)
 *  2/4/26
 *
 *  CS 15 Project 1 metrosim
 *
 *  PassengerQueue is a class that represents a queue of passengers. It
 *  starts empty, and passengers can be inserted/removed at
 *  the first index. It also supports getting its size and getting the front
 *  Passenger. It can also print the info of each Passenger it contains/ 
 *
 */

#ifndef __PASSENGER_QUEUE__
#define __PASSENGER_QUEUE__

#include <iostream>
#include <vector>

#include "Passenger.h"

class PassengerQueue {
    public:
        //getter functions
        Passenger front();
        int size();
        //setter functions
        void dequeue();
        void enqueue(const Passenger &passenger);
        //print function
        void print(std::ostream &output);
    private:
        std::vector<Passenger> passengerQueue;
};

#endif