// Copyright 2019 Yury Gaydaychuk

#include <gtest/gtest.h>

#include "include/quick-sort.h"

// Checking of simple increasing list
TEST(Gaydaychuk_Yury_ComplexNumberTest, Increasing_Checking) {
    // Arrange
	QuickSort qs;
	int arr[3] = {1, 2, 3};

    // Act
    bool res = qs.checkIncreasing(arr, 3);

    // Assert
    EXPECT_TRUE(res);
}

