#include "sort_helpers.h"
#include "heap_sort.h"

void siftDown(int* a, const int start, const int end) {
  int root = start;

  while (root*2+1 <= end) {
    int child = root*2+1;
    int to_swap = root;
    
    if (a[to_swap] < a[child]) {
      to_swap = child;
    }
    if (child+1 <= end && a[to_swap] < a[child+1]) {
      to_swap = child+1;
    }
    if (to_swap != root) {
      swap(a[root], a[to_swap]);
      root = to_swap;
    } else {
      return;
    }
  }
}

void heapify(int* a, const int length) {
  int start = (length-2) / 2;
  while (start >= 0) {
    siftDown(a, start, length-1);
    start = start-1;
  }
}


void heapSort(int* array, const int length) {
  heapify(array, length);
  int end = length-1;
  while (end>0) {
    swap(array[0], array[end]);
    end = end-1;
    siftDown(array, 0, end);
  }
}
