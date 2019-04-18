#include <cmath>

#include "..\include\triangles.h"

Triangle::Triangle() : a(-3.0, 0.0), b(3.0, 0.0), c(0.0, 3.0) {}

Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3)
                   : a(x1, y1), b(x2, y2), c(x3, y3) {
    if (!IsTriangleExist(a, b, c)) {
        throw std::string("Such a triangle does not exist.");
    }
}

Triangle::Triangle(Point _a, Point _b, Point _c) : a(_a), b(_b), c(_c) {
    if (!IsTriangleExist(a, b, c)) {
        throw std::string("Such a triangle does not exist.");
    }
}

Triangle::Triangle(std::vector<double> array) {
    if (array.size() != 6) {
        throw std::string("Size can't be lower or higher than 6");
    } else {
        a.x = array[0];
        a.y = array[1];
        b.x = array[2];
        b.y = array[3];
        c.x = array[4];
        c.y = array[5];

        if (!IsTriangleExist(a, b, c)) {
            throw std::string("Such a triangle does not exist.");
        }
    }
}

Point Triangle::get_point_a() const {
    return a;
}

Point Triangle::get_point_b() const {
    return b;
}

Point Triangle::get_point_c() const {
    return c;
}

void Triangle::set_point_a(const Point _a) {
    a = _a;
    if (!IsTriangleExist(a, b, c)) {
        throw std::string("Such a triangle does not exist.");
    }
}//TODO: test at throw

void Triangle::set_point_b(const Point _b) {
    b = _b;
    if (!IsTriangleExist(a, b, c)) {
        throw std::string("Such a triangle does not exist.");
    }
} //TODO: test at throw

void Triangle::set_point_c(const Point _c) {
    c = _c;
    if (!IsTriangleExist(a, b, c)) {
        throw std::string("Such a triangle does not exist.");
    }
}//TODO: test at throw

double Triangle::SideLength(Point _a, Point _b) {
    return sqrt(pow((_b.x - _a.x), 2) + pow((_b.y - _a.y), 2));
}

double Triangle::Perimeter() {
    double ab = SideLength(a, b);
    double bc = SideLength(b, c);
    double ac = SideLength(a, c);

    return ab + bc + ac;
}

double Triangle::Square() {
    double ab = SideLength(a, b);
    double bc = SideLength(b, c);
    double ac = SideLength(a, c);
    double h_p = (ab + bc + ac) / 2; //half of perimeter

    return sqrt(h_p * (h_p - ab) * (h_p - ac) * (h_p - bc));
}

double Triangle::get_angle_a() 
{
    double ab = SideLength(a, b);
    double bc = SideLength(b, c);
    double ac = SideLength(a, c);
    
    double radian = acos((pow(ab, 2) + pow(ac, 2) - pow(bc, 2)) / (2 * ab * ac));
    return 57.2958 * radian;
}

double Triangle::get_angle_b() 
{
    double ab = SideLength(a, b);
    double bc = SideLength(b, c);
    double ac = SideLength(a, c);

    double radian = acos((pow(ab, 2) + pow(bc, 2) - pow(ac, 2)) / (2 * ab * bc));
    return 57.2958 * radian;
}

double Triangle::get_angle_c() 
{
    double ab = SideLength(a, b);
    double bc = SideLength(b, c);
    double ac = SideLength(a, c);

    double radian = acos((pow(bc, 2) + pow(ac, 2) - pow(ab, 2)) / (2 * ac * bc));

    return 57.2958 * radian;
}

//Check whether the basic triangle inequality holds.
bool Triangle::IsTriangleExist() {
    double ab = SideLength(a, b);
    double bc = SideLength(b, c);
    double ac = SideLength(a, c);

    return (ab + bc > ac) && (ab + ac > bc) && (bc + ac > ab) ? true : false;
}

//The private method is needed for use inside other methods.
bool Triangle::IsTriangleExist(Point _a, Point _b, Point _c) {
    double ab = SideLength(a, b);
    double bc = SideLength(b, c);
    double ac = SideLength(a, c);

    return (ab + bc > ac) && (ab + ac > bc) && (bc + ac > ab) ? true : false;
}
