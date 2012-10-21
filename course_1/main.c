#include "passenger_structures.h"
#include "passenger_input.h"

#include <stdlib.h>
#include <stdio.h>

int main(int argc, const char** argv) {
  if (argc < 3) {
    printf("Not enough arguments\nUsage: passengers [input_filename] [output_filename]\n");
    return -1;
  }

  FILE* input_file = fopen(argv[1], "r");
  int size = 0;
  Passenger* passengers = readPassengerFile(input_file, &size);
  fclose(input_file);

  printf("%i %s", size, passengers[0].name.first_name);

  free(passengers);
  return 0;
}