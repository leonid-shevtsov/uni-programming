#include <stdlib.h>
#include "passenger_structures.h"

void freeFlights(Flight* flights, const int size) {
  int i;
  for (i=0; i < size; ++i) {
    free(flights[i].passengers);
  }
  free(flights);
}

void freePassengers(Passenger* passengers, const int size) {
  int i;
  for (i=0; i < size; ++i) {
    free(passengers[i].name.first_name);
    free(passengers[i].name.last_name);
    free(passengers[i].flight_no);
  }
  free(passengers);
}