#ifndef __PASSENGER_INPUT_H__
#define __PASSENGER_INPUT_H__

#include <stdio.h>
#include "passenger_structures.h"

// Reads a list of passengers from a file
// (in) input_file: file to read
// (out) size: size of the resulting passenger list
// returns: pointer to the passenger list
Passenger* readPassengerFile(FILE* input_file, int* size);

// Reads a single passenger from a file
// (in) input_file: file to read
// (out) passenger: passenger to write information to
int readPassenger(FILE* input_file, Passenger* passenger);

#endif