// Copyright 2019 Iamshchikov Ivan

#include "include/two_line_segments.h"
#include <algorithm>

TwoLineSegments::TwoLineSegments() {
    ls1_.p1.SetCoordinatesToPoint(0, 0);
    ls1_.p2.SetCoordinatesToPoint(0, 0);
    ls2_.p1.SetCoordinatesToPoint(0, 0);
    ls2_.p2.SetCoordinatesToPoint(0, 0);
}

TwoLineSegments::TwoLineSegments(const LineSegment _ls1,
                                 const LineSegment _ls2) {
    ls1_.p1.SetCoordinatesToPoint(_ls1.p1.getX(), _ls1.p1.getY());
    ls1_.p2.SetCoordinatesToPoint(_ls1.p2.getX(), _ls1.p2.getY());
    ls2_.p1.SetCoordinatesToPoint(_ls2.p1.getX(), _ls2.p1.getY());
    ls2_.p2.SetCoordinatesToPoint(_ls2.p2.getX(), _ls2.p2.getY());
}

TwoLineSegments::TwoLineSegments(const TwoLineSegments& z) {
    ls1_.p1.SetCoordinatesToPoint(z.ls1_.p1.getX(), z.ls1_.p1.getY());
    ls1_.p2.SetCoordinatesToPoint(z.ls1_.p2.getX(), z.ls1_.p2.getY());
    ls2_.p1.SetCoordinatesToPoint(z.ls2_.p1.getX(), z.ls2_.p1.getY());
    ls2_.p2.SetCoordinatesToPoint(z.ls2_.p2.getX(), z.ls2_.p2.getY());
}

void TwoLineSegments::setCoordinatesToFirstLine(const Point _p1,
                                                const Point _p2) {
    ls1_.p1.SetCoordinatesToPoint(_p1.getX(), _p1.getY());
    ls1_.p2.SetCoordinatesToPoint(_p2.getX(), _p2.getY());
}

void TwoLineSegments::setCoordinatesToSecondLine(const Point _p1,
                                                const Point _p2) {
    ls2_.p1.SetCoordinatesToPoint(_p1.getX(), _p1.getY());
    ls2_.p2.SetCoordinatesToPoint(_p2.getX(), _p2.getY());
}

LineSegment TwoLineSegments::getLineSegment1() const {
    return ls1_;
}

LineSegment TwoLineSegments::getLineSegment2() const {
    return ls2_;
}

int TwoLineSegments::signOfSquare(Point p1, Point p2, Point p3) const {
    int tmp = (p1.getX() - p3.getX())*(p2.getY() - p3.getY()) +
              (p2.getX() - p3.getX())*(p3.getY() - p1.getY());
    if (tmp > 0)
        return 1;
    if (tmp < 0)
        return -1;
    return 0;
}

bool TwoLineSegments::isMax(int a, int b, int c, int d) const {
    return std::max(a, b) >= std::min(c, d) &&
           std::max(c, d) >= std::min(a, b);
}

bool TwoLineSegments::areIntersect() const {
    int s11 = signOfSquare(ls1_.p1, ls1_.p2, ls2_.p1);
    int s12 = signOfSquare(ls1_.p1, ls1_.p2, ls2_.p2);
    int s21 = signOfSquare(ls2_.p1, ls2_.p2, ls1_.p1);
    int s22 = signOfSquare(ls2_.p1, ls2_.p2, ls1_.p2);

    if (s11 == 0 && s12 == 0 && s21 == 0 && s22 == 0)
        return isMax(ls1_.p1.getX(), ls1_.p2.getX(),
                     ls2_.p1.getX(), ls2_.p2.getX()) &&
               isMax(ls1_.p1.getY(), ls1_.p2.getY(),
                     ls2_.p1.getY(), ls2_.p2.getY());

    return (s11*s12 <= 0) && (s21*s22 <= 0);
}
