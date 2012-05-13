#include <cstdlib>
#include "sort_helpers.h"
#include "generators.h"
#include "input_output.h"

int* generateRandom(const int length) {
  int* a = new int[length];
  for (int i=0; i<length; ++i) {
    a[i] = rand() % length*2;
  }
  return a;
}

int* generateSorted(const int length) {
  int* a = new int[length];
  for (int i=0; i<length; ++i) {
    a[i] = i;
  }
  return a;
}

int* generateAlmostSorted(const int length) {
  int* a = new int[length];
  for (int i=0; i<length; ++i) {
    a[i] = i;
  }
  for (int i=0; i<length/10; ++i) {
    int i1 = rand() % (length-1);
    swap(a[i1], a[i1+1]);
  }
  return a;
}

int* generateReverseSorted(const int length) {
  int* a = new int[length];
  for (int i=0; i<length; ++i) {
    a[i] = length - i;
  }
  return a;
}

int qsortKillerCompare(int* a, const int i, const int j, int& candidate, int& gas, int& solid) {
  if (a[i]==gas && a[j]==gas) {
    if (i==candidate) {
      a[i] = solid++;
    } else {
      a[j] = solid++;
    }
  }
  if (a[i]==gas)
    candidate = i;
  else
    candidate = j;
  
  return a[i]-a[j];
}

void generateQsortKillerPart(int* a, int* b, const int start, const int end, int& candidate, int& gas, int& solid) {
  int pivot = b[(start+end)/2]; 
  int i=start, j=end;

  while (i <= j) {
    while (qsortKillerCompare(a, b[i], pivot, candidate, gas, solid)<0) i++;
    while (qsortKillerCompare(a, b[j], pivot, candidate, gas, solid)>0) j--;
    if (i <= j) {
      swap(b[i], b[j]);
      i++;
      j--;
    }
  }
  
  if (start < j)
    generateQsortKillerPart(a, b, start, j, candidate, gas, solid);
  if (i < end)
    generateQsortKillerPart(a, b, i, end, candidate, gas, solid);
}

int* generateQsortKiller(const int length) {
  int* a = new int[length];
  int* b = new int[length];
  int solid=0, candidate=0, gas=length+1;

  for (int i=0;i<length;++i) {
    a[i]=gas;
    b[i]=i;
  }

  generateQsortKillerPart(a, b, 0, length-1, candidate, gas, solid);

  delete b;

  return a;
}
