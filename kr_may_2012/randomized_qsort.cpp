#include <cstdlib>
#include "sort_helpers.h"
#include "randomized_qsort.h"

void randomizedQsortPart(int* a, int start, int end) {
  int pivot = a[start+rand()%(end-start+1)]; 
  int i=start, j=end;

  while (i <= j) {
    while (a[i]<pivot) i++;
    while (a[j]>pivot) j--;
    if (i <= j) {
      swap(a[i], a[j]);
      i++;
      j--;
    }
  }
  
  if (start < j)
    randomizedQsortPart(a, start, j);
  if (i < end)
    randomizedQsortPart(a, i, end);
}

void randomizedQsort(int* array, int length) {
  randomizedQsortPart(array, 0, length-1);
}

