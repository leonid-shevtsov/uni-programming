#include <math.h>
#include "sort_helpers.h"
#include "heap_sort.h"
#include "intro_sort.h"

void introSortPart(int* a, int start, int end, int depthLimit) {
  if (depthLimit==0) {
    heapSort(a+start, end-start+1);
  } else { 
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
      introSortPart(a, start, j, depthLimit-1);
    if (i < end)
      introSortPart(a, i, end, depthLimit-1);
  }
}

void introSort(int* array, int length) {
  introSortPart(array, 0, length-1, floor(2*log((float)length)));
}

