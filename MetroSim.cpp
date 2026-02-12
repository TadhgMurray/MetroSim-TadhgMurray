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
 * purpose:   int argc representing number of commandline arguments,
 * char *argv[] that stores those command line arguments
 * returns:   none
 * effects:   none
 * other:     none
 */
MetroSim::MetroSim() {
    outputFile.open(argv[2]);
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
 * name:      addPassenger
 * purpose:   adds passenger to a station queue
 * arguments: std::string command for Passenger's start and end station index
 * returns:   none
 * effects:   none
 * other:     none
 */
void MetroSim::addPassenger(std::string command) {
    std::istringstream iss(current);
    char cmd;
    iss >> cmd;
    int startStationIndex;
    int endStationIndex;
    //gets start and end station from istringstream instance
    iss >> startStationIndex >> endStationIndex;
    Passenger p(currentPassengerID, startStationIndex, endStationIndex);
    stationList[startStationIndex].addPassenger(p);
    currentPassengerID++;
}

/*
 * name:      currentInput
 * purpose:   moves the train to the next station
 * arguments: none
 * returns:   none
 * effects:   none
 * other:     none
 */
void MetroSim::moveTrain() {
    //std:: ostringstream log to put unloading passenger info into
    std::ostringstream exitLog;
    //loads people into train before leaving station
    train1.loadPassengers(stationList[currentStationIndex]);
    stationList[currentStationIndex].erasePassengers();
    //unloads immediately after entering new station
    currentStationIndex++;
    //loops around stations if necessary
    if (currentStationIndex >= maxStationIndex) {
        currentStationIndex = 0;
    }
    train1.unloadPassengers(stationList[currentStationIndex], exitLog);
    outputFile << exitLog.str();
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

/*
 * name:      ~MetroSim
 * purpose:   closes the output file
 * arguments: none
 * returns:   none
 * effects:   none
 * other:     none
 */
MetroSim::~MetroSim() {
    if (outputFile.is_open()) {
        outputFile.close();
    }
}

