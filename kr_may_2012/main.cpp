#include <cstdlib>
#include "input_output.h"
#include "custom_qsort.h"
#include "randomized_qsort.h"
#include "intro_sort.h"

#ifndef SORT_FUNCTION
  #define SORT_FUNCTION customQsort
#endif

void printHelp() {
  printf("QSort tester\n");
  printf("USAGE: kr_may_2012 input.txt output.txt\n");
}

int main(int argc, const char** argv) {
  int length;
  int *array;

  if (argc < 3) {
    printHelp();
    exit(-1);
  }

  array = readArray(argv[1], length);

  SORT_FUNCTION(array, length);

  writeArray(argv[2], array, length);
}
