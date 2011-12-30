#include <stdio.h>
#include <stdlib.h>
#include "lab2.h"
#include "formatting.h"

const int MIN_DIMENSIONS = 6;

void printHelp() {
  printf("This program will ask you for a matrix of integers\n");
  printf("It will compute the sums of values in all columns of the matrix\n");
  printf("It will find the column with the least sum\n");
  printf("It will also transpose the matrix and print out the result\n");
  printf("Press Ctrl+C to exit at any time\n\n");
}

bool readInt(int &i) {
  char buffer[100];
  char *ptr;
  if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
    i = strtol(buffer, &ptr, 10);
    return buffer[0] != '\n' && (*ptr == '\n' || *ptr == '\0');
  } else {
    return false;
  }
}

int readDimension(const char *name) {
  int n = 0;
  do {
	printf("%s = ", name);
    readInt(n);
	if (n < MIN_DIMENSIONS) printf("%s must be at least %i\n", name, MIN_DIMENSIONS);
  } while (n < MIN_DIMENSIONS);
  return n;
}

void readData(int &n, int &m, int **&a) {
  n = readDimension("Number of rows N");
  m = readDimension("Number of columns M");

  a = new int* [n];
  for (int i=0; i<n; ++i) {
    a[i] = new int [m];
    for (int j=0; j<m; ++j) {
      printf("A[%2i][%2i] = ", i, j);
	  readInt(a[i][j]);
    }
  }
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

  system("pause");

  return 0;
}
