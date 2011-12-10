#include <stdio.h>
#include "lab1.h"
#include "lab2.h"

void printHelp() {
}

void readData(int &n, int &m, int **&a) {
}


void writeResult(int n, int m, int *c, int maxj, int **b) {
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

  writeResult(n, m, c, minj, b); 

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
