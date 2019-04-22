// Copyright 2019 Korobeinikov Aleksey

#include <gtest/gtest.h>

#include <vector>

#include "include/diameter.h"


TEST(DiameterTest,
    check_correctness_of_DiameterOfGraph_with_equal_edges) {
    // Arrange
    int n = 8;
    std::vector <std::vector<int>> v;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        v[i].resize(n);
        for (int j = 0; j < n; ++j) {
            if (i == j) v[i][j] = 0;
            else
                v[i][j] = -1;
        }
    }
    v[0][1] = 1; v[1][0] = 1; v[1][3] = 1; v[2][6] = 1;
    v[3][4] = 1; v[6][7] = 1; v[7][6] = 1; v[7][4] = 1;
    v[0][5] = 1; v[1][2] = 1; v[2][1] = 1; v[3][1] = 1;
    v[4][5] = 1; v[4][7] = 1; v[5][0] = 1; v[5][4] = 1;
    v[6][2] = 1; v[4][3] = 1;
    Graph g(std::move(v), n);

    // Act
    int ans = g.DiameterOfGraph();

    // Assert
    EXPECT_EQ(3, ans);
}

TEST(DiameterTest,
    check_correctness_of_DiameterOfGraph_with_different_edges) {
    // Arrange
    int n = 8;
    std::vector <std::vector<int>> v;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        v[i].resize(n);
        for (int j = 0; j < n; ++j) {
            if (i == j) v[i][j] = 0;
            else
                v[i][j] = -1;
        }
    }
    v[0][1] = 3; v[1][0] = 3; v[1][3] = 1; v[2][6] = 5;
    v[3][4] = 4; v[6][7] = 7; v[7][6] = 7; v[7][4] = 2;
    v[0][5] = 6; v[1][2] = 9; v[2][1] = 9; v[3][1] = 1;
    v[4][5] = 1; v[4][7] = 2; v[5][0] = 6; v[5][4] = 1;
    v[6][2] = 5; v[4][3] = 4;
    Graph g(std::move(v), n);

    // Act
    int ans = g.DiameterOfGraph();

    // Assert
    EXPECT_EQ(16, ans);
}

TEST(DiameterTest,
    check_correctness_of_diameter_of_tree_with_equal_edges) {
    // Arrange
    int n = 8;
    std::vector <std::vector<int>> v;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        v[i].resize(n);
        for (int j = 0; j < n; ++j) {
            if (i == j) v[i][j] = 0;
            else
                v[i][j] = -1;
        }
    }
    v[0][2] = 1; v[2][0] = 1; v[1][2] = 1; v[2][1] = 1;
    v[2][3] = 1; v[3][2] = 1; v[3][4] = 1; v[4][3] = 1;
    v[2][5] = 1; v[5][2] = 1; v[5][6] = 1; v[6][5] = 1;
    v[5][7] = 1; v[7][5] = 1;
    Graph g(std::move(v), n);

    // Act
    int ans = g.DiameterOfGraph();

    // Assert
    EXPECT_EQ(4, ans);
}

TEST(DiameterTest,
    check_correctness_of_diameter_of_tree_with_different_edges) {
    // Arrange
    int n = 8;
    std::vector <std::vector<int>> v;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        v[i].resize(n);
        for (int j = 0; j < n; ++j) {
            if (i == j) v[i][j] = 0;
            else
                v[i][j] = -1;
        }
    }
    v[0][2] = 2; v[2][0] = 2; v[1][2] = 4; v[2][1] = 4;
    v[2][3] = 3; v[3][2] = 3; v[3][4] = 2; v[4][3] = 2;
    v[2][5] = 2; v[5][2] = 2; v[5][6] = 2; v[6][5] = 2;
    v[5][7] = 1; v[7][5] = 1;
    Graph g(std::move(v), n);

    // Act
    int ans = g.DiameterOfGraph();

    // Assert
    EXPECT_EQ(9, ans);
}

TEST(DiameterTest,
    check_correctness_of_copy_constructor) {
    // Arrange
    int n = 8;
    std::vector <std::vector<int>> v;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        v[i].resize(n);
        for (int j = 0; j < n; ++j) {
            if (i == j) v[i][j] = 0;
            else
                v[i][j] = -1;
        }
    }
    v[0][2] = 2; v[2][0] = 2; v[1][2] = 4; v[2][1] = 4;
    v[2][3] = 3; v[3][2] = 3; v[3][4] = 2; v[4][3] = 2;
    v[2][5] = 2; v[5][2] = 2; v[5][6] = 2; v[6][5] = 2;
    v[5][7] = 1; v[7][5] = 1;
    Graph a(std::move(v), n);
    Graph b(a);

    // Act
    int ans1 = a.DiameterOfGraph();
    int ans2 = b.DiameterOfGraph();

    // Assert
    EXPECT_EQ(1, ans1 == ans2);
}

TEST(DiameterTest,
    check_correctness_of_equality_operator) {
    // Arrange
    int n = 8;
    std::vector <std::vector<int>> v;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        v[i].resize(n);
        for (int j = 0; j < n; ++j) {
            if (i == j) v[i][j] = 0;
            else
                v[i][j] = -1;
        }
    }
    v[0][2] = 1; v[2][0] = 1; v[1][2] = 1; v[2][1] = 1;
    v[2][3] = 1; v[3][2] = 1; v[3][4] = 1; v[4][3] = 1;
    v[2][5] = 1; v[5][2] = 1; v[5][6] = 1; v[6][5] = 1;
    v[5][7] = 1; v[7][5] = 1;
    Graph a(std::move(v), n);
    Graph b;

    // Act
    int ans1 = a.DiameterOfGraph();
    b = a;
    int ans2 = b.DiameterOfGraph();

    // Assert
    EXPECT_EQ(1, ans1 == ans2);
}
