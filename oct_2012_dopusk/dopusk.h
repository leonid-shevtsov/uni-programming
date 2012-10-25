#ifndef __DOPUSK_H__
#define __DOPUSK_H__

#define MAX_SIZE 1000

// Find all non-unique elements in array. Assumes array is sorted
// (in) a: array of elements; sorted
// (in) size_a: size of a; MAX_SIZE at most
// (out) b: array of non-unique elements of a; expects PREALLOCATED array of MAX_SIZE elements
// returns: size of b
int non_unique_sorted(float* a, int size_a, float* b);

// Selection sort
// (in, out) a: array of elements
// (in) size_a: size of a
void sort(float* a, int size_a);

#endif