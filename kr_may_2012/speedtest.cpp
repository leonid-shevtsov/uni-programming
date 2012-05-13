#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cmath>
#include "custom_qsort.h"
#include "randomized_qsort.h"
#include "intro_sort.h"
#include "heap_sort.h"
#include "generators.h"
#include "input_output.h"

typedef void SortFunction(int *, int);
typedef int* GeneratorFunction(int);

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

void systemQsort(int* a, int l) {
  qsort(a, l, sizeof(int), compare);
}

SortFunction* sortFunctions[]= {
  &systemQsort,
  &customQsort, 
  &randomizedQsort, 
  &introSort,
  &heapSort};
const char* sortFunctionNames[] = {
  "stdlib qsort()", 
  "median qsort", 
  "random qsort", 
  "intro-sort",
  "heap-sort"};
const int sortCount = 5;

GeneratorFunction* generators[] = {
  &generateRandom, 
  &generateSorted,
  &generateAlmostSorted,
  &generateReverseSorted,
  &generateQsortKiller};
const char* generatorNames[] = {
  "random",
  "sorted",
  "almost sorted",
  "reverse order",
  "QSort killer"
};
const int generatorCount = 5;

// FIXME this doesn't actually convert to seconds. But we don't need seconds, just values on the same scale
double clock_diff_to_sec(long clock_diff)
{
    return double(clock_diff) / CLOCKS_PER_SEC;
}

int main() {
  FILE *csv = fopen("speedtest.csv", "w");

  int min_power = 3;
  int max_power = 16;
  int num_iterations = 100;

  for (int gi=0; gi<generatorCount; ++gi) {
    for (int si=0; si<sortCount; ++si) {
      fprintf(csv, ",%s",sortFunctionNames[si]);
    }
    fprintf(csv, ",");
  }
  fprintf(csv, "\n");
  
  for (int gi=0; gi<generatorCount; ++gi) {
    for (int si=0; si<sortCount; ++si) {
      fprintf(csv, ",%s",generatorNames[gi]);
    }
    fprintf(csv, ",");
  }
  fprintf(csv, "\n");


  for (int power=min_power, length=1<<min_power; power<=max_power; ++power, length<<=1) {
    fprintf(csv, "%i", length);
    printf("# %i\n", length); 

    for (int gi=0; gi<generatorCount; ++gi) {
      printf("## %s\n", generatorNames[gi]);
      int* data = (*generators[gi])(length);
      int* a = new int[length];

      for (int si=0; si<sortCount; ++si) {
        printf("%s\n", sortFunctionNames[si]);
        float totalTime = 0;

        for (int it=0; it<num_iterations; ++it) {
          memcpy(a, data, length*sizeof(int));
          std::clock_t const start = std::clock();
          (*sortFunctions[si])(a, length);
          std::clock_t const end = std::clock(); 
          totalTime += clock_diff_to_sec(end - start);
        }

        fprintf(csv, ",%0.0f", round(totalTime*1000000/num_iterations));

      }
      fprintf(csv, ",");
    }

    fprintf(csv, "\n");
  }

  fclose(csv);
  
  return 0;
};
