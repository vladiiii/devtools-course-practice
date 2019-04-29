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

TEST(SimpleNumbersTest, The_Right_Border_Mistake) {
    // arrange
    SimpleNumbers check_eng;
    int a = 6;
    int b = -7;
    int res;
    // act
    res = check_eng.SizeOfArray(a, b);
    // assert
    EXPECT_EQ(-1, res);
}

TEST(SimpleNumbersTest, The_Left_Border_Mistake) {
    // arrange
    SimpleNumbers check_eng;
    int a = -10;
    int b = 7;
    int res;
    // act
    res = check_eng.SizeOfArray(a, b);
    // assert
    EXPECT_EQ(-1, res);
}

TEST(SimpleNumbersTest, The_Null_Border_Mistake) {
    // arrange
    SimpleNumbers check_eng;
    int a = 0;
    int b = 0;
    int res;
    // act
    res = check_eng.SizeOfArray(a, b);
    // assert
    EXPECT_EQ(-1, res);
}

TEST(SimpleNumbersTest, The_Big_Left_Border_Mistake) {
    // arrange
    SimpleNumbers check_eng;
    int a = 6;
    int b = 2;
    int res;
    // act
    res = check_eng.SizeOfArray(a, b);
    // assert
    EXPECT_EQ(-1, res);
}

TEST(SimpleNumbersTest, The_Null_Interval) {
    // arrange
    SimpleNumbers check_eng;
    int a = 5;
    int b = 5;
    int res;
    // act
    res = check_eng.SizeOfArray(a, b);
    // assert
    EXPECT_EQ(-1, res);
}

TEST(SimpleNumbersTest, The_Null_Numbers) {
    // arrange
    SimpleNumbers check_eng;
    int a = 9;
    int b = 10;
    int res;
    // act
    res = check_eng.SizeOfArray(a, b);
    // assert
    EXPECT_EQ(0, res);
}

TEST(SimpleNumbersTest, Few_Simple_Numbers) {
    // arrange
    SimpleNumbers check_eng;
    int a = 9;
    int b = 15;
    int res;
    // act
    res = check_eng.SizeOfArray(a, b);
    // assert
    EXPECT_EQ(2, res);
}

TEST(SimpleNumbersTest, The_Negative_Number) {
    // arrange
    SimpleNumbers check_eng;
    int n = -5;
    int res;
    // act
    res = check_eng.Check(n);
    // assert
    EXPECT_EQ(-1, res);
}

TEST(SimpleNumbersTest, The_Complex_Number) {
    // arrange
    SimpleNumbers check_eng;
    int n = 6;
    int res;
    // act
    res = check_eng.Check(n);
    // assert
    EXPECT_EQ(0, res);
}

TEST(SimpleNumbersTest, The_Simple_Number) {
    // arrange
    SimpleNumbers check_eng;
    int n = 7;
    int res;
    // act
    res = check_eng.Check(n);
    // assert
    EXPECT_EQ(7, res);
}

TEST(SimpleNumbersTest, The_Right_Arraynew) {
    // arrange
    SimpleNumbers check_eng;
    int a = 3;
    int b = 5;
    int *res;
    // act
    res = check_eng.Print(a, b);
    // assert
    ASSERT_TRUE(res);
}

TEST(SimpleNumbersTest, The_check_array) {
    // arrange
    SimpleNumbers check_eng;
    int a = 3;
    int b = 9;
    int *res;
    // act
    res = check_eng.Print(a, b);
    // assert
    ASSERT_TRUE(res);
}
