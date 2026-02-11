/*
 *
 */

#ifndef _METROSIM_H_
#define _METROSIM_H_

#include "Passenger.h"
#include "Train.h"
#include "Station.h"
#include "PassengerQueue.h"

#include <vector>
// Put any other necessary includes here


class MetroSim
{

public:
    MetroSim(int argc, char *argv[]);
    void run();
    ~MetroSim();    
private:
    // Put any other structs you need here
    int readStations();
    void readInput();
    void runInputLoop(std::istream &in);
    void currentInput(std::string current);
    void printCurrentSimulation();
    std::vector <Station> stationList;
    Train train1;
    int currentPassengerID;
    int currentStationIndex;
    int maxStationIndex;
    std::ofstream outputFile;
    int argc;
    char **argv;
};

#endif
