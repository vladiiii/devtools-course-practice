// Copyright 2019 Korobeinikov Aleksey

#include <gtest/gtest.h>

#include <vector>

#include "include/diameter.h"


TEST(Korobeinikov_Aleksey_DiameterTest,
    check_correctness_of_diameter_of_Graph_with_equal_edges) {
    // Arrange
    int n = 8;
    int **dist = new int*[n];
    for (int i = 0; i < n; ++i) dist[i] = new int[n];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            if (i == j) dist[i][j] = 0;
            else
                dist[i][j] = -1;
        }
    dist[0][1] = 1; dist[1][0] = 1; dist[1][3] = 1; dist[2][6] = 1;
    dist[3][4] = 1; dist[6][7] = 1; dist[7][6] = 1; dist[7][4] = 1;
    dist[0][5] = 1; dist[1][2] = 1; dist[2][1] = 1; dist[3][1] = 1;
    dist[4][5] = 1; dist[4][7] = 1; dist[5][0] = 1; dist[5][4] = 1;
    dist[6][2] = 1; dist[4][3] = 1;
    Graph g(&dist, n);

    // Act
    int ans = g.diameter_of_Graph();
    // g.print_dist();

    // Assert
    EXPECT_EQ(3, ans);
}

TEST(Korobeinikov_Aleksey_DiameterTest,
    check_correctness_of_diameter_of_Graph_with_different_edges) {
    // Arrange
    int n = 8;
    int **dist = new int*[n];
    for (int i = 0; i < n; ++i) dist[i] = new int[n];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            if (i == j) dist[i][j] = 0;
            else
                dist[i][j] = -1;
        }
    dist[0][1] = 3; dist[1][0] = 3; dist[1][3] = 1; dist[2][6] = 5;
    dist[3][4] = 4; dist[6][7] = 7; dist[7][6] = 7; dist[7][4] = 2;
    dist[0][5] = 6; dist[1][2] = 9; dist[2][1] = 9; dist[3][1] = 1;
    dist[4][5] = 1; dist[4][7] = 2; dist[5][0] = 6; dist[5][4] = 1;
    dist[6][2] = 5; dist[4][3] = 4;
    Graph g(&dist, n);

    // Act
    int ans = g.diameter_of_Graph();

    // Assert
    EXPECT_EQ(16, ans);
}

TEST(Korobeinikov_Aleksey_DiameterTest,
    check_correctness_of_diameter_of_tree_with_equal_edges) {
    // Arrange
    int n = 8;
    std::vector <std::vector<int>> v;
    v.resize(n);
    v[0].push_back(2); v[1].push_back(2); v[2].push_back(1); v[2].push_back(3);
    v[2].push_back(5); v[3].push_back(2); v[3].push_back(4); v[4].push_back(3);
    v[5].push_back(2); v[5].push_back(6); v[6].push_back(5); v[7].push_back(5);
    v[5].push_back(7); v[2].push_back(0);
    Graph g(v, n);

    // Act
    int ans = g.diameter_of_tree();

    // Assert
    EXPECT_EQ(4, ans);
}

TEST(Korobeinikov_Aleksey_DiameterTest,
    check_correctness_of_diameter_of_tree_with_different_edges) {
    // Arrange
    int n = 8;
    int ** dist = new int*[n];
    for (int i = 0; i < n; ++i) dist[i] = new int[n];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            if (i == j) dist[i][j] = 0;
            else
                dist[i][j] = -1;
        }
    dist[0][2] = 2; dist[2][0] = 2; dist[1][2] = 4; dist[2][1] = 4;
    dist[2][3] = 3; dist[3][2] = 3; dist[3][4] = 2; dist[4][3] = 2;
    dist[2][5] = 2; dist[5][2] = 2; dist[5][6] = 2; dist[6][5] = 2;
    dist[5][7] = 1; dist[7][5] = 1;
    Graph g(&dist, n);

    // Act
    int ans = g.diameter_of_Graph();

    // Assert
    EXPECT_EQ(9, ans);
}

TEST(Korobeinikov_Aleksey_DiameterTest,
    check_correctness_of_copy_constructor) {
    // Arrange
    int n = 8;
    int ** dist = new int*[n];
    for (int i = 0; i < n; ++i) dist[i] = new int[n];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            if (i == j) dist[i][j] = 0;
            else
                dist[i][j] = -1;
        }
    dist[0][2] = 2; dist[2][0] = 2; dist[1][2] = 4; dist[2][1] = 4;
    dist[2][3] = 3; dist[3][2] = 3; dist[3][4] = 2; dist[4][3] = 2;
    dist[2][5] = 2; dist[5][2] = 2; dist[5][6] = 2; dist[6][5] = 2;
    dist[5][7] = 1; dist[7][5] = 1;
    Graph a(&dist, n);
    Graph b(a);

    // Act
    int ans1 = a.diameter_of_Graph();
    int ans2 = b.diameter_of_Graph();

    // Assert
    EXPECT_EQ(1, ans1 == ans2);
}

TEST(Korobeinikov_Aleksey_DiameterTest,
    check_correctness_of_equality_operator) {
    // Arrange
    int n = 8;
    std::vector <std::vector<int>> v;
    v.resize(n);
    v[0].push_back(2); v[1].push_back(2); v[2].push_back(1); v[2].push_back(3);
    v[2].push_back(5); v[3].push_back(2); v[3].push_back(4); v[4].push_back(3);
    v[5].push_back(2); v[5].push_back(6); v[6].push_back(5); v[7].push_back(5);
    v[5].push_back(7); v[2].push_back(0);
    Graph a(v, n);
    Graph b;

    // Act
    int ans1 = a.diameter_of_tree();
    b = a;
    int ans2 = b.diameter_of_tree();

    // Assert
    EXPECT_EQ(1, ans1 == ans2);
}
