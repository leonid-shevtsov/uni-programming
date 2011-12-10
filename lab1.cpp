#include <stdio.h>
#include "lab1.h"

void readData(int &n, int *&a) {
  printf("Total number of elements N = ");
  scanf("%i", &n);
  
  // TODO validation

  a = new int[n];

  for (int i=0; i<n; ++i) {
    printf("A[%4i] = ", i);
    scanf("%i", a+i);
  }
}


void writeResult(int *a, int min, int max, int neighborsCount) {
  printf("====\n");
  printf("Min: A[%i] = %i\n", min, a[min]);
  printf("Max: A[%i] = %i\n", max, a[max]);
  printf("Neighbors count: %i\n", neighborsCount);
}

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
