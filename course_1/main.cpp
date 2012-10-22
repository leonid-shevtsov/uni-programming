#include "passenger_structures.h"
#include "passenger_input.h"
#include "passenger_logic.h"

#include <stdlib.h>
#include <stdio.h>

// Prints information about this application's usage
void printBanner() {
  printf("Not enough arguments\nUsage: passengers [input_filename] [output_filename]\n");
}

// (in) filename: name of file to read
// (out) passengers: pointer to a pointer that will store the resulting array
// (out) passengers_size: point to an integer variable that will store the array's size
void readData(const char* filename, Passenger** passengers, int* passengers_size) {
  FILE* input_file = fopen(filename, "r");
  *passengers = readPassengerFile(input_file, passengers_size);
  fclose(input_file);
}

// (in) filename: name of file to write
// (in) max_passenger: passenger with max items (as per assignment)
// (in) max_flight: flight with max weight (as per assignment)
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
    freePassengers(passengers);
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