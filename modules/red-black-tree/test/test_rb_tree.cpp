// Copyright 2019 Timakin Nikita

#include <gtest/gtest.h>

#include <vector>

#include "include/rb_tree.h"

TEST(RedBlackTreeNodeTest, Can_Create_Node_Default) {
    ASSERT_NO_THROW(Node{});
}

TEST(RedBlackTreeNodeTest, Can_Create_Node_from_Another) {
    Node node;

    ASSERT_NO_THROW(Node{node});
}

TEST(RedBlackTreeNodeTest, Can_Assign_Node) {
    Node x(1), y(2);

    ASSERT_NO_THROW(x = y);
}

TEST(RedBlackTreeNodeTest, Assigned_Node_Equals_to_Original) {
    Node x(1);

    Node y = x;

    ASSERT_TRUE(x == y);
}

TEST(RedBlackTreeNodeTest, The_Same_Nodes_Are_Equal) {
    Node x(1), y(1);

    ASSERT_TRUE(x == y);
}

TEST(RedBlackTreeNodeTest, Different_Nodes_Are_Not_Equal) {
    Node x(1), y(2);

    ASSERT_TRUE(x != y);
}

TEST(RedBlackTreeTest, Can_Create_Tree_Default) {
    ASSERT_NO_THROW(RBTree{});
}

TEST(RedBlackTreeTest, Can_Create_Tree_from_Node) {
    Node *node = new Node{};

    ASSERT_NO_THROW(RBTree{node});
}

TEST(RedBlackTreeTest, Can_Create_Tree_from_Vector) {
    std::vector<int> vec{0, 1, 2};

    ASSERT_NO_THROW(RBTree{vec});
}

TEST(RedBlackTreeTest, Can_Get_Root) {
    Node *node = new Node(1);
    RBTree tree{node};

    ASSERT_EQ(1, tree.get_root()->value);
}

TEST(RedBlackTreeTest, Can_Get_Current) {
    Node *node = new Node(1);
    RBTree tree{node};

    tree.begin();

    ASSERT_EQ(1, tree.get_current()->value);
}

TEST(RedBlackTreeTest, Can_Find_Excisting_Item) {
    std::vector<int> vec{-10, 35, 2};
    RBTree tree{vec};

    bool is_found = tree.find(35);

    ASSERT_TRUE(is_found);
}

TEST(RedBlackTreeTest, Can_Not_Find_Nonexistent_Item) {
    std::vector<int> vec{-10, 35, 2};
    RBTree tree{vec};

    bool is_found = tree.find(0);

    ASSERT_FALSE(is_found);
}

TEST(RedBlackTreeTest, Can_Insert_New_Item) {
    std::vector<int> vec{0, 1, 2};
    RBTree tree{vec};

    Node *new_node = new Node(3);

    ASSERT_NO_THROW(tree.insert(new_node));
}

TEST(RedBlackTreeTest, Can_Not_Insert_Excisting_Item) {
    std::vector<int> vec{0, 1, 2};
    RBTree tree{vec};

    Node *excisting_node = new Node(1);

    ASSERT_ANY_THROW(tree.insert(excisting_node));
}

TEST(RedBlackTreeTest, Can_Remove_Excisting_Item) {
    std::vector<int> vec{0, 1, 2};
    RBTree tree{vec};

    ASSERT_NO_THROW(tree.remove(1));
}

TEST(RedBlackTreeTest, Can_Not_Remove_Nonexistent_Item) {
    std::vector<int> vec{0, 1, 2};
    RBTree tree{vec};

    ASSERT_ANY_THROW(tree.remove(3));
}

TEST(RedBlackTreeTest, Begin_Sets_Current_to_Smallest_Item) {
    std::vector<int> vec{10, 1, 8};
    RBTree tree{vec};

    tree.begin();

    ASSERT_EQ(1, tree.get_current()->value);
}

TEST(RedBlackTreeTest, Iterator_Represents_All_Items) {
    std::vector<int> vec{0, 1, 2};
    RBTree tree{vec};
    bool result = true;
    unsigned i = 0;

    for (tree.begin(); !tree.end(); tree.next(), ++i)
        if (vec[i] != tree.get_current()->value)
            result = false;

    result &= (i == vec.size());

    ASSERT_TRUE(result);
}
