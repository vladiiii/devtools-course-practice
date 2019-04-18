// Copyright 2019 Shkerin Igor

#ifndef MODULES_TRIANGLES_INCLUDE_TRIANGLES_H_
#define MODULES_TRIANGLES_INCLUDE_TRIANGLES_H_

#include <iostream>
#include <vector>

struct Point {
    double x, y;

    Point(double _x = 0, double _y = 0) : x(_x), y(_y) {};

    Point& operator=(const Point& point) {
        x = point.x;
        y = point.y;
        return *this;
    }

    bool operator==(const Point& point) const {
        if ((this->x == point.x) &&
            (this->y == point.y)) {
            return true;
        } else {
            return false;
        } 
    }
};

class Triangle {
public:
    Triangle();
    Triangle(double x1, double y1, double x2, double y2, double x3, double y3);
    Triangle(Point _a, Point _b, Point _c);
    Triangle(std::vector<double> array);

    bool IsTriangleExist();

    Point get_point_a() const;
    Point get_point_b() const;
    Point get_point_c() const;

    void set_point_a(Point _a);
    void set_point_b(Point _b);
    void set_point_c(Point _c);

    double SideLength(Point _a, Point _b);

    double Perimeter();
    double Square();

    double get_angle_a(); 
    double get_angle_b();
    double get_angle_c();
private:
    bool IsTriangleExist(Point _a, Point _b, Point _c);
private:
    Point a, b, c;
    //double ab = 0, bc = 0, ac = 0;
};

#endif  // MODULES_TRIANGLES_INCLUDE_TRIANGLES_H_
