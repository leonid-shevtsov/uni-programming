#include "sort_helpers.h"
#include "custom_qsort.h"

#include <stdlib.h>
#include <stdio.h>

void customQsortPart(int* a, int start, int end) {
  int pivot = a[(start+end)/2]; 
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
    customQsortPart(a, start, j);
  if (i < end)
    customQsortPart(a, i, end);
}

void customQsort(int* array, int length) {
  customQsortPart(array, 0, length-1);
}

