/*
 *  Main.cpp
 *  Tadhg Murray (tmurra01)
 *  2/4/26
 *
 *  CS 15 Project 1 metrosim
 *
 *  This file is the main file for the program. It reads in the files/commands
 *  from the console and creates a MetroSim object to simulate the metro
 *  using those read files/commands.
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "MetroSim.h"

using namespace std;

int readStations(MetroSim *sim, char *argv[]);
int readInput(MetroSim *sim, int argc, char *argv[]);
void runInputLoop(MetroSim *sim, std::istream &in, std::ostream &out);

/*
 * name:      main
 * purpose:   Runs the simulation, reading the files/commands
 * arguments: int argc representing number of commandline arguments,
 * char *argv[] that stores those command line arguments
 * returns:   returnts int 0 once program is finished running
 * effects:   none
 * other:     none
 */
int main(int argc, char *argv[])
{
    MetroSim sim;
    if (readStations(&sim, argv) != 0) {
        return EXIT_FAILURE;
    }
    if (readInput(&sim, argc, argv) != 0) {
        return EXIT_FAILURE;
    }
    return 0;
}


/*
 * name:      readStations
 * purpose:   creates stations in the simulation using the stations file
 * arguments: MetroSim *sim to add station to, char *argv[] to read stations
 * from file
 * returns:   returns error if it cannot open file
 * effects:   none
 * other:     none
 */
int readStations(MetroSim *sim, char *argv[]) {
    std::ifstream inFile(argv[1]);
    if (not inFile.is_open()) {
        std::cerr << "Error: could not open file " << argv[1] << std::endl;
        return EXIT_FAILURE;
    }
    std::string stationName;
    //Goes through file, creating stations and adding them to MetroSim's 
    //station list
    while (std::getline(inFile, stationName)) {
        Station s(sim->getMaxStationIndex(), stationName);
        sim->addStation(s);
    }
    return 0;
}

/*
 * name:      readInput
 * purpose:   reads user input either from given file or the console
 * arguments: MetroSim *sim to run the inputs, int argc to check if commands
 * from console or file, char *argv[] to read commands from file if given
 * returns:   returns error if it cannot open file
 * effects:   none
 * other:     none
 */
int readInput(MetroSim *sim, int argc, char *argv[]) {
    std::ofstream outFile(argv[2]);
    if (not outFile.is_open()) {
        std::cerr << "Error: could not open file " << argv[2] << std::endl;
        return EXIT_FAILURE;
    }
    std::ifstream file;
    std::istream *in = &std::cin;
    if (argc > 3) {
        file.open(argv[3]);
        if (not file.is_open()) {
            std::cerr << "Error: could not open file " << argv[3] << std::endl;
            return EXIT_FAILURE;
        }
        in = &file;
    }
    runInputLoop(sim, *in, outFile);
    std::cout << "Thanks for playing MetroSim. Have a nice day!" << std::endl;
    return 0;
}

/*
 * name:      runInputLoop
 * purpose:   reads user input for each turn
 * arguments: MetroSim *sim to run the commands,
 * std::istream &in to read input from the user/file, stdLLostream &out
 * to write output into
 * returns:   none
 * effects:   none
 * other:     none
 */
void runInputLoop(MetroSim *sim, std::istream &in, std::ostream &out) {
    std::string line;
    //prints out simulation for the first time
    sim->printCurrentSimulation();
    //loops through each turn asking for user input
    while (true) {
        std::cout << "Command? ";
        if (not std::getline(in, line)) {
            return;
        }
        if (line == "m f") {
            return;
        }
        else if(line[0] == 'p') {
            sim->addPassenger(line);
        }
        else if(line == "m m") {
            std::ostringstream exit;
            sim->moveTrain(out);
        }
        sim->printCurrentSimulation();
    }
}
