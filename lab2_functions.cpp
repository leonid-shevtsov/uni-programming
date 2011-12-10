#include "lab2.h"

int* computeSums(int n, int m, int **a) {
  int *c = new int[m];
  int i, j;

  for (j=0; j<m; ++j) {
    c[j] = 0;
    for (i=0; i<n; ++i) {
      c[j] += a[i][j];
    }
  }

  return c;
}

int** transposeMatrix(int n, int m, int **a) {
  int **b = new int* [m];
  int i, j;

  for (i=0; i<m; ++i) {
    b[i] = new int[n];
    for (j=0; j<n; ++j) {
      b[i][j] = a[j][i];
    }
  }

  return b;
}
