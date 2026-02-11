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
MetroSim::MetroSim(int argc, char *argv[]) {
    outputFile.open(argv[2]);
    currentStationIndex = 0;
    maxStationIndex = 0;
    currentPassengerID = 1;
    this->argc = argc;
    this->argv = argv;
}

/*
 * name:      run
 * purpose:   runs the MetroSim simulation
 * arguments: none
 * returns:   none
 * effects:   none
 * other:     none
 */
void MetroSim::run() {
    readStations();
    readInput();
}

/*
 * name:      readStations
 * purpose:   creates stations in the simulation using the stations file
 * arguments: none
 * returns:   none
 * effects:   none
 * other:     none
 */
int MetroSim::readStations() {
    std::ifstream inFile(argv[1]);
    if (!inFile.is_open()) {
        std::cerr << "Error: could not open file " << argv[1];
        return EXIT_FAILURE;
    }
    std::string stationName;
    //Goes through file, creating stations and adding them to MetroSim's 
    //station list
    while (std::getline(inFile, stationName)) {
        Station s(maxStationIndex, stationName);
        stationList.push_back(s);
        maxStationIndex++;
    }
    return 0;
}

/*
 * name:      readInput
 * purpose:   reads user input either from given file or the console
 * arguments: none
 * returns:   none
 * effects:   none
 * other:     none
 */
void MetroSim::readInput()
{
    std::ifstream file;
    std::istream *in = &std::cin;
    if (argc > 3) {
        file.open(argv[3]);
        if (!file.is_open()) {
            std::cerr << "Error: could not open file " << argv[3] << std::endl;
            return;
        }
        in = &file;
    }
    runInputLoop(*in);
    std::cout << "Thanks for playing MetroSim. Have a nice day!" << std::endl;
}

/*
 * name:      runInputLoop
 * purpose:   reads user input for each turn
 * arguments: std::istream &in to read input from the user/file
 * returns:   none
 * effects:   none
 * other:     none
 */
void MetroSim::runInputLoop(std::istream &in) {
    std::string line;
    //prints out simulation for the first time
    printCurrentSimulation();
    //loops through each turn asking for user input
    while (true) {
        std::cout << "Command? ";
        if (!std::getline(in, line)) {
            return;
        }
        if (line == "m f") {
            return;
        }
        currentInput(line);
    }
}

/*
 * name:      currentInput
 * purpose:   plays out a turn in the simulation
 * arguments: std::string current representing the current user command
 * returns:   none
 * effects:   none
 * other:     none
 */
void MetroSim::currentInput(std::string current) {
    //makes istringstream instance so can split up current into parts
    std::istringstream iss(current);
    char cmd;
    iss >> cmd;
    if (cmd == 'p') {
        int startStationIndex;
        int endStationIndex;
        //gets start and end station from istringstream instance
        iss >> startStationIndex >> endStationIndex;
        Passenger p(currentPassengerID, startStationIndex, endStationIndex);
        stationList[startStationIndex].addPassenger(p);
        currentPassengerID++;
    }
    //since "m f" case slready covered 'm' is automatically "m m" command
    else if (cmd == 'm') {
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
    printCurrentSimulation();
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

