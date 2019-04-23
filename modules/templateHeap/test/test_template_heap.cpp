// Copyright 2019 Kumbrasev Pavel

#include <gtest/gtest.h>
#include "include/heap.h"


TEST(TemplateHeapTest, Can_Create_Empty_Heap) {
    // Arrange
    Heap<int> heap{};

    // Act & Assert
    EXPECT_EQ(0, heap.GetSize());
}

