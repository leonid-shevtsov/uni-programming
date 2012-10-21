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

#endif