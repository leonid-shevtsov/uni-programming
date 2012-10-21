#ifndef __PASSENGER_LOGIC_H__
#define __PASSENGER_LOGIC_H__

#include <stdio.h>
#include "passenger_structures.h"

Flight* mapFlights(Passenger* passengers, const int size, int *flights_size);
Flight* flightWithMaxWeight(Flight* flights, const int size);
Passenger* passengerWithMaxItems(Passenger* passengers, const int size);
void printFlight(FILE* output_file, Flight* flight);

#endif