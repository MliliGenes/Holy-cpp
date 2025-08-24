#pragma once

#include "Fixed.hpp"

class Point {

    private :

        Fixed x,y;


    public :

        Point( void ) : x(0), y(0) {}
        Point( const float _x, const float _y ) : x(_x), y(_y) {}
        ~Point( void );
        Point( const Point& other );
        Point& operator=( const Point& other );

        Fixed getX() const ;
        Fixed getY() const ;

};

bool bsp( Point const a, Point const b, Point const c, Point const point);
