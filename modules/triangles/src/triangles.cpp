#include "..\include\triangles.h"

Triangle::Triangle() : a(-3.0, 0.0), b(3.0, 0.0), c(0.0, 3.0)
{
}

Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3) :a(x1, y1), b(x2, y2), c(x3, y3)
{
}

Triangle::Triangle(std::pair<double, double> _a, std::pair<double, double> _b, std::pair<double, double> _c) : a(_a.first, _a.second), b(_b.first, _b.second), c(_c.first, _c.second)
{
}

Triangle::Triangle(Point _a, Point _b, Point _c) : a(_a), b(_b), c(_c)
{
}

Triangle::Triangle(double* array)
{
    if (sizeof(array) / sizeof(*array) != 6) {
        throw std::string("Size can't be lower or higher than 6");
    } else {
        array[0] = a.x;
        array[1] = a.y;
        array[2] = b.x;
        array[3] = b.y;
        array[4] = c.x;
        array[5] = c.y;
    }
}

Triangle::Triangle(std::vector<double> array)
{
    if (array.size() != 6) {
        throw std::string("Size can't be lower or higher than 6");
    }
    else {
        array[0] = a.x;
        array[1] = a.y;
        array[2] = b.x;
        array[3] = b.y;
        array[4] = c.x;
        array[5] = c.y;
    }
}

bool Triangle::IsTriangleExist(std::vector<double> array)
{
    return true;
}
