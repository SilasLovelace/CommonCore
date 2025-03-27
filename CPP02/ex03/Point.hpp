#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
    Fixed const x;
    Fixed const y;
public:
    Point();
    Point(float const x, float const y);
    Point(const Point &src);
    ~Point();
    Fixed const getX() const;
    Fixed const getY() const;
    void setX(float const x);
    void setY(float const y);
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif