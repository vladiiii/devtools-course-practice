// Copyright 2019 Karasev Anton

#include "gtest/gtest.h"

#include "include/modif_stack.h"

#include <iostream>
#include <vector>
#include <string>


TEST(modif_stack, Can_Creating_Empty_Stack) {
    // Arrange
    modif_stack<int> x;

    // Act and Assert
    ASSERT_EQ(x.size(), 0);
}

TEST(modif_stack, Can_Create_Stack_In_Vector) {
    // Arrange
    std::vector<int> x = {4, 6, 7};
    std::string z = "(4,4) (6,4) (7,4) ";
    
    // Act
    modif_stack<int> y(x);

    // Assert
    ASSERT_STREQ(y.show_stack(), z);
}

TEST(modif_stack, Can_Create_Stack_In_Copy_Constructor) {
    // Arrange
    std::vector<int> x = {1, 2, 3};
    modif_stack<int> y(x);
    std::string z = "(1,1) (2,1) (3,1) ";
    
    // Act
    modif_stack<int> q(y);

    // Assert
    ASSERT_STREQ(q.show_stack(), z);
}

TEST(modif_stack, Can_Top_In_Empty_Stack) {
    // Arrange
    modif_stack<int> x;
    int last, min;
    
    // Act
    last = y.top().first;
    min = y.top().second;

    // Assert
    EXPECT_EQ(-1, last);
    EXPECT_EQ(0, min);
}

TEST(modif_stack, Can_Top_In_Stack) {
    // Arrange
    std::vector<int> x = {3, 4, 27};
    modif_stack<int> y(x);
    int last = 0;
    
    // Act
    last = y.top().first;

    // Assert
    EXPECT_EQ(27, last);
}

TEST(modif_stack, Can_Pop_In_Empty_Stack) {
    // Arrange
    modif_stack<int> x;

    // Act & Assert
    ASSERT_ANY_THROW(x.pop());
}

TEST(modif_stack, Can_Pop_In_Non_Empty_Stack) {
    // Arrange
    std::vector<int> x = {7, 21, 6. 25, 1};
    modif_stack<int> y(x);
    
    // Act
    y.pop();

    // Assert
    EXPECT_EQ(25, y.top().first);
}

TEST(modif_stack, Can_Get_Min_Via_Top_In_Stack) {
    // Arrange
    std::vector<int> x = {4, 29, 3};
    modif_stack<int> y(x);
    int min = 0;
    
    // Act
    last = y.top().second;

    // Assert
    EXPECT_EQ(3, min);
}

TEST(modif_stack, Can_Push_In_Stack) {
    // Arrange
    modif_stack<int> x;
    
    // Act
    x.push(21);

    // Assert
    EXPECT_EQ(21, x.top().first);
}