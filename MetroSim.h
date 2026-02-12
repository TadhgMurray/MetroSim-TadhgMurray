/*
 *  MetroSim.h
 *  Tadhg Murray (tmurra01)
 *  2/4/26
 *
 *  CS 15 Project 1 metrosim
 *
 *  MetroSim is a class that simulates a metro line. It takes in commands and
 *  runs them in the simulation, controlling a train and the stations on the
 *  line. It can add passengers to the station, move the train, and print
 *  the current state of the simulation.
 *
 */

#ifndef _METROSIM_H_
#define _METROSIM_H_

#include "Passenger.h"
#include "Train.h"
#include "Station.h"
#include "PassengerQueue.h"

#include <vector>


class MetroSim
{

public:
    MetroSim(int argc, char *argv[]);
    void addStation(Station s);
    void addPassenger(std::string current);
    void moveTrain();
    void printCurrentSimulation();
    ~MetroSim();    
private:
    std::vector <Station> stationList;
    Train train1;
    int currentPassengerID;
    int currentStationIndex;
    int maxStationIndex;
    std::ofstream outputFile;
};

#endif
