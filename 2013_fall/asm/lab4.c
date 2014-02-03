#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int DIMENSION = 1400;

void seedRandomArray(int* array, int length) {
  for (int i=0; i<length; ++i) {
    array[i] = rand();
  }
}

int main() {
  int matrix[DIMENSION*DIMENSION];
  int vector[DIMENSION];
  int result[DIMENSION];

  clock_t start, end;

  seedRandomArray(matrix, DIMENSION*DIMENSION);
  seedRandomArray(vector, DIMENSION);

  int i,j;
  start = clock();

  for (i=0; i<DIMENSION; i++) {
    result[i]=0;
    for (j=0; j<DIMENSION; j++) {
      result[i] += vector[j] * matrix[j*DIMENSION+i];
    }
  }
  end = clock();

  float time = (end - start)*1.0/CLOCKS_PER_SEC;

  printf("%f\n", time);

  return 0;
}