#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "dopusk.h"

void random_array(float* a, int size_a) {
  int rand_interval = size_a/2; // to make things interesting
  for (int i=0; i<size_a; ++i) {
    a[i] = rand() % rand_interval;
  }
}

void print_array(float* a, int size_a) {
  for (int i=0; i<size_a; ++i) {
    printf("A[%i] = %0.2f\n", i, a[i]);
  }
}

int main(int argc, char** argv) {
  char buf[100];
  int size_a;
  printf("Enter number of elements (from 0 to %u; %u is default) =>", MAX_SIZE, MAX_SIZE);
  fgets(buf, 100, stdin);
  if (buf[0] == '\n') {
    size_a = MAX_SIZE;
  } else {
    size_a = atol(buf);
    if (errno || size_a<0 || size_a>MAX_SIZE) {
      printf("Please enter a number from 0 to %u\n", MAX_SIZE);
      return -1;
    }
  }

  float a[MAX_SIZE];
  float b[MAX_SIZE];

  random_array(a, size_a);
  printf("Array of elements:\n");
  print_array(a, size_a);

  sort(a, size_a);

  printf("Sorted array of elements:\n");
  print_array(a, size_a);

  int size_b = non_unique_sorted(a, size_a, b);

  printf("Non-unique elements:\n");
  print_array(b, size_b);

  return 0;
}