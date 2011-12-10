#include <gtest/gtest.h>
#include <stdarg.h>
#include "lab2.h"

int ** m(int n, int m, ...) {
  int ** a;
  int i,j, vc;
  va_list vp;

  a = new int* [n];

  va_start(vp, vc);

  for (i=0;i<n;++i) {
    a[i] = new int[m];

    for (j=0;j<m;++j) {
      a[i][j] = va_arg(vp, int);
    }
  }

  va_end(vp);

  return a;
}

int *  a(int n, ...) {
  int * a;
  int i, vc;

  va_list vp;

  va_start(vp, vc);

  a = new int[n];

  for (i=0;i<n;++i) {
    a[i] = va_arg(vp, int);
  }

  va_end(vp);

  return a;
}

TEST(ComputeSums, ComputesSums) {
  int* c = computeSums(2, 2, m( 2, 2,
    1, 2, 
    3, 4)
  );

  ASSERT_EQ(4, c[0]);
  ASSERT_EQ(6, c[1]);
}

TEST(TransposeMatrix, TransposesMatrix) {
  int **b = transposeMatrix(2, 3, m( 2, 3,
    1, 2, 3,
    4, 5, 6)
  );

  ASSERT_EQ(1, b[0][0]);
  ASSERT_EQ(4, b[0][1]);
  ASSERT_EQ(2, b[1][0]);
  ASSERT_EQ(5, b[1][1]);
  ASSERT_EQ(3, b[2][0]);
  ASSERT_EQ(6, b[2][1]);
}
