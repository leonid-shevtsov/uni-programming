#ifndef GENERATORS_H
#define GENERATORS_H

// Completely random values
int* generateRandom(const int length);
// An already sorted array
int* generateSorted(const int length);
// A sorted array with length/10 items randomly swapped
int* generateAlmostSorted(const int length);
// An array sorted in the reverse order
int* generateReverseSorted(const int length);
// A "Qsort killer" that's tuned for the customQsort
// See http://www.cs.dartmouth.edu/~doug/mdmspe.pdf  
// Warning - the generator itself is O(n2) 
int* generateQsortKiller(const int length);

#endif
