#include "lab1.h"

int findMinElement(int n, const int *a) {
  int min = 0;
  for (int i=1; i < n; ++i) {
    if (a[i] < a[min]) {
      min = i;
    }
  }
  return min;
}

int findMaxElement(int n, const int *a) {
  int max = 0;
  for (int i=1; i < n; ++i) {
    if (a[i] > a[max]) {
      max = i;
    }
  }
  return max;
}

int countNeighbors(int n, const int *a) {
  int neighborsCount = 0;
  for (int i=1; i < n; ++i) {
    if (a[i] * a[i-1] < 0) {
      ++neighborsCount;
    }
  }
  return neighborsCount;
}

