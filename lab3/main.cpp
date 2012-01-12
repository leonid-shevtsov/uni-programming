// Ввести одномерный массив, найти минимальный, макс, сумму, среднее значение, сумму положительных, произведение элементов на четных местах, количество отрицательных 
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

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

void readArray(int &n, int *&a) {
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

void printArray(const int n, const int *a) {
  printf("[ ");
  for (int i=0; i<n; ++i) {
    printf("%6i ", a[i]);
  }
  printf(" ]\n");
}

void printResult(const int n, const int* a, const int maxi, const int mini, const float avg, const int sum, const int product, const int count) {
  printf("A = ");
  printArray(n, a);
  printf("Max element A[%i] = %i\n", maxi, a[maxi]);
  printf("Min element A[%i] = %i\n", mini, a[mini]);
  printf("Average = %0.3f\n", avg);
  printf("Sum of positive elements = %i\n", sum);
  printf("Product of elements with even indices = %i\n", product);
  printf("Count of negative elements = %i\n", count);
}

int main() {
  int n;
  int *a;
  int maxi, mini, s, p, c;
  float avg;
  readArray(n, a);
  maxi = findMaxElement(n, a);
  mini = findMinElement(n, a);
  avg = findAverage(n, a);
  s = sumOfPositiveElements(n, a);
  p = productOfElementsWithEvenIndices(n, a);
  c = countNegativeElements(n, a);
  printResult(n, a, maxi, mini, avg, s, p, c);
  return 0;
}
