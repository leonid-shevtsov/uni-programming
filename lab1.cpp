#include <stdio.h>
#include <unistd.h>
#include "lab1.h"

void readData(int &n, int *&a) {
  bool showMenu = isatty(fileno(stdin));
};


void writeResult(int *a, int min, int max, int neightborsCount) {
};

int main() {
  int n = 0;
  int *a;

  int min, max, neighborsCount;

  readData(n, a);
  min = findMinElement(n, a);
  max = findMaxElement(n, a);
  neighborsCount = countNeighbors(n, a);
  writeResult(a, min, max, neighborsCount); 
  return 0;
}
