// Copyright 2019 Soluyanov Alexsey

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/dHeap.h"

TEST(dHeapTest, Can_Create_dHeap_With_d) {
    // Arrange
    unsigned int _d = 2;

    // Act
    dHeap my_heap = dHeap(_d);

    // Assert
    EXPECT_EQ(_d, my_heap.get_d());
}

TEST(dHeapTest, Can_Create_dHeap_With_d_and_Weight) {
    // Arrange
    unsigned int _d = 2;
    std::vector<int> w = { 1, 2, 3 };

    // Act
    dHeap my_heap = dHeap(_d, w);

    // Assert
    EXPECT_EQ(w, my_heap.get_weight());
}

TEST(dHeapTest, Get_Parent) {
    // Arrange
    unsigned int _d = 2;
    std::vector<int> w = { 3, 6, 4, 9, 8, 12, 7, 11, 9 };

    // Act
    dHeap my_heap = dHeap(_d, w);

    // Assert
    EXPECT_EQ(0, my_heap.get_parent(2));
}

TEST(dHeapTest, Get_Left_Child) {
    // Arrange
    unsigned int _d = 2;
    std::vector<int> w = { 5, 6, 7, 4, 8, 11, 12, 9 };

    // Act
    dHeap my_heap = dHeap(_d, w);

    // Assert
    EXPECT_EQ(3, my_heap.get_left_child(1));
}

TEST(dHeapTest, Get_Right_Child) {
    // Arrange
    unsigned int _d = 2;
    std::vector<int> w = { 5, 6, 7, 4, 8, 11, 12, 9 };

    // Act
    dHeap my_heap = dHeap(_d, w);

    // Assert
    EXPECT_EQ(4, my_heap.get_right_child(1));
}

TEST(dHeapTest, Get_Min_Child) {
    // Arrange
    unsigned int _d = 3;
    std::vector<int> w = { 1, 2, 2, 2, 3, 4, 5 };

    // Act
    dHeap my_heap = dHeap(_d, w);

    // Assert
    EXPECT_EQ(4, my_heap.get_min_child(1));
}

TEST(dHeapTest, Insert_Element) {
    // Arrange
    unsigned int _d = 2;
    std::vector<int> w = { 1, 4, 3, 5 };
    std::vector<int> res = { 1, 2, 3, 5, 4};
    // Act
    dHeap my_heap = dHeap(_d, w);
    my_heap.Insert(2);

    // Assert
    EXPECT_EQ(res, my_heap.get_weight());
}

TEST(dHeapTest, Delete_Elements) {
    // Arrange
    unsigned int _d = 2;
    std::vector<int> w = { 1, 4, 3, 5 };
    std::vector<int> res = { 1, 5, 3};
    // Act
    dHeap my_heap = dHeap(_d, w);
    my_heap.Delete(1);

    // Assert
    EXPECT_EQ(res, my_heap.get_weight());
}

TEST(dHeapTest, Delete_Min_Element) {
    // Arrange
    unsigned int _d = 2;
    std::vector<int> w = { 1, 4, 3, 5 };
    std::vector<int> res = { 3, 4, 5 };
    // Act
    dHeap my_heap = dHeap(_d, w);
    my_heap.Delete_min();

    // Assert
    EXPECT_EQ(res, my_heap.get_weight());
}
