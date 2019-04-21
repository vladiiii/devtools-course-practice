// Copyright 2019 Iamshchikov Ivan

#include <gtest/gtest.h>

#include "include/two_line_segments.h"

TEST(TwoLineSegmentsTest, Can_Create_Via_Default_Constructor) {
    // Arrange

    // Act & Assert
    ASSERT_NO_THROW(TwoLineSegments tls);
}

TEST(TwoLineSegmentsTest,
     Can_Get_Coordinates_Of_Lines_Created_Via_Default_Constructor) {
    // Arrange
    TwoLineSegments tls;

    // Act & Assert
    EXPECT_EQ(0, tls.getLineSegment1().p1.getX());
    EXPECT_EQ(0, tls.getLineSegment1().p1.getY());
    EXPECT_EQ(0, tls.getLineSegment1().p2.getX());
    EXPECT_EQ(0, tls.getLineSegment1().p2.getY());
    EXPECT_EQ(0, tls.getLineSegment2().p1.getX());
    EXPECT_EQ(0, tls.getLineSegment2().p1.getY());
    EXPECT_EQ(0, tls.getLineSegment2().p2.getX());
    EXPECT_EQ(0, tls.getLineSegment2().p2.getY());
}

TEST(TwoLineSegmentsTest, Can_Create_Via_Parameterized_Constructor) {
    // Arrange
    LineSegment ls1;
    ls1.p1.SetCoordinatesToPoint(0, 0);
    ls1.p2.SetCoordinatesToPoint(5, 0);

    LineSegment ls2;
    ls2.p1.SetCoordinatesToPoint(5, 0);
    ls2.p2.SetCoordinatesToPoint(0, 7);

    // Act & Assert
    ASSERT_NO_THROW(TwoLineSegments tls(ls1, ls2));
}

TEST(TwoLineSegmentsTest,
     Can_Get_Coordinates_Of_Lines_Created_Via_Parameterized_Constructor) {
    // Arrange
    LineSegment ls1;
    ls1.p1.SetCoordinatesToPoint(0, 0);
    ls1.p2.SetCoordinatesToPoint(5, 0);

    LineSegment ls2;
    ls2.p1.SetCoordinatesToPoint(5, 0);
    ls2.p2.SetCoordinatesToPoint(0, 7);

    // Act
    TwoLineSegments tls(ls1, ls2);

    // Assert
    EXPECT_EQ(0, tls.getLineSegment1().p1.getX());
    EXPECT_EQ(0, tls.getLineSegment1().p1.getY());
    EXPECT_EQ(5, tls.getLineSegment1().p2.getX());
    EXPECT_EQ(0, tls.getLineSegment1().p2.getY());
    EXPECT_EQ(5, tls.getLineSegment2().p1.getX());
    EXPECT_EQ(0, tls.getLineSegment2().p1.getY());
    EXPECT_EQ(0, tls.getLineSegment2().p2.getX());
    EXPECT_EQ(7, tls.getLineSegment2().p2.getY());
}

TEST(TwoLineSegmentsTest, Can_Create_Via_Copy_Constructor) {
    // Arrange
    LineSegment ls1;
    ls1.p1.SetCoordinatesToPoint(0, 0);
    ls1.p2.SetCoordinatesToPoint(5, 0);

    LineSegment ls2;
    ls2.p1.SetCoordinatesToPoint(5, 0);
    ls2.p2.SetCoordinatesToPoint(0, 7);

    TwoLineSegments tls(ls1, ls2);

    // Act & Assert
    ASSERT_NO_THROW(TwoLineSegments(tls));
}

TEST(TwoLineSegmentsTest,
     Can_Get_Coordinates_Of_Lines_Created_Via_Copy_Constructor) {
    // Arrange
    LineSegment ls1;
    ls1.p1.SetCoordinatesToPoint(1, 2);
    ls1.p2.SetCoordinatesToPoint(5, 6);

    LineSegment ls2;
    ls2.p1.SetCoordinatesToPoint(5, 0);
    ls2.p2.SetCoordinatesToPoint(3, 7);

    TwoLineSegments tls1(ls1, ls2);

    // Act
    TwoLineSegments tls2(tls1);

    // Assert
    EXPECT_EQ(1, tls2.getLineSegment1().p1.getX());
    EXPECT_EQ(2, tls2.getLineSegment1().p1.getY());
    EXPECT_EQ(5, tls2.getLineSegment1().p2.getX());
    EXPECT_EQ(6, tls2.getLineSegment1().p2.getY());
    EXPECT_EQ(5, tls2.getLineSegment2().p1.getX());
    EXPECT_EQ(0, tls2.getLineSegment2().p1.getY());
    EXPECT_EQ(3, tls2.getLineSegment2().p2.getX());
    EXPECT_EQ(7, tls2.getLineSegment2().p2.getY());
}

TEST(TwoLineSegmentsTest, Can_Set_And_Get_Coorditanes_Of_First_Line_Segment) {
    // Arrange
    Point p1, p2;
    p1.x = 5;
    p1.y = 7;
    p2.x = -1;
    p2.y = -8;
    TwoLineSegments tls;

    // Act
    tls.setCoordinatesToFirstLine(p1, p2);

    // Assert
    EXPECT_EQ(5, tls.getLineSegment1().p1.getX());
    EXPECT_EQ(7, tls.getLineSegment1().p1.getY());
    EXPECT_EQ(-1, tls.getLineSegment1().p2.getX());
    EXPECT_EQ(-8, tls.getLineSegment1().p2.getY());
}

TEST(TwoLineSegmentsTest,
     Can_Set_And_Get_Coorditanes_Of_Second_Line_Segment) {
    // Arrange
    Point p1, p2;
    p1.x = 5;
    p1.y = 7;
    p2.x = -3;
    p2.y = -8;
    TwoLineSegments tls;

    // Act
    tls.setCoordinatesToSecondLine(p1, p2);

    // Assert
    EXPECT_EQ(5, tls.getLineSegment2().p1.getX());
    EXPECT_EQ(7, tls.getLineSegment2().p1.getY());
    EXPECT_EQ(-3, tls.getLineSegment2().p2.getX());
    EXPECT_EQ(-8, tls.getLineSegment2().p2.getY());
}

TEST(TwoLineSegmentsTest, Testing_Of_Are_Intersect_Function_v1) {
    // Arrange
    Point p1, p2, p3, p4;
    p1.x = 0;
    p1.y = 0;
    p2.x = 10;
    p2.y = 0;
    p3.x = 0;
    p3.y = 3;
    p4.x = 10;
    p4.y = 3;
    TwoLineSegments tls;

    tls.setCoordinatesToFirstLine(p1, p2);
    tls.setCoordinatesToSecondLine(p3, p4);

    // Act & Assert
    EXPECT_EQ(0, tls.areIntersect());
}

TEST(TwoLineSegmentsTest, Testing_Of_Are_Intersect_Function_v2) {
    // Arrange
    Point p1, p2, p3, p4;
    p1.x = 0;
    p1.y = 0;
    p2.x = 10;
    p2.y = 0;
    p3.x = 2;
    p3.y = 1;
    p4.x = 2;
    p4.y = 5;
    TwoLineSegments tls;

    tls.setCoordinatesToFirstLine(p1, p2);
    tls.setCoordinatesToSecondLine(p3, p4);

    // Act & Assert
    EXPECT_EQ(0, tls.areIntersect());
}

TEST(TwoLineSegmentsTest, Testing_Of_Are_Intersect_Function_v3) {
    // Arrange
    Point p1, p2, p3, p4;
    p1.x = 0;
    p1.y = 0;
    p2.x = 10;
    p2.y = 0;
    p3.x = 2;
    p3.y = 0;
    p4.x = 2;
    p4.y = 5;
    TwoLineSegments tls;

    tls.setCoordinatesToFirstLine(p1, p2);
    tls.setCoordinatesToSecondLine(p3, p4);

    // Act & Assert
    EXPECT_EQ(1, tls.areIntersect());
}

TEST(TwoLineSegmentsTest, Testing_Of_Are_Intersect_Function_v4) {
    // Arrange
    Point p1, p2, p3, p4;
    p1.x = 0;
    p1.y = 0;
    p2.x = 10;
    p2.y = 0;
    p3.x = 2;
    p3.y = -5;
    p4.x = 2;
    p4.y = 5;
    TwoLineSegments tls;

    tls.setCoordinatesToFirstLine(p1, p2);
    tls.setCoordinatesToSecondLine(p3, p4);

    // Act & Assert
    EXPECT_EQ(1, tls.areIntersect());
}

TEST(TwoLineSegmentsTest, Testing_Of_Are_Intersect_Function_v5) {
    // Arrange
    Point p1, p2, p3, p4;
    p1.x = 0;
    p1.y = 0;
    p2.x = 10;
    p2.y = 0;
    p3.x = 2;
    p3.y = 1;
    p4.x = 2;
    p4.y = 1;
    TwoLineSegments tls;

    tls.setCoordinatesToFirstLine(p1, p2);
    tls.setCoordinatesToSecondLine(p3, p4);

    // Act & Assert
    EXPECT_EQ(0, tls.areIntersect());
}

TEST(TwoLineSegmentsTest, Testing_Of_Are_Intersect_Function_v6) {
    // Arrange
    Point p1, p2, p3, p4;
    p1.x = 0;
    p1.y = 0;
    p2.x = 10;
    p2.y = 0;
    p3.x = 5;
    p3.y = 0;
    p4.x = 5;
    p4.y = 0;
    TwoLineSegments tls;

    tls.setCoordinatesToFirstLine(p1, p2);
    tls.setCoordinatesToSecondLine(p3, p4);

    // Act & Assert
    EXPECT_EQ(1, tls.areIntersect());
}

TEST(TwoLineSegmentsTest, Testing_Of_Are_Intersect_Function_v7) {
    // Arrange
    Point p1, p2, p3, p4;
    p1.x = 1;
    p1.y = 2;
    p2.x = 1;
    p2.y = 2;
    p3.x = 1;
    p3.y = 2;
    p4.x = 1;
    p4.y = 2;
    TwoLineSegments tls;

    tls.setCoordinatesToFirstLine(p1, p2);
    tls.setCoordinatesToSecondLine(p3, p4);

    // Act & Assert
    EXPECT_EQ(1, tls.areIntersect());
}

TEST(TwoLineSegmentsTest, Testing_Of_Are_Intersect_Function_v8) {
    // Arrange
    Point p1, p2, p3, p4;
    p1.x = 1;
    p1.y = 2;
    p2.x = 1;
    p2.y = 2;
    p3.x = 5;
    p3.y = 0;
    p4.x = 5;
    p4.y = 0;
    TwoLineSegments tls;

    tls.setCoordinatesToFirstLine(p1, p2);
    tls.setCoordinatesToSecondLine(p3, p4);

    // Act & Assert
    EXPECT_EQ(0, tls.areIntersect());
}
