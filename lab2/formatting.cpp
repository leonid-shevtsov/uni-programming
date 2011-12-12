#include <stdio.h>
#include "formatting.h"

void printMatrix(int n, int m, int **a) {
  for (int i=0; i<n; ++i) {
    printf("| ");
    for (int j=0; j<m; ++j) {
      printf("%6i ", a[i][j]);
    }
    printf(" |\n");
  }
}

void printArray(int n, int *a) {
  printf("[ ");
  for (int i=0; i<n; ++i) {
    printf("%6i ", a[i]);
  }
  printf(" ]\n");
}
