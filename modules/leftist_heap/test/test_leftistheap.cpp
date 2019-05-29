// Copyright 2019 Daria Koroleva

#include <gtest/gtest.h>
#include "include/leftistheap.h"

TEST(LeftistHeap_Test, Can_Construct_Heap_Without_Parameters) {
    // Arrange
    // Act
    // Assert
    ASSERT_NO_THROW(LeftistHeap lh);
}

TEST(LeftistHeap_Test, Can_Insert_Element) {
    // Arrange
    LeftistHeap lh;
    // Act
    // Assert
    ASSERT_NO_THROW(lh.Insert(55));
}

TEST(LeftistHeap_Test, IsEmpty_Returns_True_When_Empty) {
    // Arrange
    LeftistHeap lh;
    // Act
    // Assert
    EXPECT_TRUE(lh.IsEmpty());
}

TEST(LeftistHeap_Test, IsEmpty_Returns_False_When_NotEmpty) {
    // Arrange
    LeftistHeap lh;
    // Act
    lh.Insert(23);
    // Assert
    EXPECT_FALSE(lh.IsEmpty());
}

TEST(LeftistHeap_Test, Can_FindMin_Correcly) {
    // Arrange
    LeftistHeap lh;
    // Act
    lh.Insert(23);
    lh.Insert(1);
    lh.Insert(23);
    lh.Insert(2);
    lh.Insert(88);
    // Assert
    EXPECT_EQ(1, lh.FindMin());
}

TEST(LeftistHeap_Test, Can_DeleteMin_Correcly) {
    // Arrange
    LeftistHeap lh;
    // Act
    lh.Insert(23);
    lh.Insert(1);
    lh.Insert(23);
    lh.Insert(2);
    lh.Insert(88);

    lh.DeleteMin();

    // Assert
    EXPECT_EQ(2, lh.FindMin());
}

TEST(LeftistHeap_Test, Can_Merge_Two_LeftistHeaps) {
    // Arrange
    LeftistHeap lh1;
    LeftistHeap lh2;
    // Act
    // Assert
    ASSERT_NO_THROW(lh1.Merge(&lh2));
}

TEST(LeftistHeap_Test, Can_Merge_Two_LeftistHeaps_Correctly) {
    // Arrange
    LeftistHeap lh1;
    LeftistHeap lh2;
    // Act
    lh1.Insert(3);
    lh1.Insert(1);
    lh2.Insert(2);
    lh2.Insert(3);
    lh1.Merge(&lh2);
    // Assert
    EXPECT_EQ(1, lh1.FindMin());
    lh1.DeleteMin();
    EXPECT_EQ(2, lh1.FindMin());
    lh1.DeleteMin();
    EXPECT_EQ(3, lh1.FindMin());
    lh1.DeleteMin();
    EXPECT_EQ(3, lh1.FindMin());
}

TEST(LeftistHeap_Test, Can_Merge_With_Empty_LeftistHeaps1) {
    // Arrange
    LeftistHeap lh1;
    LeftistHeap lh2;

    // Act
    lh1.Insert(3);
    // Assert
    ASSERT_NO_THROW(lh2.Merge(&lh1));
}

TEST(LeftistHeap_Test, Can_Merge_With_Empty_LeftistHeaps2) {
    // Arrange
    LeftistHeap lh1;
    LeftistHeap lh2;

    // Act
    lh1.Insert(3);
    // Assert
    ASSERT_NO_THROW(lh1.Merge(&lh2));
}

TEST(LeftistHeap_Test, Can_Merge_With_Itself) {
    // Arrange
    LeftistHeap lh1;
    // Act
    lh1.Insert(3);
    // Assert
    ASSERT_NO_THROW(lh1.Merge(&lh1));
}

TEST(LeftistHeap_Test, Can_Merge_Leftishheaps_With_OneElem) {
    // Arrange
    LeftistHeap lh1;
    LeftistHeap lh2;
    // Act
    lh1.Insert(3);
    lh2.Insert(4);
    // Assert
    ASSERT_NO_THROW(lh1.Merge(&lh1));
}
