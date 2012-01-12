#include "functions.h"
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

TEST(FindAverage, FindsAverage) {
  int array1[] = {1};
  int array2[] = {5, 4};

  ASSERT_EQ(1, findAverage(1, array1));
  ASSERT_EQ(4.5, findAverage(2, array2));
}

TEST(SumOfPositiveElements, FindsSum) {
  int array1[] = {1, 2, 3};
  int array2[] = {1, -2, -3};

  ASSERT_EQ(6, sumOfPositiveElements(3, array1));
  ASSERT_EQ(1, sumOfPositiveElements(3, array2));
}

TEST(ProductOfElementsWithEvenIndices, FindsProduct) {
  int array1[] = {1, 2, 3};
  int array2[] = {1, 2, 3, 4};

  ASSERT_EQ(3, productOfElementsWithEvenIndices(3, array1));
  ASSERT_EQ(3, productOfElementsWithEvenIndices(4, array2));
}

TEST(CountNegativeElements, FindsCount) {
  int array1[] = {1, 2, 3};
  int array2[] = {-1, -2, -3};

  ASSERT_EQ(0, countNegativeElements(3, array1));
  ASSERT_EQ(3, countNegativeElements(3, array2));
}
