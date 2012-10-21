#include "passenger_structures.h"
#include "passenger_input.h"
#include "passenger_logic.h"

#include <stdlib.h>
#include <stdio.h>

int main(int argc, const char** argv) {
  if (argc < 3) {
    printf("Not enough arguments\nUsage: passengers [input_filename] [output_filename]\n");
    return -1;
  }

  FILE* input_file = fopen(argv[1], "r");
  int passengers_size = 0, flights_size=0;
  Passenger* passengers = readPassengerFile(input_file, &passengers_size);
  fclose(input_file);

  Flight* flights = mapFlights(passengers, passengers_size, &flights_size);

  Flight* maxFlight = flightWithMaxWeight(flights, flights_size);

  FILE* output_file = fopen(argv[2], "w");
  printFlight(output_file, maxFlight);
  fclose(output_file);

  freeFlights(flights, flights_size);
  freePassengers(passengers, passengers_size);
  return 0;
}