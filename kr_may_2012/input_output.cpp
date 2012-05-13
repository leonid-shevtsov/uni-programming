#include <cstdio>
#include "input_output.h"

int* readArray(const char *filename, int& length) {
  FILE *fp;
  int i;
  int *array;

  fp = fopen(filename, "r");
  fscanf(fp, "%u", &length);

  array = new int[length];

  for (i=0; i<length; ++i) {
    fscanf(fp, "%d", array + i);
  }

  fclose(fp);

  return array;
}

void writeArray(const char* filename, const int * array, const int length) {
  FILE* fp;
  int i;

  fp = fopen(filename, "w");
  fprintf(fp, "%u\n", length);

  for (i=0; i<length; ++i) {
    fprintf(fp, "%d\n", array[i]);
  }
  
  fclose(fp);
}
