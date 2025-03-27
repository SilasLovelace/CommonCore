#include    "Point.hpp"

Point::Point() {
    this->x = Fixed(0);
    this->y = Fixed(0);
}

Point::Point(float const x, float const y) : x(x), y(y) {}