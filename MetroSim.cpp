/*
 *  MetroSim.cpp
 *  Tadhg Murray(tmurra01)
 *  2/4/26
 *
 *  CS 15 Project 1 metrosim
 *
 *  This file contains an implementation of the MetroSim class.
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cerrno>
#include <cstring>


#include "MetroSim.h"

/*
 * name:      MetroSim
 * purpose:   creates a MetroSim object
 * arguments: none
 * returns:   none
 * effects:   none
 * other:     none
 */
MetroSim::MetroSim() {
    currentStationIndex = 0;
    maxStationIndex = 0;
    currentPassengerID = 1;
}

/*
 * name:      addStation
 * purpose:   adds station to the station list
 * arguments: Station s to add to station list
 * returns:   none
 * effects:   none
 * other:     none
 */
void MetroSim::addStation(Station s) {
    stationList.push_back(s);
    maxStationIndex++;
}

/*
 * name:      getMaxStationIndex
 * purpose:   returns the index of the last station in the line
 * arguments: none
 * returns:   none
 * effects:   none
 * other:     none
 */
int MetroSim::getMaxStationIndex() {
    return maxStationIndex;
}

/*
 * name:      getCurrentPassengerID
 * purpose:   returns the index of the last passenger added + 1
 * arguments: none
 * returns:   none
 * effects:   none
 * other:     none
 */
int MetroSim::getCurrentPassengerID() {
    return currentPassengerID;
}

/*
 * name:      getCurrentStationIndex
 * purpose:   returns the index of current Station the train is at
 * arguments: none
 * returns:   none
 * effects:   none
 * other:     none
 */
int MetroSim::getCurrentStationIndex() {
    return currentStationIndex;
}

/*
 * name:      addPassenger
 * purpose:   adds passenger to a station queue
 * arguments: std::string command for Passenger's start and end station index
 * returns:   none
 * effects:   none
 * other:     bug: if startStationIndex is incorrect program crashes
 */
void MetroSim::addPassenger(std::string command) {
    std::istringstream iss(command);
    char cmd;
    iss >> cmd;
    int startStationIndex;
    int endStationIndex;
    //gets start and end station from istringstream instance
    iss >> startStationIndex >> endStationIndex;
    Passenger p = createPassenger(startStationIndex, endStationIndex);
    stationList[start].addPassenger(p);
}

/*
 * name:      createPassenger
 * purpose:   creates passenger
 * arguments: int startStation that passenger enters from, int endStation that
 * passenger exits from
 * returns:   none
 * effects:   none
 * other:     bug: if startStationIndex is incorrect program crashes
 */
Passenger MetroSim::createPassenger(int startStation, int endStation) {
    Passenger p(currentPassengerID, start, end);
    currentPassengerID++;
    return p;
}

/*
 * name:      currentInput
 * purpose:   moves the train to the next station
 * arguments: std::ostream &output to write unloading info into
 * returns:   none
 * effects:   none
 * other:     none
 */
void MetroSim::moveTrain(std::ostream &output) {
    //std:: ostringstream log to put unloading passenger info into
    std::ostringstream exitLog;
    //loads people into train before leaving station, erases passengers
    //from station
    train1.loadPassengers(stationList[currentStationIndex]);
    //unloads immediately after entering new station
    currentStationIndex++;
    //loops around stations if necessary
    if (currentStationIndex >= maxStationIndex) {
        currentStationIndex = 0;
    }
    train1.unloadPassengers(stationList[currentStationIndex], exitLog);
    output << exitLog.str();
}

/*
 * name:      printCurrentSimulation
 * purpose:   prints out the current simulation log
 * arguments: none
 * returns:   none
 * effects:   none
 * other:     none
 */
void MetroSim::printCurrentSimulation() {
    //std:: ostringstream log to put current simulation log into
    std::ostringstream out;
    //use train and station print functions to print simulation
    train1.print(out);
    for (int i = 0; i < stationList.size(); i++) {
        //if train is at this index prints Train:
        if (i == currentStationIndex) {
            out << "TRAIN: ";
        }
        else {
            out << "       ";
        }
        stationList[i].print(out);
    }
    std::cout << out.str();
}
