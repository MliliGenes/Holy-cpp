#include "Point.hpp"

Fixed Point::getX( void ) const {

    return x;

}

Fixed Point::getY( void ) const {

    return y;

}

Point::~Point( void ) {

    // meow

}

Point::Point( const Point& other) {

    x = other.getX();
    y = other.getY();

}

Point& Point::operator=( const Point& other ) {

    if (&other == this)
        return *this;

    x = other.getX();
    y = other.getY();

    return *this;
}

Fixed orient(Point const &a, Point const &b, Point const &c) {
    std::cout << a.getX() << std::endl;
    std::cout << a.getY() << std::endl;
    std::cout << b.getX() << std::endl;
    std::cout << b.getY() << std::endl;
    std::cout << c.getX() << std::endl;
    std::cout << c.getY() << std::endl;
    return (a.getX() - c.getX()) * (b.getY() - c.getY())
         - (b.getX() - c.getX()) * (a.getY() - c.getY());
}

bool bsp( Point const a, Point const b, Point const c, Point const p) {

    Fixed d1 = orient(p, a, b);
    Fixed d2 = orient(p, b, c);
    Fixed d3 = orient(p, c, a);

    std::cout << d1 << d2 << d3 << std::endl;
    bool hasNeg = (d1 < Fixed(0)) || (d2 < Fixed(0)) || (d3 < Fixed(0));
    bool hasPos = (d1 > Fixed(0)) || (d2 > Fixed(0)) || (d3 > Fixed(0));

    return !(hasNeg && hasPos) && d1 != 0 && d2 != 0 && d3 != 0;

}
