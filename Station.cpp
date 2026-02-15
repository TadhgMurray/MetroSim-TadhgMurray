/*
 *  Station.cpp
 *  Tadhg Murray(tmurra01)
 *  2/4/26
 *
 *  CS 15 Project 1 metrosim
 *
 *  This file contains an implementation of the Station class.
 *
 */
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Station.h"


/*
 * name:      Station
 * purpose:   creates a station with an index and a name
 * arguments: int num that represents the station's index and std::string name
 * representing the station's name
 * returns:   nothing
 * effects:   none
 * other:     none
 */
Station::Station(int num, std::string name) {
    stationNumber = num;
    stationName = name;
}

/*
 * name:      getStationNumber const
 * purpose:   gets the number(index) of the station
 * arguments: none
 * returns:   returns int of the station's number(index)
 * effects:   none
 * other:     none
 */
int Station::getStationNumber() const {
    return stationNumber;
}

/*
 * name:      getStationName const
 * purpose:   gets the name of the station
 * arguments: none
 * returns:   returns std::string of the station's name
 * effects:   none
 * other:     none
 */
std::string Station::getStationName() const {
    return stationName;
}

/*
 * name:      getQueueSize
 * purpose:   gets the size of the station's passenger queue
 * arguments: none
 * returns:   int size of the station's passenger queue
 * effects:   none
 * other:     none
 */
int Station::getQueueSize() {
    return stationPassengers.size();
}

/*
 * name:      addPassenger
 * purpose:   adds a passenger to the station's queue at the end
 * arguments: Passenger p to add to queue
 * returns:   none
 * effects:   none
 * other:     none
 */
void Station::addPassenger(Passenger p) {
    stationPassengers.enqueue(p);
}

/*
 * name:      erasePassengers
 * purpose:   removes passengers from station queue
 * arguments: none
 * returns:   none
 * effects:   none
 * other:     none
 */
void Station::erasePassengers() {
    while (stationPassengers.size() > 0) {
        stationPassengers.dequeue();
    }
}

/*
 * name:      getFirstPassenger
 * purpose:   gets the first Passenger in the Station's queue
 * arguments: none
 * returns:   Passenger in queue that user wanted
 * effects:   none
 * other:     bug: if queue is empty, crashes
 */
Passenger Station::getFirstPassenger() {
    return stationPassengers.front();
}

/*
 * name:      dequeue
 * purpose:   removes first passenger from station queue
 * arguments: none
 * returns:   none
 * effects:   none
 * other:     bug: if queue is empty crashes
 */
void Station::dequeue() {
    stationPassengers.dequeue();
}

/*
 * name:      print
 * purpose:   prints the station number, station name, and all passengers
 *            currently waiting at the station
 * arguments: std::ostream &output — the output stream to write to
 * returns:   none
 * effects:   none
 * other:     none
 */
void Station::print(std::ostream &output) {
    output << "[" << stationNumber << "] " << stationName << " {";
    stationPassengers.print(output);
    output << "}" << std::endl;
}