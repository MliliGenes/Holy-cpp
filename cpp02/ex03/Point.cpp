#include "Point.hpp"

Fixed Point::getx( void ) const {

    return x;

}

Fixed Point::gety( void ) const {

    return y;

}

Point::~Point( void ) {

    // meow

}

Point::Point( const Point& other) {

    x = other.x;
    y = other.y;

}

Point& Point::operator=( const Point& other ) {

    if (&other == this)
        return *this;

    x = other.getx();
    y = other.gety();

    return *this;
}

Fixed orient(Point const &P, Point const &A, Point const &B) {

    return ((P.getx() - B.getx()) * (A.gety() - B.gety()))
            - ((A.getx() - B.getx()) * (P.gety() - B.gety()));

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
