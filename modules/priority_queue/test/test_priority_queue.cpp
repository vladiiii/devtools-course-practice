// Copyright 2019 Andronov Maxim

#include <gtest/gtest.h>

#include "include/priority_queue.h"

TEST(PriorityQueueTest, can_push_element_in_empty_queue) {
    //Arrange
    PriorityQueue q;
    int prior = 1;
    int val = 1;
    //Act
    q.push(prior, val);
    //Assert
    EXPECT_EQ(val, q.top());
}

TEST(PriorityQueueTest, element_with_minimal_priority_push_in_bottom_queue) {
    //Arrange
    PriorityQueue q;
    int prior1 = 1;
    int val1 = 1;
    int prior2 = 2;
    int val2 = 2;
    int prior3 = 3;
    int val3 = 3;
    //Act
    q.push(prior2, val2);
    q.push(prior3, val3);
    q.push(prior1, val1);
    q.pop();
    q.pop();
    //Assert
    EXPECT_EQ(val1, q.top());
}

TEST(PriorityQueueTest, element_with_maximal_priority_push_in_top_queue) {
    //Arrange
    PriorityQueue q;
    int prior1 = 1;
    int val1 = 1;
    int prior2 = 2;
    int val2 = 2;
    int prior3 = 3;
    int val3 = 3;
    //Act
    q.push(prior1, val1);
    q.push(prior2, val2);
    q.push(prior3, val3);
    //Assert
    EXPECT_EQ(val3, q.top());
}

TEST(PriorityQueueTest, element_with_no_max_and_no_min_priority_push_in_queue) {
    //Arrange
    PriorityQueue q;
    int prior1 = 1;
    int val1 = 1;
    int prior2 = 2;
    int val2 = 2;
    int prior3 = 3;
    int val3 = 3;
    //Act
    q.push(prior1, val1);
    q.push(prior3, val3);
    q.push(prior2, val2);
    q.pop();
    //Assert
    EXPECT_EQ(val2, q.top());
}


