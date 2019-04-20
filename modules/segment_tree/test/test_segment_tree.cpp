// Copyright 2019 Savkin Yuriy

#include <gtest/gtest.h>

#include "include/segment_tree.h"

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
