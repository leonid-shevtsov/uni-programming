#include "dopusk.h"

int non_unique_sorted(float* a, int size_a, float* b) {
  int size_b=0;

  for (int i=1; i < size_a; i++) {
    if (a[i]==a[i-1] && (size_b==0 || b[size_b-1] != a[i])) {
      b[size_b++] = a[i];
    }
  }
  return size_b;
}

void sort(float* a, int size_a) {
  for (int i=0; i<size_a; i++) {
    for (int j=i+1; j<size_a; j++) {
      if (a[j] < a[i]) {
        float t = a[i];
        a[i] = a[j];
        a[j] = t;
      }
    }
  }
}