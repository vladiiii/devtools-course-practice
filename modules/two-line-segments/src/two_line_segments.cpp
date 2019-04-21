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
    ls1_.p1.SetCoordinatesToPoint(_ls1.p1.x, _ls1.p1.y);
    ls1_.p2.SetCoordinatesToPoint(_ls1.p2.x, _ls1.p2.y);
    ls2_.p1.SetCoordinatesToPoint(_ls2.p1.x, _ls2.p1.y);
    ls2_.p2.SetCoordinatesToPoint(_ls2.p2.x, _ls2.p2.y);
}

TwoLineSegments::TwoLineSegments(const TwoLineSegments& z) {
    ls1_.p1.SetCoordinatesToPoint(z.ls1_.p1.x, z.ls1_.p1.y);
    ls1_.p2.SetCoordinatesToPoint(z.ls1_.p2.x, z.ls1_.p2.y);
    ls2_.p1.SetCoordinatesToPoint(z.ls2_.p1.x, z.ls2_.p1.y);
    ls2_.p2.SetCoordinatesToPoint(z.ls2_.p2.x, z.ls2_.p2.y);
}

void TwoLineSegments::setCoordinatesToFirstLine(const Point _p1,
                                                const Point _p2) {
    ls1_.p1.SetCoordinatesToPoint(_p1.x, _p1.y);
    ls1_.p2.SetCoordinatesToPoint(_p2.x, _p2.y);
}

void TwoLineSegments::setCoordinatesToSecondLine(const Point _p1,
                                                const Point _p2) {
    ls2_.p1.SetCoordinatesToPoint(_p1.x, _p1.y);
    ls2_.p2.SetCoordinatesToPoint(_p2.x, _p2.y);
}

LineSegment TwoLineSegments::getLineSegment1() const {
    return ls1_;
}

LineSegment TwoLineSegments::getLineSegment2() const {
    return ls2_;
}

int TwoLineSegments::signOfSquare(Point p1, Point p2, Point p3) const {
    int tmp = (p1.x - p3.x)*(p2.y - p3.y) + (p2.x - p3.x)*(p3.y - p1.y);
    if(tmp > 0)
        return 1;
    if(tmp < 0)
        return -1;
    return 0;
}

bool TwoLineSegments::isMax(int a, int b, int c, int d) const {
    return std::max(a, b) >= std::min(c, d) && std::max(c, d) >= std::min(a, b);
}

bool TwoLineSegments::areIntersect() const {
    int s11 = signOfSquare(ls1_.p1, ls1_.p2, ls2_.p1);
    int s12 = signOfSquare(ls1_.p1, ls1_.p2, ls2_.p2);
    int s21 = signOfSquare(ls2_.p1, ls2_.p2, ls1_.p1);
    int s22 = signOfSquare(ls2_.p1, ls2_.p2, ls1_.p2);

    if(s11 == 0 && s12 == 0 && s21 == 0 && s22 == 0)
        return isMax(ls1_.p1.x, ls1_.p2.x, ls2_.p1.x, ls2_.p2.x) && isMax(ls1_.p1.y, ls1_.p2.y, ls2_.p1.y, ls2_.p2.y);

    return (s11*s12 <= 0) && (s21*s22 <= 0);
}