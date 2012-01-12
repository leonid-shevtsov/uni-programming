#include "functions.h"

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

float findAverage(int n, const int *a) {
  float sum = a[0];
  for (int i=1; i < n; ++i) {
    sum += a[i];
  }
  return sum/n;
}

int sumOfPositiveElements(int n, const int *a) {
  int sum = a[0];
  for (int i=1; i < n; ++i) {
    if (a[i] > 0) {
      sum += a[i];
    }
  }
  return sum;
}

int productOfElementsWithEvenIndices(int n, const int *a) {
  int product = a[0];
  for (int i=2; i < n; i+=2) {
    product *= a[i];
  }
  return product;
}

int countNegativeElements(int n, const int *a) {
  int count = 0;
  for (int i=0; i < n; ++i) {
    if (a[i] < 0) {
      count++;
    }
  }
  return count;
}
