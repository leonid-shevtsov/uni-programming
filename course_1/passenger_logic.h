#ifndef __PASSENGER_LOGIC_H__
#define __PASSENGER_LOGIC_H__

#include <stdio.h>
#include "passenger_structures.h"

// Produce a map of flight no => flight passengers for the given passenger list
// (in) passengers: the passenger list
// (in) size: size of the list
// (out) flights_size: size of the resulting flight map
// returns: the resulting flight map
Flight* mapFlights(Passenger* passengers, const int size, int *flights_size);

// (in) flights: the flight map
// (in) size: size of the flight map
// returns: flight with maximum weight
Flight* flightWithMaxWeight(Flight* flights, const int size);

// (in) passengers: the passenger list
// (in) size: size of the passenger list
// returns: passenger with maximum items
Passenger* passengerWithMaxItems(Passenger* passengers, const int size);

// Prints information about a flight (its name, weight, and a list of passengers)
// (in) output_file: file to write
// (in) flight: flight to write
void printFlight(FILE* output_file, Flight* flight);

#endif