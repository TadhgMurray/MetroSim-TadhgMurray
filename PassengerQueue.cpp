/*
 *  PassengerQueue.cpp
 *  Tadhg Murray(tmurra01)
 *  2/4/26
 *
 *  CS 15 Project 1 metrosim
 *
 *  This file contains an implementation of the PassengerQueue class.
 *
 */
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "PassengerQueue.h"

/*
 * name:      front
 * purpose:   returns the front passenger
 * arguments: none
 * returns:   returns the first Passenger in the queue
 * effects:   none
 * other:     none
 */
Passenger PassengerQueue::front() {
    return passengerQueue[0];
}

/*
 * name:      dequeue
 * purpose:   removes the first passenger from the queue
 * arguments: none
 * returns:   none
 * effects:   none
 * other:     none
 */
void PassengerQueue::dequeue() {
    passengerQueue.erase(passengerQueue.begin());
}

/*
 * name:      enqueue
 * purpose:   adds a passenger to the end of the queue
 * arguments: const Passenger reference passenger representing a passenger
 * to add to the queue
 * returns:   nothing
 * effects:   none
 * other:     none
 */
void PassengerQueue::enqueue(const Passenger &passenger) {
    passengerQueue.push_back(passenger);
}

/*
 * name:      size
 * purpose:   returns the size of the PassengerQueue
 * arguments: none
 * returns:   int size of the PassengerQueue
 * effects:   none
 * other:     none
 */
int PassengerQueue::size() {
    return passengerQueue.size();
}

/*
 * name:      print
 * purpose:   prints all passengers in the queue in order from front to back
 * arguments: std::ostream &output — the output stream to write to
 * returns:   nothing
 * effects:   none
 * other:     none
 */
void PassengerQueue::print(std::ostream &output) {
    for (int i = 0; i < size(); i++) {
        passengerQueue[i].print(output);
    }
}