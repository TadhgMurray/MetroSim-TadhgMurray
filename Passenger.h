/*
 *  Passenger.h
 *  Tadhg Murray (tmurra01)
 *  2/4/26
 *
 *  CS 15 Project 1 metrosim
 *
 *  Passenger is a class that represents a passenger on the metro. Each
 *  passenger has an id, starting station, and ending station. A new passenger
 *  begins with these values initalized, and has getters for all of these
 *  values, as well as a function to print them.
 *
 */

#ifndef __PASSENGER_H__
#define __PASSENGER_H__

#include <iostream>

class Passenger {
    public:
        //constructor function
        Passenger(int id, int startingStation, int endingStation);
        //getter functions
        int getId();
        int getStartingStation();
        int getEndingStation();
        //print function
        void print(std::ostream &output);
    private:
        int id;
        int startingStation;
        int endingStation;
};

#endif


