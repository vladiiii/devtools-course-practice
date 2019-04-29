// Copyright 2019 by Zolotareva Olesya

#include <gtest/gtest.h>

#include "include/print-simple-numbers.h"

TEST(SimpleNumbersTest, The_Right_Array) {
    // arrange
    SimpleNumbers check_eng;
    int a = 3;
    int b = 4;
    int *res;
    // act
    res = check_eng.Print(a, b);
    // assert
    ASSERT_TRUE(res);
}
