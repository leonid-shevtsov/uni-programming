#include "dopusk.h"
#include <gtest/gtest.h>

class ArrayTest: public ::testing::Test {
protected:
  float a[1000];
  float b[1000];
  int size_a;
  int size_b;
};

TEST_F(ArrayTest, SortedWithEmptyArray) {
  size_a = 0;
  size_b = non_unique_sorted(a, size_a, b);
  ASSERT_EQ(0, size_b);
};

TEST_F(ArrayTest, SortedWithSingleElement) {
  size_a = 1;
  a[0] = 1;
  size_b = non_unique_sorted(a, size_a, b);
  ASSERT_EQ(0, size_b);
};

TEST_F(ArrayTest, SortedWithTwoDifferentElements) {
  size_a = 2;
  a[0] = 1;
  a[1] = 2;
  size_b = non_unique_sorted(a, size_a, b);
  ASSERT_EQ(0, size_b);
}

TEST_F(ArrayTest, SortedWithTwoEqualElements) {
  size_a = 2;
  a[0] = 1;
  a[1] = 1;
  size_b = non_unique_sorted(a, size_a, b);
  ASSERT_EQ(1, size_b);
  ASSERT_EQ(1, b[0]);
}

TEST_F(ArrayTest, SortedWithThreeEqualElements) {
  size_a = 3;
  a[0] = 1;
  a[1] = 1;
  a[2] = 1;
  size_b = non_unique_sorted(a, size_a, b);
  ASSERT_EQ(1, size_b);
  ASSERT_EQ(1, b[0]);
}

TEST_F(ArrayTest, SortedWithTwoPairs) {
  size_a = 4;
  a[0] = 1;
  a[1] = 1;
  a[2] = 2;
  a[3] = 2;
  size_b = non_unique_sorted(a, size_a, b);
  ASSERT_EQ(2, size_b);
  ASSERT_EQ(1, b[0]);
  ASSERT_EQ(2, b[1]);
}


/*
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
*/