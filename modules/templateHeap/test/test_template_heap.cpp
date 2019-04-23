// Copyright 2019 Kumbrasev Pavel

#include <gtest/gtest.h>
#include "include/heap.h"

TEST(TemplateHeapTest, Size_Empty_Heap_Equals_Zero) {
	// Arrange
	Heap<int> heap{};

	// Act && Assert
	EXPECT_EQ(0, heap.GetSize());
}

TEST(TemplateHeapTest, Can_Create_Empty_Heap) {
    // Arrange
    Heap<int> heap{};

    // Act & Assert
    EXPECT_EQ(0, heap.GetSize());
}

TEST(TemplateHeapTest, Can_Insert_Element_In_Empty_Heap) {
    // Arrange
    Heap<int> heap{};
    
    // Act
    heap.Insert(7);
    // Assert
    EXPECT_EQ(1, heap.GetSize());
}

TEST(TemplateHeapTest, Can_Insert_Element_In_Not_Empty_Heap) {
	// Arrange
	Heap<int> heap{};

	// Act
	heap.Insert(7);
	heap.Insert(3);
	// Assert
	EXPECT_EQ(2, heap.GetSize());
}

TEST(TemplateHeapTest, Can_Not_Remove_Element_From_Empty_Heap) {
	// Arrange
	Heap<int> heap{};

	// Act && Assert
	ASSERT_ANY_THROW(heap.Remove());
}

TEST(TemplateHeapTest, Can_Remove_Element_From_Not_Empty_Heap) {
	// Arrange
	Heap<int> heap{};
	heap.Insert(7);

	// Act && Assert
	EXPECT_EQ(7, heap.Remove());
}

TEST(TemplateHeapTest, Can_Sort_Vector) {
	// Arrange
	Heap<int> heap{};
	std::vector<int> test_vec = { 3,4,6,1 };
	// Act
	std::vector<int> result_vec = { 6,4,3,1 };
	// Act && Assert
	EXPECT_EQ(result_vec, heap.HeapSort(test_vec));
}

