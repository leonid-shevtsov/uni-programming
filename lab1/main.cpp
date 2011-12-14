#include <stdio.h>
#include <stdlib.h>
#include "lab1.h"

void printHelp() {
  printf("This program will show the minimum and maximum elements of an array\n");
  printf("It will also count the number of occurences when a positive and\n");
  printf("negative number stand next to each other\n\n");
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

void readData(int &n, int *&a) {
  do {
    printf("Total number of integer elements N = ");
    if (!readInt(n) || n<0) {
      printf("N must be a number greater than 0\n");
    }
  } while (n <= 0);

  a = new int[n];

  for (int i=0; i<n; ++i) {
    printf("A[%2i] = ", i);
    if (!readInt(a[i])) {
      printf("A[%2i] must be an integer\n",i);
      i--;
    }
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

  printHelp();
  readData(n, a);
  min = findMinElement(n, a);
  max = findMaxElement(n, a);
  neighborsCount = countNeighbors(n, a);
  writeResult(a, min, max, neighborsCount); 
  delete a;
  return 0;
}
