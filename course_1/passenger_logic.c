#include <stdlib.h>
#include <string.h>
#include "passenger_logic.h"

Flight* mapFlights(Passenger* passengers, const int size, int *flights_size) {
  // Yep, not very effective. But this is the max possible number of flights
  Flight* flights = malloc(sizeof(Flight)*size);
  *flights_size = 0;
  int i, j;

  for (i=0; i < size; ++i) {
    for (j=0; j < *flights_size; ++j) {
      if (strcmp(passengers[i].flight_no, flights[j].flight_no)==0) {
        break;
      }
    }
    if (j == *flights_size) { // didn't find a flight in the map; initialize new
      flights[j].flight_no = passengers[i].flight_no;
      flights[j].passenger_count= 0;
      flights[j].passengers = malloc(sizeof(Passenger*)*size); // also not very effective
      (*flights_size)++;
    }
    flights[j].passengers[flights[j].passenger_count++] = passengers+i;
  }

  return flights;
}

int weightOfFlight(Flight* flight) {
  int i, weight = 0;

  for (i=0; i < flight->passenger_count; ++i) {
    weight += flight->passengers[i]->total_weight;
  }

  return weight;
}

Flight* flightWithMaxWeight(Flight* flights, const int size) {
  int i, max_weight = 0;
  Flight* max_flight = NULL;

  for (i=0; i < size; ++i) {
    int flight_weight = weightOfFlight(flights+i);
    if (flight_weight > max_weight) {
      max_weight = flight_weight;
      max_flight = flights + i;
    }
  }

  return max_flight;
}

Passenger* passengerWithMaxItems(Passenger* passengers, const int size) {
  int i, max_count = 0;
  Passenger *max_passenger = NULL;

  for (i=0; i < size; ++i) {
    if (passengers[i].items_count > max_count) {
      max_count = passengers[i].items_count;
      max_passenger = passengers + i;
    }
  }

  return max_passenger;
}

void printFlight(FILE* output_file, Flight* flight) {
  int i;

  fprintf(output_file, "Flight information for flight no. %s\n", flight->flight_no);
  fprintf(output_file, "Total weight: %i\n", weightOfFlight(flight));
  fprintf(output_file, "List of passengers\n%20s | %10s\n", "Name", "B. weight");

  for (i=0; i < flight->passenger_count; ++i) {
    char* full_name = malloc(strlen(flight->passengers[i]->name.first_name) + strlen(flight->passengers[i]->name.last_name) + 2);
    strcpy(full_name, flight->passengers[i]->name.first_name);
    strcat(full_name, " ");
    strcat(full_name, flight->passengers[i]->name.last_name);
    fprintf(output_file, "%20s | %10i\n", full_name, flight->passengers[i]->total_weight);
    free(full_name);
  }
}
