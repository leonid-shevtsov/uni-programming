#ifndef __PASSENGER_STRUCTURES_H__
#define __PASSENGER_STRUCTURES_H__

typedef struct {
  char* first_name;
  char* last_name;
} Name;

typedef struct {
  Name name;
  char* flight_no;
  int items_count;
  int total_weight;
} Passenger;

typedef struct {
  const char* flight_no;
  int passenger_count;
  Passenger** passengers;
} Flight;

void freeFlights(Flight* flights, const int size);
void freePassengers(Passenger* passengers, const int size);

#endif