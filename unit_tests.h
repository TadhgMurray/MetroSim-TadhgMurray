/*
 *  unit_tests.h
 *  Tadhg Murray(tmurra01)
 *  1/26/26
 *
 *  CS 15 Project 1 metrosim
 *
 *  Uses Matt Russell's unit_test framework to test the Passenger class.
 *
 */

#include <cassert>
#include <iostream>
#include <sstream>
#include <string>

#include "Passenger.h"
#include "PassengerQueue.h"
#include "Station.cpp"
#include "Train.cpp"
#include "MetroSim.cpp"

//tests print() from the Passenger class
void pPrintTest1() {
    Passenger p(0, 0, 1);
    std::ostringstream out;
    p.print(out);
    assert(out.str() == "[0, 0->1]");
}

//tests enqueue() from the PassengerQueue class one time
void pqEnqueueTest() {
    PassengerQueue pq;
    Passenger p(0, 0, 1);
    pq.enqueue(p);
    std::ostringstream out;
    pq.print(out);
    assert(out.str() == "[0, 0->1]");
}

//tests enqueue() from PassengerQueue multiple times
void pqEnqueueMultipleTimesTest() {
    PassengerQueue pq;
    Passenger p1(0, 0, 1);
    Passenger p2(1, 0, 1);
    Passenger p3(2, 0, 1);
    Passenger p4(3, 0, 1);
    Passenger p5(4, 0, 1);
    pq.enqueue(p1);
    pq.enqueue(p2);
    pq.enqueue(p3);
    pq.enqueue(p4);
    pq.enqueue(p5);
    std::ostringstream out;
    pq.print(out);
    assert(out.str() == "[0, 0->1][1, 0->1][2, 0->1][3, 0->1][4, 0->1]");
}

//tests enqueue() from the PassengerQueue class multiple times using 
//the same passenger
void pqEnqueueSamePassenger() {
    PassengerQueue pq;
    Passenger p(0, 0, 1);
    pq.enqueue(p);
    pq.enqueue(p);
    std::ostringstream out;
    pq.print(out);
    assert(out.str() == "[0, 0->1][0, 0->1]");
}

//tests enqueue() then dequeue() from the PassengerQueue class
void pqEnqueueDequeueTest() {
    PassengerQueue pq;
    Passenger p(0, 0, 1);
    pq.enqueue(p);
    pq.dequeue();
    std::ostringstream out;
    pq.print(out);
    assert(out.str() == "");
}

//tests enqueue() then dequeue() from the PassengerQueue class multiple times
void pqEnqueueDequeue100TimesTest() {
    PassengerQueue pq;
    Passenger p(0, 0, 1);
    for (int i = 0; i < 100; i++) {
        pq.enqueue(p);
    }
    for (int i = 0; i < 100; i++) {
        pq.dequeue();
    }
    std::ostringstream out;
    pq.print(out);
    assert(out.str() == "");
}

//tests front() from the PassengerQueue class
void pqFrontTest() {
    PassengerQueue pq;
    Passenger p(0, 0, 1);
    pq.enqueue(p);
    //can't directly compare objects so compare information
    assert(pq.front().getId() == p.getId());
    assert(pq.front().getStartingStation() == p.getStartingStation());
    assert(pq.front().getEndingStation() == p.getEndingStation());
}

//tests size() from the PassengerQueue class on a size one queue
void pqSizeTest() {
    PassengerQueue pq;
    Passenger p(0, 0, 1);
    pq.enqueue(p);
    assert(pq.size() == 1);
}

//tests size() from the PassengerQueue class on a size 100 queue
void pqSizeTest100() {
    PassengerQueue pq;
    Passenger p(0, 0, 1);
    for (int i = 0; i < 100; i++) {
        pq.enqueue(p);
    }
    assert(pq.size() == 100);
}

//tests size() from the PassengerQueue class on a queue that was enqueued 
//and then dequeued
void pqEnqueueDequeueSizeTest() {
    PassengerQueue pq;
    Passenger p(0, 0, 1);
    pq.enqueue(p);
    pq.dequeue();
    assert(pq.size() == 0);
}

//tests size() from the PassengerQueue class on an empty queue
void pqSizeEmptyTest() {
    PassengerQueue pq;
    assert(pq.size() == 0);
}

//tests print() from the PassengerQueue class on a 2 size queue
void pqPrintTest() {
    PassengerQueue pq;
    Passenger p1(0, 0, 1);
    Passenger p2(1, 0, 1);
    pq.enqueue(p1);
    pq.enqueue(p2);
    std::ostringstream out;
    pq.print(out);
    assert(out.str() == "[0, 0->1][1, 0->1]");
}

//tests the station constructor
void stationCreationTest() {
    Station s(1, "hello");
}

//tests getStationNumber()
void stationGetStationNumberTest() {
    Station s(1, "hello");
    assert(s.getStationNumber() == 1);
}

//tests getStationName()
void stationGetStationNameTest() {
    Station s(1, "hello");
    assert(s.getStationName() == "hello");
}

//tests getQueueSize() on an empty station
void stationGetQueueEmptyTest() {
    Station s(1, "hello");
    assert(s.getQueueSize() == 0);
}

//tests getQueueSize() on a one passenger queue station
void stationGetQueueSize1Test() {
    Station s(1, "hello");
    Passenger p(0, 0, 1);
    s.addPassenger(p);
    assert(s.getQueueSize() == 1);
}

//tests getQueueSize() on a 100 passenger queue station
void stationGetQueueSize100Test() {
    Station s(1, "hello");
    Passenger p(0, 0, 1);
    for (int i = 0; i < 100; i++) {
        s.addPassenger(p);
    }
    assert(s.getQueueSize() == 100);
}

//tests erasePassengers() on an empty station
void erasePassengersEmptyTest() {
    Station s(1, "hello");
    s.erasePassengers();
    assert(s.getQueueSize() == 0);
}

//tests erasePassengers() on a one passenger queue station
void erasePassengersOnePassengersTest() {
    Station s(1, "hello");
    Passenger p(0, 0, 1);
    s.addPassenger(p);
    s.erasePassengers();
    assert(s.getQueueSize() == 0);
}

//tests erasePassengers() on a 100 passenger queue station
void erasePassengers100PassengersTest() {
    Station s(1, "hello");
    Passenger p(0, 0, 1);
    for (int i = 0; i < 100; i++) {
        s.addPassenger(p);
    }
    s.erasePassengers();
    assert(s.getQueueSize() == 0);
}

//tests dequeue() on a one passenger queue station
void stationDequeueOnePassengerTest() {
    Station s(1, "hello");
    Passenger p(0, 0, 1);
    s.addPassenger(p);
    s.dequeue();
    assert(s.getQueueSize() == 0);
}

//tests dequeue() once on a two passenger queue station
void stationDequeueTwoPassengerTest() {
    Station s(1, "hello");
    Passenger p(0, 0, 1);
    s.addPassenger(p);
    s.addPassenger(p);
    s.dequeue();
    assert(s.getQueueSize() == 1);
}

//tests addPassenger() then dequeue() 100 times station
void stationDequeue100PassengerTest() {
    Station s(1, "hello");
    Passenger p(0, 0, 1);
    for (int i = 0; i < 100; i++) {
        s.addPassenger(p);
    }
    for (int i = 0; i < 100; i++) {
        s.dequeue();
    }
    assert(s.getQueueSize() == 0);
}

//tests getFirstPassenger() on a one passenger queue station
void stationGetFirstPassengerTest() {
    Station s(1, "hello");
    Passenger p(0, 0, 1);
    s.addPassenger(p);
    assert(s.getFirstPassenger().getId() == p.getId());
    assert(s.getFirstPassenger().getEndingStation() == p.getEndingStation());
    assert(s.getFirstPassenger().getStartingStation() == p.getStartingStation());
}

//tests getFirstPassenger() on a 100 passenger queue station
void stationGetFirstPassenger100PassengerTest() {
    Station s(1, "hello");
    Passenger p(0, 0, 1);
    for (int i = 0; i < 100; i++) {
        s.addPassenger(p);
    }
    assert(s.getFirstPassenger().getId() == p.getId());
    assert(s.getFirstPassenger().getEndingStation() == p.getEndingStation());
    assert(s.getFirstPassenger().getStartingStation() == p.getStartingStation());
}

//tests getFirstPassenger() on a 100 passenger queue station on all passengers
void stationGetFirstPassenger100PassengerAllPassengersTest() {
    Station s(1, "hello");
    Passenger p(0, 0, 1);
    for (int i = 0; i < 100; i++) {
        s.addPassenger(p);
    }
    for (int i = 0; i < 100; i++) {
        assert(s.getFirstPassenger().getId() == p.getId());
        assert(s.getFirstPassenger().getEndingStation() == p.getEndingStation());
        assert(s.getFirstPassenger().getStartingStation() == p.getStartingStation());
        s.dequeue();
    }
}

//tests print() on an empty passenger queue station
void stationPrintEmptyPassengerTest() {
    Station s(1, "hello");
    std::ostringstream out;
    s.print(out);
    assert(out.str() == "[1] hello {}\n");
}

//tests print() on a 1 passenger queue station
void stationPrintOnePassengerTest() {
    Station s(1, "hello");
    Passenger p(0, 0, 1);
    s.addPassenger(p);
    std::ostringstream out;
    s.print(out);
    assert(out.str() == "[1] hello {[0, 0->1]}\n");
}

//tests print() on a 100 passenger queue station
void stationPrint100PassengerTest() {
    Station s(1, "hello");
    Passenger p(0, 0, 1);
    std::string passengersPrint = "[1] hello {";
    for (int i = 0; i < 100; i++) {
        s.addPassenger(p);
        passengersPrint += "[0, 0->1]";
    }
    passengersPrint += "}\n";
    std::ostringstream out;
    s.print(out);
    assert(out.str() == passengersPrint);
}

//tests loadPassengers() with an empty station
void trainPrintEmptyTest() {
    Train t;
    std::ostringstream out;
    t.print(out);
    assert(out.str() == "Passengers on the train: {}\n");
}

//tests loadPassengers() with an empty station
void trainLoadPassengersEmptyTest() {
    Train t;
    Station s(1, "hello");
    std::ostringstream out;
    t.loadPassengers(s);
    t.print(out);
    assert(out.str() == "Passengers on the train: {}\n");
}

//tests loadPassengers() with a one passenger station
void trainLoadPassengersOnePassengerTest() {
    Train t;
    Station s(1, "hello");
    Passenger p(0, 0, 1);
    s.addPassenger(p);
    t.loadPassengers(s);
    std::ostringstream out;
    t.print(out);
    assert(out.str() == "Passengers on the train: {[0, 0->1]}\n");
}


//tests loadPassengers() with a 100 passenger station
void trainLoadPassengers100PassengersTest() {
    Train t;
    Station s(1, "hello");
    Passenger p(0, 0, 1);
    std::string trainPrint = "Passengers on the train: {";
    for (int i = 0; i < 100; i++) {
        s.addPassenger(p);
        trainPrint += "[0, 0->1]";
    }
    t.loadPassengers(s);
    trainPrint += "}\n";
    std::ostringstream out;
    t.print(out);
    assert(out.str() == trainPrint);
}

//tests unloadPassengers() on an empty train
void trainUnloadEmptyTrain() {
    Train t;
    Station s(1, "hello");
    std::ostringstream exit;
    t.unloadPassengers(s, exit);
    std::ostringstream out;
    t.print(out);
    assert(out.str() == "Passengers on the train: {}\n");
    assert(exit.str() == "");
}

//tests unloadPassengers() on an empty train
void trainUnloadOnePassengerTrain() {
    Station s(1, "hello");
    Passenger p(0, 0, 1);
    Train t;
    s.addPassenger(p);
    std::ostringstream exit;
    t.loadPassengers(s);
    t.unloadPassengers(s, exit);
    std::ostringstream out;
    t.print(out);
    assert(out.str() == "Passengers on the train: {}\n");
    assert(exit.str() == "Passenger 0 left train at station hello\n");
}

//tests unloadPassengers() on an empty train
void trainUnload100PassengerTrain() {
    Train t;
    Station s(1, "hello");
    Passenger p(0, 0, 1);
    std::string exitOutput;
    for (int i = 0; i < 100; i++) {
        s.addPassenger(p);
        exitOutput += "Passenger 0 left train at station hello\n";
    }
    t.loadPassengers(s);
    std::ostringstream exit;
    t.unloadPassengers(s, exit);
    std::ostringstream out;
    t.print(out);
    assert(out.str() == "Passengers on the train: {}\n");
    assert(exit.str() == exitOutput);
}

//tests the MetroSim class using run()
void metroSimRunTest() {
    char arg0[] = "stations.txt";
    char arg1[] = "outputFile";
    char arg2[] = "test_commands.txt";
    char* fakeArgv[] = {arg0, arg1, arg2};
    MetroSim sim(3, fakeArgv);
    sim.run();
}
