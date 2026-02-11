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

#include "Train.h"

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
    //PassengerQueue to store correct order(end station) of passengers to put 
    //back into train's PassengerQueue
    PassengerQueue correctOrder;
    //stores what the size of the train's PassengerQueue should be after 
    //unloading
    int passengersLeft = trainPassengers.size();
    int i = 0;
    //traverses through PassengerQueue unloading Passengers and keeping
    //non-unloaded Passeers in a different PassengerQueue for storage
    while (i < passengersLeft) {
        Passenger p = trainPassengers.front();
        if (p.getEndingStation() == s.getStationNumber()) {
            log << "Passenger " << p.getId();
            log << " left train at station " << s.getStationName() << "\n";
            trainPassengers.dequeue();
            passengersLeft--;
        } 
        else {
            correctOrder.enqueue(p);
            trainPassengers.dequeue();
            i++;
        }
    }
    sortPassengerQueue(correctOrder);
}

/*
 * name:      sortPassengerQueue
 * purpose:   sorts the train's PassengerQueue by endStation(lowest to highest)
 * arguments: PassengerQueue correctOrder to reorder the train's PassengerQueue
 * returns:   nothing
 * effects:   none
 * other:     none
 */
void Train::sortPassengerQueue(PassengerQueue correctOrder) {
    //2nd PassengerQueue to store original PassengerQueue without restored
    //passengers
    PassengerQueue correctOrder2;
    //reads passengers to train's PassengerQueue in correct order(end station)
    while (correctOrder.size() > 0) {
        int lowestEndStation = getLowestStation(correctOrder);
        //finds passenger at lowest station index and adds it to 
        //trainPassengers, stores rest of Passengers in second PassengerQueue
        while (correctOrder.size() > 0) {
            if (correctOrder.front().getEndingStation() == lowestEndStation) {
                trainPassengers.enqueue(correctOrder.front());
            } 
            else {
                correctOrder2.enqueue(correctOrder.front());
            }
            correctOrder.dequeue();
        }
        //restore remaining for next traversal
        while (correctOrder2.size() > 0) {
            correctOrder.enqueue(correctOrder2.front());
            correctOrder2.dequeue();
        }
    }
}

/*
 * name:      getLowestStation
 * purpose:   gets the lowest station index in a PassengerQueue
 * arguments: PassengerQueue pq to find lowest station index in
 * returns:   nothing
 * effects:   none
 * other:     none
 */
int Train::getLowestStation(PassengerQueue pq) {
    if (pq.size() == 0) {
        return -1;
    }
    int lowestEndStation = pq.front().getEndingStation();
    pq.dequeue();
    while (pq.size() > 0) {
        if (pq.front().getEndingStation() < lowestEndStation) {
            lowestEndStation = pq.front().getEndingStation();
        }
        pq.dequeue();
    }
    return lowestEndStation;
}

/*
 * name:      unloadPassengers
 * purpose:   unloads Passengers at the new station
 * arguments: Station s to load Passengers from its queue
 * returns:   nothing
 * effects:   none
 * other:     none
 */
void Train::loadPassengers(Station s) {
    int n = s.getQueueSize();
    for (int i = 0; i < n; i++) {
        Passenger p = s.getFirstPassenger();
        trainPassengers.enqueue(p);
        s.dequeue();
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
    trainPassengers.print(output); 
    output << "}" << std::endl;
}
