// Copyright 2019 Savkin Yuriy

#include <gtest/gtest.h>

#include "include/segment_tree.h"
#include <climits>

TEST(segment_tree, can_create_segment_tree)
{
    ASSERT_NO_THROW(segment_tree a(1, 2));
}

TEST(segment_tree, can_add_value)
{
    segment_tree a(1, 2);

    ASSERT_NO_THROW(a.add_value(1, 9));
}

TEST(segment_tree, cant_add_value_to_wrong_position)
{
    segment_tree a(1, 2);

    ASSERT_ANY_THROW(a.add_value(3, 9));
}

TEST(segment_tree, can_add_to_segment)
{
    segment_tree a(1, 2);

    ASSERT_NO_THROW(a.add_value(1, 2, 9));
}

TEST(segment_tree, cant_add_out_of_range)
{
    segment_tree a(1, 2);

    ASSERT_ANY_THROW(a.add_value(1, 3, 9));
}

TEST(segment_tree, cant_add_with_incorrect_barriers)
{
    segment_tree a(1, 2);

    ASSERT_ANY_THROW(a.add_value(2, 1, 9));
}

TEST(segment_tree, can_set_value)
{
    segment_tree a(1, 2);

    ASSERT_NO_THROW(a.set_value(1, 9));
}

TEST(segment_tree, can_set_on_segment)
{
    segment_tree a(1, 2);

    ASSERT_NO_THROW(a.set_value(1, 2, 9));
}

TEST(segment_tree, cant_set_out_of_range)
{
    segment_tree a(1, 2);

    ASSERT_ANY_THROW(a.set_value(0, 2, 9));
}

TEST(segment_tree, cant_set_value_on_wrong_position)
{
    segment_tree a(1, 2);

    ASSERT_ANY_THROW(a.set_value(0, 9));
}

TEST(segment_tree, cant_set_with_incorrect_barriers)
{
    segment_tree a(1, 2);

    ASSERT_ANY_THROW(a.set_value(2, 1, 9));
}

TEST(segment_tree, can_get_value)
{
    segment_tree a(1, 2);

    ASSERT_NO_THROW(a.get_value(2));
}

TEST(segment_tree, cant_get_value_on_wrong_position)
{
    segment_tree a(1, 2);

    ASSERT_ANY_THROW(a.get_value(3));
}

TEST(segment_tree, can_get_on_segment)
{
    segment_tree a(1, 2);

    ASSERT_NO_THROW(a.get_value(1, 2));
}

TEST(segment_tree, cant_get_out_of_range)
{
    segment_tree a(1, 2);

    ASSERT_ANY_THROW(a.get_value(1, 3));
}

TEST(segment_tree, cant_get_with_incorrect_barriers)
{
    segment_tree a(1, 2);

    ASSERT_ANY_THROW(a.get_value(1, 3));
}

TEST(segment_tree, can_get_base_element)
{
    segment_tree a(1, 2);

    EXPECT_EQ(0, a.get_base_elem());
}

TEST(segment_tree, can_get_left_barrier)
{
    segment_tree a(1, 2);

    EXPECT_EQ(1, a.get_left_barr());
}

TEST(segment_tree, can_get_right_barrier)
{
    segment_tree a(1, 2);

    EXPECT_EQ(2, a.get_right_barr());
}

TEST(segment_tree, can_create_from_other)
{
    segment_tree a(1, 2);

    ASSERT_NO_THROW(segment_tree b(a));
}

TEST(segment_tree, can_assign_from_other)
{
    segment_tree a(1, 2), b(5, 9);

    ASSERT_NO_THROW(a = b);
}

TEST(segment_tree, get_value_is_correct)
{
    segment_tree a(1, 2);

    EXPECT_EQ(a.get_base_elem(), a.get_value(1));
}

TEST(segment_tree, get_value_on_segment_is_correct)
{
    segment_tree a(1, 2);

    EXPECT_EQ(a.get_base_elem(), a.get_value(1, 2));
}

TEST(segment_tree, can_get_added_value)
{
    segment_tree a(1, 2);

    a.add_value(1, 7);

    EXPECT_EQ(7, a.get_value(1));
}

TEST(segment_tree, added_value_affects_segment)
{
    segment_tree a(1, 2);

    a.add_value(1, 7);

    EXPECT_EQ(7, a.get_value(1, 2));
}

TEST(segment_tree, added_value_dont_affects_other_value)
{
    segment_tree a(1, 2);

    a.add_value(1, 7);

    EXPECT_EQ(0, a.get_value(2));
}

TEST(segment_tree, can_get_setted_value)
{
    segment_tree a(1, 2);

    a.set_value(1, 7);

    EXPECT_EQ(7, a.get_value(1));
}

TEST(segment_tree, setted_value_affects_segment)
{
    segment_tree a(1, 2);

    a.set_value(1, 7);

    EXPECT_EQ(7, a.get_value(1, 2));
}

TEST(segment_tree, setted_value_dont_affects_other_value)
{
    segment_tree a(1, 2);

    a.set_value(1, 7);

    EXPECT_EQ(0, a.get_value(2));
}

TEST(segment_tree, can_get_added_on_segment_value)
{
    segment_tree a(1, 7);

    a.add_value(1, 4, 7);

    EXPECT_EQ(7, a.get_value(2));
}

TEST(segment_tree, added_on_segment_value_affects_segment)
{
    segment_tree a(1, 7);

    a.add_value(1, 4, 7);

    EXPECT_EQ(14, a.get_value(3, 6));
}

TEST(segment_tree, added_on_segment_value_dont_affects_other_value)
{
    segment_tree a(1, 7);

    a.add_value(1, 4, 7);

    EXPECT_EQ(0, a.get_value(5));
}

TEST(segment_tree, can_get_setted_on_segment_value)
{
    segment_tree a(1, 7);

    a.set_value(1, 4, 7);

    EXPECT_EQ(7, a.get_value(4));
}

TEST(segment_tree, setted_on_segment_value_affects_segment)
{
    segment_tree a(1, 7);

    a.set_value(1, 4, 7);

    EXPECT_EQ(21, a.get_value(2, 4));
}

TEST(segment_tree, setted_on_segment_value_dont_affects_other_value)
{
    segment_tree a(1, 7);

    a.set_value(1, 4, 7);

    EXPECT_EQ(0, a.get_value(5, 7));
}

TEST(segment_tree, tree_work_with_other_functions)
{
    segment_tree a(1, 7, [](int a, int b, int c)->int {
        if (a < b)
            return a;
        return b;
    }, INT_MAX);

    a.add_value(1, 8);
    a.add_value(2, 5, 7);

    EXPECT_EQ(7, a.get_value(1, 2));
}

TEST(segment_tree, correct_adding_after_setting)
{
    segment_tree a(1, 7);

    a.set_value(4, 7);
    a.add_value(4, 3);

    EXPECT_EQ(10, a.get_value(1, 5));
}

TEST(segment_tree, correct_adding_after_setting_on_segment)
{
    segment_tree a(1, 7);

    a.set_value(1, 4, 7);
    a.add_value(2, 3, 3);

    EXPECT_EQ(34, a.get_value(1, 5));
}

TEST(segment_tree, correct_setting_after_adding)
{
    segment_tree a(-5, -2);

    a.add_value(-3, 3);
    a.set_value(-3, 7);

    EXPECT_EQ(7, a.get_value(-3));
}

TEST(segment_tree, correct_setting_after_adding_on_segment)
{
    segment_tree a(-5, -2);

    a.add_value(-4, -2, 3);
    a.set_value(-5, -3, 7);

    EXPECT_EQ(24, a.get_value(-5, -2));
}
