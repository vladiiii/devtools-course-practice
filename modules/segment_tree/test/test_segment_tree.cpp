// Copyright 2019 Savkin Yuriy

#include <gtest/gtest.h>

#include <climits>
#include "include/segment_tree.h"


TEST(segment_tree, can_create_segment_tree) {
    // Arrange & Act & Assert
    ASSERT_NO_THROW(segment_tree a(1, 2));
}

TEST(segment_tree, cant_create_segment_tree_with_wrong_barriers) {
    // Arrange & Act & Assert
    ASSERT_ANY_THROW(segment_tree a(2, 1));
}

TEST(segment_tree, can_add_value) {
    // Arrange
    segment_tree a(1, 2);
    // Act & Assert
    ASSERT_NO_THROW(a.add_value(1, 9));
}

TEST(segment_tree, cant_add_value_to_wrong_position) {
    // Arrange
    segment_tree a(1, 2);
    // Act & Assert
    ASSERT_ANY_THROW(a.add_value(3, 9));
}

TEST(segment_tree, can_add_to_segment) {
    // Arrange
    segment_tree a(1, 2);
    // Act & Assert
    ASSERT_NO_THROW(a.add_value(1, 2, 9));
}

TEST(segment_tree, cant_add_out_of_range) {
    // Arrange
    segment_tree a(1, 2);
    // Act & Assert
    ASSERT_ANY_THROW(a.add_value(1, 3, 9));
}

TEST(segment_tree, cant_add_with_incorrect_barriers) {
    // Arrange
    segment_tree a(1, 2);
    // Act & Assert
    ASSERT_ANY_THROW(a.add_value(2, 1, 9));
}

TEST(segment_tree, can_set_value) {
    // Arrange
    segment_tree a(1, 2);
    // Act & Assert
    ASSERT_NO_THROW(a.set_value(1, 9));
}

TEST(segment_tree, can_set_on_segment) {
    // Arrange
    segment_tree a(1, 2);
    // Act & Assert
    ASSERT_NO_THROW(a.set_value(1, 2, 9));
}

TEST(segment_tree, cant_set_out_of_range) {
    // Arrange
    segment_tree a(1, 2);
    // Act & Assert
    ASSERT_ANY_THROW(a.set_value(0, 2, 9));
}

TEST(segment_tree, cant_set_value_on_wrong_position) {
    // Arrange
    segment_tree a(1, 2);
    // Act & Assert
    ASSERT_ANY_THROW(a.set_value(0, 9));
}

TEST(segment_tree, cant_set_with_incorrect_barriers) {
    // Arrange
    segment_tree a(1, 2);
    // Act & Assert
    ASSERT_ANY_THROW(a.set_value(2, 1, 9));
}

TEST(segment_tree, can_get_value) {
    // Arrange
    segment_tree a(1, 2);
    // Act & Assert
    ASSERT_NO_THROW(a.get_value(2));
}

TEST(segment_tree, cant_get_value_on_wrong_position) {
    // Arrange
    segment_tree a(1, 2);
    // Act & Assert
    ASSERT_ANY_THROW(a.get_value(3));
}

TEST(segment_tree, can_get_on_segment) {
    // Arrange
    segment_tree a(1, 2);
    // Act & Assert
    ASSERT_NO_THROW(a.get_value(1, 2));
}

TEST(segment_tree, cant_get_out_of_range) {
    // Arrange
    segment_tree a(1, 2);
    // Act & Assert
    ASSERT_ANY_THROW(a.get_value(1, 3));
}

TEST(segment_tree, cant_get_with_incorrect_barriers) {
    // Arrange
    segment_tree a(1, 2);
    // Act & Assert
    ASSERT_ANY_THROW(a.get_value(1, 3));
}

TEST(segment_tree, can_get_base_element) {
    // Arrange
    segment_tree a(1, 2);
    // Act & Assert
    EXPECT_EQ(0, a.get_base_elem());
}

TEST(segment_tree, can_get_left_barrier) {
    // Arrange
    segment_tree a(1, 2);
    // Act & Assert
    EXPECT_EQ(1, a.get_left_barr());
}

TEST(segment_tree, can_get_right_barrier) {
    // Arrange
    segment_tree a(1, 2);
    // Act & Assert
    EXPECT_EQ(2, a.get_right_barr());
}

TEST(segment_tree, can_create_from_other) {
    // Arrange
    segment_tree a(1, 2);
    // Act & Assert
    ASSERT_NO_THROW(segment_tree b(a));
}

TEST(segment_tree, can_assign_from_other) {
    // Arrange
    segment_tree a(1, 2), b(5, 9);
    // Act & Assert
    ASSERT_NO_THROW(a = b);
}

TEST(segment_tree, get_value_is_correct) {
    // Arrange
    segment_tree a(1, 2);
    // Act & Assert
    EXPECT_EQ(a.get_base_elem(), a.get_value(1));
}

TEST(segment_tree, get_value_on_segment_is_correct) {
    // Arrange
    segment_tree a(1, 2);
    // Act & Assert
    EXPECT_EQ(a.get_base_elem(), a.get_value(1, 2));
}

TEST(segment_tree, can_get_added_value) {
    // Arrange
    segment_tree a(1, 2);
    // Act
    a.add_value(1, 7);
    // Assert
    EXPECT_EQ(7, a.get_value(1));
}

TEST(segment_tree, added_value_affects_segment) {
    // Arrange
    segment_tree a(1, 2);
    // Act
    a.add_value(1, 7);
    // Assert
    EXPECT_EQ(7, a.get_value(1, 2));
}

TEST(segment_tree, added_value_dont_affects_other_value) {
    // Arrange
    segment_tree a(1, 2);
    // Act
    a.add_value(1, 7);
    // Assert
    EXPECT_EQ(0, a.get_value(2));
}

TEST(segment_tree, can_get_setted_value) {
    // Arrange
    segment_tree a(1, 2);
    // Act
    a.set_value(1, 7);
    // Assert
    EXPECT_EQ(7, a.get_value(1));
}

TEST(segment_tree, setted_value_affects_segment) {
    // Arrange
    segment_tree a(1, 2);
    // Act
    a.set_value(1, 7);
    // Assert
    EXPECT_EQ(7, a.get_value(1, 2));
}

TEST(segment_tree, setted_value_dont_affects_other_value) {
    // Arrange
    segment_tree a(1, 2);
    // Act
    a.set_value(1, 7);
    // Assert
    EXPECT_EQ(0, a.get_value(2));
}

TEST(segment_tree, can_get_added_on_segment_value) {
    // Arrange
    segment_tree a(1, 7);
    // Act
    a.add_value(1, 4, 7);
    // Assert
    EXPECT_EQ(7, a.get_value(2));
}

TEST(segment_tree, added_on_segment_value_affects_segment) {
    // Arrange
    segment_tree a(1, 7);
    // Act
    a.add_value(1, 4, 7);
    // Assert
    EXPECT_EQ(14, a.get_value(3, 6));
}

TEST(segment_tree, added_on_segment_value_dont_affects_other_value) {
    // Arrange
    segment_tree a(1, 7);
    // Act
    a.add_value(1, 4, 7);
    // Assert
    EXPECT_EQ(0, a.get_value(5));
}

TEST(segment_tree, can_get_setted_on_segment_value) {
    // Arrange
    segment_tree a(1, 7);
    // Act
    a.set_value(1, 4, 7);
    // Assert
    EXPECT_EQ(7, a.get_value(4));
}

TEST(segment_tree, setted_on_segment_value_affects_segment) {
    // Arrange
    segment_tree a(1, 7);
    // Act
    a.set_value(1, 4, 7);
    // Assert
    EXPECT_EQ(21, a.get_value(2, 4));
}

TEST(segment_tree, setted_on_segment_value_dont_affects_other_value) {
    // Arrange
    segment_tree a(1, 7);
    // Act
    a.set_value(1, 4, 7);
    // Assert
    EXPECT_EQ(0, a.get_value(5, 7));
}

TEST(segment_tree, tree_work_with_other_functions) {
    // Arrange
    segment_tree a(1, 7, [](int a, int b, int c)->int {
        if (a < b)
            return a;
        return b;
    }, INT_MAX);
    // Act
    a.add_value(1, 8);
    a.add_value(2, 5, 7);
    // Assert
    EXPECT_EQ(7, a.get_value(1, 2));
}

TEST(segment_tree, correct_adding_after_setting) {
    // Arrange
    segment_tree a(1, 7);
    // Act
    a.set_value(4, 7);
    a.add_value(4, 3);
    // Assert
    EXPECT_EQ(10, a.get_value(1, 5));
}

TEST(segment_tree, correct_adding_after_setting_on_segment) {
    // Arrange
    segment_tree a(1, 7);
    // Act
    a.set_value(1, 4, 7);
    a.add_value(2, 3, 3);
    // Assert
    EXPECT_EQ(34, a.get_value(1, 5));
}

TEST(segment_tree, correct_setting_after_adding) {
    // Arrange
    segment_tree a(-5, -2);
    // Act
    a.add_value(-3, 3);
    a.set_value(-3, 7);
    // Assert
    EXPECT_EQ(7, a.get_value(-3));
}

TEST(segment_tree, correct_setting_after_adding_on_segment) {
    // Arrange
    segment_tree a(-5, -2);
    // Act
    a.add_value(-4, -2, 3);
    a.set_value(-5, -3, 7);
    // Assert
    EXPECT_EQ(24, a.get_value(-5, -2));
}

TEST(segment_tree, correct_setting_after_setting_on_segment) {
    // Arrange
    segment_tree a(0, 6);
    // Act
    a.set_value(0, 2, 7);
    a.set_value(1, 3);
    // Assert
    EXPECT_EQ(17, a.get_value(0, 4));
}

TEST(segment_tree, can_create_very_big_tree) {
    // Arrange & Act & Assert
    ASSERT_NO_THROW(segment_tree a(0, INT_MAX));
}

TEST(segment_tree, can_add_to_very_big_tree) {
    // Arrange
    segment_tree a(0, INT_MAX);
    // Act & Assert
    ASSERT_NO_THROW(a.add_value(457876, 4));
}

TEST(segment_tree, can_add_to_very_big_tree_on_segment) {
    // Arrange
    segment_tree a(0, INT_MAX);
    // Act & Assert
    ASSERT_NO_THROW(a.add_value(457876, 1000000000, 4));
}

TEST(segment_tree, can_set_to_very_big_tree_on_segment) {
    // Arrange
    segment_tree a(0, INT_MAX);
    // Act & Assert
    ASSERT_NO_THROW(a.set_value(457876, 1000000000, 4));
}

TEST(segment_tree, can_set_to_very_big_tree) {
    // Arrange
    segment_tree a(0, INT_MAX);
    // Act & Assert
    ASSERT_NO_THROW(a.set_value(457876, 76));
}

TEST(segment_tree, can_get_from_very_big_tree) {
    // Arrange
    segment_tree a(0, INT_MAX);
    // Act
    a.add_value(457876, 4);
    // Assert
    EXPECT_EQ(4, a.get_value(0, 500000));
}

TEST(segment_tree, can_create_very_small_tree) {
    // Arrange & Act & Assert
    ASSERT_NO_THROW(segment_tree a(0, 0));
}

TEST(segment_tree, can_add_to_very_small_tree) {
    // Arrange
    segment_tree a(0, 0);
    // Act & Assert
    ASSERT_NO_THROW(a.add_value(0, 5));
}

TEST(segment_tree, can_set_to_very_small_tree) {
    // Arrange
    segment_tree a(0, 0);
    // Act & Assert
    ASSERT_NO_THROW(a.set_value(0, 5));
}

TEST(segment_tree, can_get_from_very_small_tree) {
    // Arrange
    segment_tree a(0, 0);
    // Act & Assert
    EXPECT_EQ(0, a.get_value(0));
}

TEST(segment_tree, can_get_added_value_from_very_small_tree) {
    // Arrange
    segment_tree a(0, 0);
    // Act
    a.add_value(0, 7);
    // Assert
    EXPECT_EQ(7, a.get_value(0));
}

TEST(segment_tree, difficult_test_for_adding) {
    // Arrange
    segment_tree a(0, 9);
    // Act
    a.set_value(4, 7, 5);
    for (int i = 0; i < 10; ++i)
        a.add_value(i, 9, i);
    // Assert
    EXPECT_EQ(185, a.get_value(0, 9));
}

TEST(segment_tree, difficult_test_for_setting) {
    // Arrange
    segment_tree a(0, 9);
    // Act
    for (int i = 0; i < 10; ++i)
        a.set_value(i, 9, i);
    a.add_value(4, 6, 5);
    // Assert
    EXPECT_EQ(60, a.get_value(0, 9));
}

TEST(segment_tree, copyed_tree_equal_to_original) {
    // Arrange
    segment_tree a(0, 9);
    bool flag = true;
    for (int i = 0; i < 10; ++i)
        a.set_value(i, 9, i);
    a.add_value(4, 6, 5);
    // Act
    segment_tree b(a);
    for (int i = 0; i < 10; ++i)
        if (a.get_value(i) != b.get_value(i))
            flag = false;
    // Assert
    EXPECT_TRUE(flag);
}

TEST(segment_tree, assigned_tree_equal_to_original) {
    // Arrange
    segment_tree a(0, 9);
    segment_tree b(0, 2);
    bool flag = true;
    for (int i = 0; i < 10; ++i)
        a.set_value(i, 9, i);
    a.add_value(4, 6, 5);
    // Act
    b = a;
    for (int i = 0; i < 10; ++i)
        if (a.get_value(i) != b.get_value(i))
            flag = false;
    // Assert
    EXPECT_TRUE(flag);
}

TEST(segment_tree, can_assign_to_itself) {
    // Arrange
    segment_tree a(0, 9);
    // Act & Assert
    ASSERT_NO_THROW(a = a);
}

TEST(segment_tree, can_assign_filled_tree) {
    // Arrange
    segment_tree a(0, 9);
    segment_tree b(0, 2);
    for (int i = 0; i < 10; ++i)
        a.set_value(i, 9, i);
    a.add_value(4, 6, 5);
    // Act & Assert
    ASSERT_NO_THROW(a = b);
}

TEST(segment_tree, correct_get_after_set_on_segment) {
    // Arrange
    segment_tree a(0, 4);
    bool flag = true;
    for (int i = 0; i < 5; ++i)
        a.set_value(i, i);
    // Act
    a.set_value(3, 4, 10);
    // Assert
    EXPECT_EQ(10, a.get_value(3));
}

TEST(segment_tree, cant_get_added_value_with_incorrect_barriers) {
    // Arrange
    segment_tree a(0, 4);
    // Act & Assert
    ASSERT_ANY_THROW(a.get_value(4, 2));
}
