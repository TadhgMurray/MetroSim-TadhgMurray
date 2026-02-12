/*
 *  Main.cpp
 *  Tadhg Murray (tmurra01)
 *  2/4/26
 *
 *  CS 15 Project 1 metrosim
 *
 *  Train is a class that represents a train in the metro simulation. It
 *  starts empty, and passengers can be inserted/removed based on what station
 *  the train is at. It also supports printing the information of the 
 *  passenges on the train.
 *
 */

#include <iostream>
#include <fstream>
#include <string>

#include "MetroSim.h"

using namespace std;

/*
 * name:      main
 * purpose:   Runs the simulation using the MetroSim class
 * arguments: int argc representing number of commandline arguments,
 * char *argv[] that stores those command line arguments
 * returns:   returnts int 0 once programis finished running
 * effects:   none
 * other:     none
 */
int main(int argc, char *argv[])
{
    MetroSim sim(argc, argv);
    readStations(sim);
    readInput(sim);
    return 0;
}


/*
 * name:      readStations
 * purpose:   creates stations in the simulation using the stations file
 * arguments: none
 * returns:   none
 * effects:   none
 * other:     none
 */
int MetroSim::readStations(MetroSim sim) {
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
        sim.addStation(s);
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
void MetroSim::readInput(MetroSim sim)
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
    runInputLoop(sim, *in);
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
void MetroSim::runInputLoop(MetroSim sim, std::istream &in) {
    std::string line;
    //prints out simulation for the first time
    sim.printCurrentSimulation();
    //loops through each turn asking for user input
    while (true) {
        std::cout << "Command? ";
        if (!std::getline(in, line)) {
            return;
        }
        if (line == "m f") {
            return;
        }
        else if(line[0] == "p") {
            sim.addPassenger(line);
        }
        else if(line == "m m") {
            sim.moveTrain();
        }
        sim.printCurrentSimulation();
    }
}
