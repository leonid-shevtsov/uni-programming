#include "passenger_structures.h"
#include "passenger_input.h"
#include "passenger_logic.h"

#include <stdlib.h>
#include <stdio.h>

void printBanner() {
  printf("Not enough arguments\nUsage: passengers [input_filename] [output_filename]\n");
}

void readData(const char* filename, Passenger** passengers, int* passengers_size) {
  FILE* input_file = fopen(filename, "r");
  *passengers = readPassengerFile(input_file, passengers_size);
  fclose(input_file);
}

void printResults(const char* filename, Passenger* max_passenger, Flight* max_flight) {
  FILE* output_file = fopen(filename, "w");
  fprintf(output_file, "Passenger with max items: %s %s (%i items)\n", max_passenger->name.first_name, max_passenger->name.last_name, max_passenger->items_count);
  fprintf(output_file, "Flight with maximum weight: %s\n", max_flight->flight_no);
  printFlight(output_file, max_flight);
  fclose(output_file);
}

int main(int argc, const char** argv) {
  // Initialization
  if (argc < 3) {
    printBanner();
    return -1;
  }

  Passenger *passengers = NULL, *max_passenger = NULL;
  Flight *flights = NULL, *max_flight = NULL;
  int passengers_size = 0, flights_size = 0;

  readData(argv[1], &passengers, &passengers_size);

  // Error handling
  if (passengers == NULL) {
    printf("Incorrect passenger file format.\n");
    return -1;
  }
  if (passengers_size == 0) {
    printf("Passenger file must contain at least one record.\n");
    return -1;
  }

  // Core logic
  max_passenger = passengerWithMaxItems(passengers, passengers_size);
  flights = mapFlights(passengers, passengers_size, &flights_size);
  max_flight = flightWithMaxWeight(flights, flights_size);

  // Output
  printResults(argv[2], max_passenger, max_flight);

  // Finalization
  freeFlights(flights, flights_size);
  freePassengers(passengers, passengers_size);
  return 0;
}