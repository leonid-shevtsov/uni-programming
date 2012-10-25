#ifndef __DOPUSK_H__
#define __DOPUSK_H__

#define MAX_SIZE 1000

// (in) a: array of elements
// (in) size_a: size of a; MAX_SIZE at most
// (out) b: array of non-unique elements of a; expects PREALLOCATED array of MAX_SIZE elements
// returns: size of b
int non_unique_sorted(float* a, int size_a, float* b) {
  int size_b=0;

  for (int i=1; i < size_a; i++) {
    if (a[i]==a[i-1] && (size_b==0 || b[size_b-1] != a[i])) {
      b[size_b++] = a[i];
    }
  }

  return size_b;
}

#endif