#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    (*line) = (char*)malloc(strlen(buffer)+1);
    strcpy((*line), buffer);
    return 1;
  } else {
    return  0;
  }
}

int readName(FILE* file, Name* name) {
  return readLine(file, &name->first_name) && readLine(file, &name->last_name);
}

Passenger* readPassengerFile(FILE* input_file, int* size) {
  if (!readInt(input_file, size)) {
    return NULL; // bad file format
  }
  if ((*size)<0) {
    return NULL;
  }
  Passenger* passengers = (Passenger*)malloc(sizeof(Passenger)*(*size));
  int i;
  for (i=0; i<(*size); ++i) {
    if (!readPassenger(input_file, passengers+i)) {
      free(passengers);
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
