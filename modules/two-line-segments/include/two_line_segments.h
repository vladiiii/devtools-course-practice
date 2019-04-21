// CopyRight 2019 Iamshchikov Ivan

#ifndef MODULES_TWO_LINE_SEGMENTS_INCLUDE_TWO_LINE_SEGMENTS_H_
#define MODULES_TWO_LINE_SEGMENTS_INCLUDE_TWO_LINE_SEGMENTS_H_

struct Point {
    int x;
    int y;

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    void SetCoordinatesToPoint(int _x, int _y) {
        x = _x;
        y = _y;
    }
};

struct LineSegment {
    Point p1;
    Point p2;
};

class TwoLineSegments {
 public:
    TwoLineSegments();
    TwoLineSegments(const LineSegment _ls1,
                    const LineSegment _ls2);
    TwoLineSegments(const TwoLineSegments& z);

    void setCoordinatesToFirstLine(const Point _p1, const Point _p2);
    void setCoordinatesToSecondLine(const Point _p1, const Point _p2);

    LineSegment getLineSegment1() const;
    LineSegment getLineSegment2() const;

    bool areIntersect() const;

 private:
    int signOfSquare(Point p1, Point p2, Point p3) const;
    bool isMax(int a, int b, int c, int d) const;
    LineSegment ls1_;
    LineSegment ls2_;
};


#endif  // MODULES_TWO_LINE_SEGMENTS_INCLUDE_TWO_LINE_SEGMENTS_H_
