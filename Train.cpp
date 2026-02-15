/*
 *  Train.cpp
 *  Tadhg Murray(tmurra01)
 *  2/4/26
 *
 *  CS 15 Project 1 metrosim
 *
 *  This file contains an implementation of the Train class.
 *
 */
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

#include "Train.h"

/*
 * name:      Train
 * purpose:   creates a Train object
 * arguments: int numStations for size of PassengerQueue vector
 * returns:   none
 * effects:   none
 * other:     none
 */
Train::Train(int numStations) {
    trainPassengers.resize(numStations);
}

/*
 * name:      unloadPassengers
 * purpose:   unloads Passengers who have reached their ending station
 * arguments: const Station &s of the station at which passengers will be
 * unloaded, std::ostream &log representing the output stream where messages 
 * about passenger movements will be written
 * returns:   none
 * effects:   deletes unloaded Passengers
 * other:     none
 */
void Train::unloadPassengers(const Station &s, std::ostream &log) {
    int stationIndex = s.getStationNumber();
    PassengerQueue &q = trainPassengers[stationIndex];
    int n = q.size();
    for (int i = 0; i < n; i++) {
        Passenger p = q.front();
        q.dequeue();
        log << "Passenger " << p.getId();
        log << " left train at station " << s.getStationName() << "\n";
    }
}

/*
 * name:      compareById
 * purpose:   compares two Passengers by their ID for sorting
 * arguments: Passenger& p0 and Passenger& p1 to compare id indexes
 * returns:   true if p0's ID is greater than p1's ID, false otherwise
 * effects:   none
 * other:     none
 */
bool Train::compareById(Passenger& p0, Passenger& p1) {
    return p0.getId() > p1.getId();
}

/*
 * name:      loadPassengers
 * purpose:   loads Passengers at the new station
 * arguments: Station s to load Passengers from its queue
 * returns:   nothing
 * effects:   none
 * other:     none
 */
void Train::loadPassengers(Station &s) {
    int n = s.getQueueSize();
    for (int i = 0; i < n; i++) {
        Passenger p = s.getFirstPassenger();
        s.dequeue();
        trainPassengers[p.getEndingStation()].enqueue(p);
    }
    // Sort each queue by ascending ID
    for (auto &queue : trainPassengers) {
        if (queue.size() <= 1) {
            continue;
        }
        std::vector<Passenger> temp;\
        //adds passengers to tep vector to sort
        while (queue.size() > 0) {
            temp.push_back(queue.front());
            queue.dequeue();
        }
        //uses vector sort operation to sort each endStation passengers by ID
        std::sort(temp.begin(), temp.end(), [](Passenger &a, Passenger &b) {
            return a.getId() < b.getId();
        });
        //returns passengers to queue in correct order
        for (auto &p : temp) {
            queue.enqueue(p);
        }
    }
}

/*
 * name:      print
 * purpose:   prints information about all passengers currently on the train
 * arguments: std::ostream &output — the output stream to write to
 * returns:   nothing
 * effects:   none
 * other:     nothing
 */
void Train::print(std::ostream &output) {
    output << "Passengers on the train: {";
    for (int i = 0; i < trainPassengers.size(); i++) {
        trainPassengers[i].print(output);
    } 
    output << "}" << std::endl;
}

/*
 * name:      ~Train
 * purpose:   clears train's PassengerQueues
 * arguments: none
 * returns:   nothing
 * effects:   none
 * other:     nothing
 */
Train::~Train() {
    // Clear all queues
    for (size_t i = 0; i < trainPassengers.size(); i++) {
        while (trainPassengers[i].size() > 0) {
            trainPassengers[i].dequeue();
        }
    }
}
