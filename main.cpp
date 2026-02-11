/*
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
    sim.run();
    return 0;
}
