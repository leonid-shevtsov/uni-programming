#include "lab1.h"
#include <gtest/gtest.h>

TEST(MinElement, FindsMinimumElement) {
  int array1[] = {1, 2, 3};
  int array2[] = {-2, 0, -3, 4};
  ASSERT_EQ(0, findMinElement(3, array1));
  ASSERT_EQ(2, findMinElement(4, array2));
}

TEST(MaxElement, FindsMaximumElement) {
  int array1[] = {1, 2, 3};
  int array2[] = {-2, 0, -3, 4};
  ASSERT_EQ(2, findMaxElement(3, array1));
  ASSERT_EQ(3, findMaxElement(4, array2));
}

TEST(CountNeighbors, CountsNeighbors) {
  int array1[] = {1, 2, 3};
  int array2[] = {-1, 2, 3};
  int array3[] = {1, 2, -3};
  int array4[] = {-1, -2, 3};
  int array5[] = {-1, -2, -3};
  int array6[] = {1, -2, 3};
  int zeroElements[] = {0, -2, -3};

  ASSERT_EQ(0, countNeighbors(3, array1));
  ASSERT_EQ(1, countNeighbors(3, array2));
  ASSERT_EQ(1, countNeighbors(3, array3));
  ASSERT_EQ(1, countNeighbors(3, array4));
  ASSERT_EQ(0, countNeighbors(3, array5));
  ASSERT_EQ(2, countNeighbors(3, array6));
  ASSERT_EQ(0, countNeighbors(3, zeroElements));
}
