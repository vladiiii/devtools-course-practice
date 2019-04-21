// Copyright 2019 Savkin Yuriy

#include <gtest/gtest.h>

#include <climits>
#include "include/segment_tree.h"


TEST(SegmentTree, can_create_segment_tree) {
    // Arrange & Act & Assert
    ASSERT_NO_THROW(SegmentTree a(1, 2));
}

TEST(SegmentTree, cant_create_segment_tree_with_wrong_barriers) {
    // Arrange & Act & Assert
    ASSERT_ANY_THROW(SegmentTree a(2, 1));
}

TEST(SegmentTree, can_add_value) {
    // Arrange
    SegmentTree a(1, 2);
    // Act & Assert
    ASSERT_NO_THROW(a.AddValue(1, 9));
}

TEST(SegmentTree, cant_add_value_to_wrong_position) {
    // Arrange
    SegmentTree a(1, 2);
    // Act & Assert
    ASSERT_ANY_THROW(a.AddValue(3, 9));
}

TEST(SegmentTree, can_add_to_segment) {
    // Arrange
    SegmentTree a(1, 2);
    // Act & Assert
    ASSERT_NO_THROW(a.AddValue(1, 2, 9));
}

TEST(SegmentTree, cant_add_out_of_range) {
    // Arrange
    SegmentTree a(1, 2);
    // Act & Assert
    ASSERT_ANY_THROW(a.AddValue(1, 3, 9));
}

TEST(SegmentTree, cant_add_with_incorrect_barriers) {
    // Arrange
    SegmentTree a(1, 2);
    // Act & Assert
    ASSERT_ANY_THROW(a.AddValue(2, 1, 9));
}

TEST(SegmentTree, can_set_value) {
    // Arrange
    SegmentTree a(1, 2);
    // Act & Assert
    ASSERT_NO_THROW(a.SetValue(1, 9));
}

TEST(SegmentTree, can_set_on_segment) {
    // Arrange
    SegmentTree a(1, 2);
    // Act & Assert
    ASSERT_NO_THROW(a.SetValue(1, 2, 9));
}

TEST(SegmentTree, cant_set_out_of_range) {
    // Arrange
    SegmentTree a(1, 2);
    // Act & Assert
    ASSERT_ANY_THROW(a.SetValue(0, 2, 9));
}

TEST(SegmentTree, cant_set_value_on_wrong_position) {
    // Arrange
    SegmentTree a(1, 2);
    // Act & Assert
    ASSERT_ANY_THROW(a.SetValue(0, 9));
}

TEST(SegmentTree, cant_set_with_incorrect_barriers) {
    // Arrange
    SegmentTree a(1, 2);
    // Act & Assert
    ASSERT_ANY_THROW(a.SetValue(2, 1, 9));
}

TEST(SegmentTree, can_get_value) {
    // Arrange
    SegmentTree a(1, 2);
    // Act & Assert
    ASSERT_NO_THROW(a.GetValue(2));
}

TEST(SegmentTree, cant_get_value_on_wrong_position) {
    // Arrange
    SegmentTree a(1, 2);
    // Act & Assert
    ASSERT_ANY_THROW(a.GetValue(3));
}

TEST(SegmentTree, can_get_on_segment) {
    // Arrange
    SegmentTree a(1, 2);
    // Act & Assert
    ASSERT_NO_THROW(a.GetValue(1, 2));
}

TEST(SegmentTree, cant_get_out_of_range) {
    // Arrange
    SegmentTree a(1, 2);
    // Act & Assert
    ASSERT_ANY_THROW(a.GetValue(1, 3));
}

TEST(SegmentTree, cant_get_with_incorrect_barriers) {
    // Arrange
    SegmentTree a(1, 2);
    // Act & Assert
    ASSERT_ANY_THROW(a.GetValue(1, 3));
}

TEST(SegmentTree, can_get_base_element) {
    // Arrange
    SegmentTree a(1, 2);
    // Act & Assert
    EXPECT_EQ(0, a.GetBaseElem());
}

TEST(SegmentTree, can_get_left_barrier) {
    // Arrange
    SegmentTree a(1, 2);
    // Act & Assert
    EXPECT_EQ(1, a.GetLeftBarr());
}

TEST(SegmentTree, can_get_right_barrier) {
    // Arrange
    SegmentTree a(1, 2);
    // Act & Assert
    EXPECT_EQ(2, a.GetRightBarr());
}

TEST(SegmentTree, can_create_from_other) {
    // Arrange
    SegmentTree a(1, 2);
    // Act & Assert
    ASSERT_NO_THROW(SegmentTree b(a));
}

TEST(SegmentTree, can_assign_from_other) {
    // Arrange
    SegmentTree a(1, 2), b(5, 9);
    // Act & Assert
    ASSERT_NO_THROW(a = b);
}

TEST(SegmentTree, get_value_is_correct) {
    // Arrange
    SegmentTree a(1, 2);
    // Act & Assert
    EXPECT_EQ(a.GetBaseElem(), a.GetValue(1));
}

TEST(SegmentTree, get_value_on_segment_is_correct) {
    // Arrange
    SegmentTree a(1, 2);
    // Act & Assert
    EXPECT_EQ(a.GetBaseElem(), a.GetValue(1, 2));
}

TEST(SegmentTree, can_get_added_value) {
    // Arrange
    SegmentTree a(1, 2);
    // Act
    a.AddValue(1, 7);
    // Assert
    EXPECT_EQ(7, a.GetValue(1));
}

TEST(SegmentTree, added_value_affects_segment) {
    // Arrange
    SegmentTree a(1, 2);
    // Act
    a.AddValue(1, 7);
    // Assert
    EXPECT_EQ(7, a.GetValue(1, 2));
}

TEST(SegmentTree, added_value_dont_affects_other_value) {
    // Arrange
    SegmentTree a(1, 2);
    // Act
    a.AddValue(1, 7);
    // Assert
    EXPECT_EQ(0, a.GetValue(2));
}

TEST(SegmentTree, can_get_setted_value) {
    // Arrange
    SegmentTree a(1, 2);
    // Act
    a.SetValue(1, 7);
    // Assert
    EXPECT_EQ(7, a.GetValue(1));
}

TEST(SegmentTree, setted_value_affects_segment) {
    // Arrange
    SegmentTree a(1, 2);
    // Act
    a.SetValue(1, 7);
    // Assert
    EXPECT_EQ(7, a.GetValue(1, 2));
}

TEST(SegmentTree, setted_value_dont_affects_other_value) {
    // Arrange
    SegmentTree a(1, 2);
    // Act
    a.SetValue(1, 7);
    // Assert
    EXPECT_EQ(0, a.GetValue(2));
}

TEST(SegmentTree, can_get_added_on_segment_value) {
    // Arrange
    SegmentTree a(1, 7);
    // Act
    a.AddValue(1, 4, 7);
    // Assert
    EXPECT_EQ(7, a.GetValue(2));
}

TEST(SegmentTree, added_on_segment_value_affects_segment) {
    // Arrange
    SegmentTree a(1, 7);
    // Act
    a.AddValue(1, 4, 7);
    // Assert
    EXPECT_EQ(14, a.GetValue(3, 6));
}

TEST(SegmentTree, added_on_segment_value_dont_affects_other_value) {
    // Arrange
    SegmentTree a(1, 7);
    // Act
    a.AddValue(1, 4, 7);
    // Assert
    EXPECT_EQ(0, a.GetValue(5));
}

TEST(SegmentTree, can_get_setted_on_segment_value) {
    // Arrange
    SegmentTree a(1, 7);
    // Act
    a.SetValue(1, 4, 7);
    // Assert
    EXPECT_EQ(7, a.GetValue(4));
}

TEST(SegmentTree, setted_on_segment_value_affects_segment) {
    // Arrange
    SegmentTree a(1, 7);
    // Act
    a.SetValue(1, 4, 7);
    // Assert
    EXPECT_EQ(21, a.GetValue(2, 4));
}

TEST(SegmentTree, setted_on_segment_value_dont_affects_other_value) {
    // Arrange
    SegmentTree a(1, 7);
    // Act
    a.SetValue(1, 4, 7);
    // Assert
    EXPECT_EQ(0, a.GetValue(5, 7));
}

TEST(SegmentTree, tree_work_with_other_functions) {
    // Arrange
    SegmentTree a(1, 7, [](int a, int b, int c)->int {
        if (a < b)
            return a;
        return b;
    }, INT_MAX);
    // Act
    a.AddValue(1, 8);
    a.AddValue(2, 5, 7);
    // Assert
    EXPECT_EQ(7, a.GetValue(1, 2));
}

TEST(SegmentTree, correct_adding_after_setting) {
    // Arrange
    SegmentTree a(1, 7);
    // Act
    a.SetValue(4, 7);
    a.AddValue(4, 3);
    // Assert
    EXPECT_EQ(10, a.GetValue(1, 5));
}

TEST(SegmentTree, correct_adding_after_setting_on_segment) {
    // Arrange
    SegmentTree a(1, 7);
    // Act
    a.SetValue(1, 4, 7);
    a.AddValue(2, 3, 3);
    // Assert
    EXPECT_EQ(34, a.GetValue(1, 5));
}

TEST(SegmentTree, correct_setting_after_adding) {
    // Arrange
    SegmentTree a(-5, -2);
    // Act
    a.AddValue(-3, 3);
    a.SetValue(-3, 7);
    // Assert
    EXPECT_EQ(7, a.GetValue(-3));
}

TEST(SegmentTree, correct_setting_after_adding_on_segment) {
    // Arrange
    SegmentTree a(-5, -2);
    // Act
    a.AddValue(-4, -2, 3);
    a.SetValue(-5, -3, 7);
    // Assert
    EXPECT_EQ(24, a.GetValue(-5, -2));
}

TEST(SegmentTree, correct_setting_after_setting_on_segment) {
    // Arrange
    SegmentTree a(0, 6);
    // Act
    a.SetValue(0, 2, 7);
    a.SetValue(1, 3);
    // Assert
    EXPECT_EQ(17, a.GetValue(0, 4));
}

TEST(SegmentTree, can_create_very_big_tree) {
    // Arrange & Act & Assert
    ASSERT_NO_THROW(SegmentTree a(0, INT_MAX));
}

TEST(SegmentTree, can_add_to_very_big_tree) {
    // Arrange
    SegmentTree a(0, INT_MAX);
    // Act & Assert
    ASSERT_NO_THROW(a.AddValue(457876, 4));
}

TEST(SegmentTree, can_add_to_very_big_tree_on_segment) {
    // Arrange
    SegmentTree a(0, INT_MAX);
    // Act & Assert
    ASSERT_NO_THROW(a.AddValue(457876, 1000000000, 4));
}

TEST(SegmentTree, can_set_to_very_big_tree_on_segment) {
    // Arrange
    SegmentTree a(0, INT_MAX);
    // Act & Assert
    ASSERT_NO_THROW(a.SetValue(457876, 1000000000, 4));
}

TEST(SegmentTree, can_set_to_very_big_tree) {
    // Arrange
    SegmentTree a(0, INT_MAX);
    // Act & Assert
    ASSERT_NO_THROW(a.SetValue(457876, 76));
}

TEST(SegmentTree, can_get_from_very_big_tree) {
    // Arrange
    SegmentTree a(0, INT_MAX);
    // Act
    a.AddValue(457876, 4);
    // Assert
    EXPECT_EQ(4, a.GetValue(0, 500000));
}

TEST(SegmentTree, can_create_very_small_tree) {
    // Arrange & Act & Assert
    ASSERT_NO_THROW(SegmentTree a(0, 0));
}

TEST(SegmentTree, can_add_to_very_small_tree) {
    // Arrange
    SegmentTree a(0, 0);
    // Act & Assert
    ASSERT_NO_THROW(a.AddValue(0, 5));
}

TEST(SegmentTree, can_set_to_very_small_tree) {
    // Arrange
    SegmentTree a(0, 0);
    // Act & Assert
    ASSERT_NO_THROW(a.SetValue(0, 5));
}

TEST(SegmentTree, can_get_from_very_small_tree) {
    // Arrange
    SegmentTree a(0, 0);
    // Act & Assert
    EXPECT_EQ(0, a.GetValue(0));
}

TEST(SegmentTree, can_get_added_value_from_very_small_tree) {
    // Arrange
    SegmentTree a(0, 0);
    // Act
    a.AddValue(0, 7);
    // Assert
    EXPECT_EQ(7, a.GetValue(0));
}

TEST(SegmentTree, difficult_test_for_adding) {
    // Arrange
    SegmentTree a(0, 9);
    // Act
    a.SetValue(4, 7, 5);
    for (int i = 0; i < 10; ++i)
        a.AddValue(i, 9, i);
    // Assert
    EXPECT_EQ(185, a.GetValue(0, 9));
}

TEST(SegmentTree, difficult_test_for_setting) {
    // Arrange
    SegmentTree a(0, 9);
    // Act
    for (int i = 0; i < 10; ++i)
        a.SetValue(i, 9, i);
    a.AddValue(4, 6, 5);
    // Assert
    EXPECT_EQ(60, a.GetValue(0, 9));
}

TEST(SegmentTree, copyed_tree_equal_to_original) {
    // Arrange
    SegmentTree a(0, 9);
    bool flag = true;
    for (int i = 0; i < 10; ++i)
        a.SetValue(i, 9, i);
    a.AddValue(4, 6, 5);
    // Act
    SegmentTree b(a);
    for (int i = 0; i < 10; ++i)
        if (a.GetValue(i) != b.GetValue(i))
            flag = false;
    // Assert
    EXPECT_TRUE(flag);
}

TEST(SegmentTree, assigned_tree_equal_to_original) {
    // Arrange
    SegmentTree a(0, 9);
    SegmentTree b(0, 2);
    bool flag = true;
    for (int i = 0; i < 10; ++i)
        a.SetValue(i, 9, i);
    a.AddValue(4, 6, 5);
    // Act
    b = a;
    for (int i = 0; i < 10; ++i)
        if (a.GetValue(i) != b.GetValue(i))
            flag = false;
    // Assert
    EXPECT_TRUE(flag);
}

TEST(SegmentTree, can_assign_to_itself) {
    // Arrange
    SegmentTree a(0, 9);
    // Act & Assert
    ASSERT_NO_THROW(a = a);
}

TEST(SegmentTree, can_assign_filled_tree) {
    // Arrange
    SegmentTree a(0, 9);
    SegmentTree b(0, 2);
    for (int i = 0; i < 10; ++i)
        a.SetValue(i, 9, i);
    a.AddValue(4, 6, 5);
    // Act & Assert
    ASSERT_NO_THROW(a = b);
}

TEST(SegmentTree, correct_get_after_set_on_segment) {
    // Arrange
    SegmentTree a(0, 4);
    bool flag = true;
    for (int i = 0; i < 5; ++i)
        a.SetValue(i, i);
    // Act
    a.SetValue(3, 4, 10);
    // Assert
    EXPECT_EQ(10, a.GetValue(3));
}

TEST(SegmentTree, cant_get_added_value_with_incorrect_barriers) {
    // Arrange
    SegmentTree a(0, 4);
    // Act & Assert
    ASSERT_ANY_THROW(a.GetValue(4, 2));
}

TEST(SegmentTree, correct_get_after_set_and_add_on_segment) {
    // Arrange
    SegmentTree a(0, 7);
    bool flag = true;
    for (int i = 0; i < 8; ++i)
        a.SetValue(i, i);
    // Act
    a.SetValue(4, 7, 10);
    a.AddValue(4, 5, 12);
    // Assert
    EXPECT_EQ(22, a.GetValue(5));
}
