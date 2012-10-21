#ifndef __PASSENGER_INPUT_H__
#define __PASSENGER_INPUT_H__

#include <stdio.h>
#include "passenger_structures.h"

Passenger* readPassengerFile(FILE* input_file, int* size);
int readPassenger(FILE* input_file, Passenger* passenger);

#endif