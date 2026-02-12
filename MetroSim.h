/*
 *  MetroSim.h
 *  Tadhg Murray (tmurra01)
 *  2/4/26
 *
 *  CS 15 Project 1 metrosim
 *
 *  MetroSim is a class that simulates a metro line. It can run this simulation
 *  using two text files for stations and output, and a way for the user to
 *  input commands. MetroSim is able to move trains and deal with unloading/
 *  loading passengers. It can also add passengers to Stations.
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
    int argc;
    char **argv;
};

#endif
