#include <stdio.h>
#include "lab1.h"
#include "lab2.h"

const int MIN_DIMENSIONS = 6;

void printHelp() {
}

void readData(int &n, int &m, int **&a) {
  printf("Number of rows N = ");
  scanf("%i", &n);
  printf("Number of columns M = ");
  scanf("%i", &m);
  a = new int* [n];
  for (int i=0; i<n; ++i) {
    a[i] = new int [m];
    for (int j=0; j<m; ++j) {
      printf("A[%2i][%2i] = ", i, j);
      scanf("%i", &a[i][j]);
    }
  }
}

void printMatrix(int n, int m, int **a) {
  for (int i=0; i<n; ++i) {
    printf("| ");
    for (int j=0; j<m; ++j) {
      printf("%4i", a[i][j]);
    }
    printf(" |\n");
  }
}

void printArray(int n, int *a) {
  printf("[ ");
  for (int i=0; i<n; ++i) {
    printf("%4i", a[i]);
  }
  printf(" ]\n");
}

void printResult(int n, int m, int **a, int *c, int minj, int **b) {
  printf("====\n");
  printf("Initial matrix\n");
  printMatrix(n, m, a);
  printf("\nColumn sums\n");
  printArray(m, c);
  printf("\nColumn with least sum: column %i\n", minj);
  printf("\nTransposed matrix\n");
  printMatrix(m, n, b);
}

int main() {
  int n, m;
  int **a, **b;
  int *c;
  int i;
  int minj;

  printHelp();
  readData(n, m, a);

  c = computeSums(n, m, a);
  minj = findMinElement(m, c);
  b = transposeMatrix(n, m, a);

  printResult(n, m, a, c, minj, b); 

  //== cleanup
  for (int i=0; i<n; ++i) {
    delete a[i];
  }
  // b is transposed, so m rows
  for (int i=0; i<m; ++i) {
    delete b[i];
  }
  delete a;
  delete b;
  delete c;

  return 0;
}
