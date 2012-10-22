#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "passenger_structures.h"
#include "passenger_input.h"

// Helper function to read integer with proper error handling
int readInt(FILE* file, int *i) {
  char buffer[100];
  char *ptr;
  if (fgets(buffer, sizeof(buffer), file) != NULL) {
    (*i) = strtol(buffer, &ptr, 10);
    return buffer[0] != '\n' && (*ptr == '\n' || *ptr == '\0');
  } else {
    return 0;
  }
}

int readLine(FILE* file, char** line) {
  char buffer[100];
  if (fgets(buffer, sizeof(buffer), file) != NULL) {
    // Trim trailing newline & spaces
    int buf_len = strlen(buffer)-1;
    while(buf_len>0 && isspace(buffer[buf_len])) buf_len--;
    buffer[buf_len+1] = 0;
    (*line) = new char[buf_len+1];
    strcpy((*line), buffer);
    return 1;
  } else {
    return  0;
  }
}

int readName(FILE* file, Name* name) {
  return readLine(file, &name->first_name) && readLine(file, &name->last_name);
}

// TODO while it would be nice to provide custom error messages,
// this functionality is out of scope of this coursework
int validatePassenger(Passenger* passenger) {
  return
    (strlen(passenger->name.first_name) > 0) &&
    (strlen(passenger->name.last_name) > 0) &&
    (strlen(passenger->flight_no) > 0) &&
    (passenger->total_weight >= 0) &&
    (passenger->items_count >= 0);
}

Passenger* readPassengerFile(FILE* input_file, int* size) {
  if (!readInt(input_file, size)) {
    return NULL; // bad file format
  }
  if ((*size)<0) {
    return NULL;
  }
  Passenger* passengers = new Passenger[*size];
  int i;
  for (i=0; i<(*size); ++i) {
    if (!readPassenger(input_file, passengers+i)) {
      // FIXME there is a known memory leak of already allocated strings in the last Passenger instance
      // Fix omitted here for clarity
      freePassengers(passengers, i);
      return NULL;
    }
    if (!validatePassenger(passengers+i)) {
      // The current passenger must also be disposed of
      freePassengers(passengers, i+1);
      return NULL;
    }
  }
  return passengers;
}

int readPassenger(FILE* input_file, Passenger* passenger) {
  return readName(input_file, &passenger->name) &&
    readLine(input_file, &passenger->flight_no) &&
    readInt(input_file, &passenger->items_count) &&
    readInt(input_file, &passenger->total_weight);
}
