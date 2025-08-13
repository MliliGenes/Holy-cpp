#include "Fixed.hpp"

Fixed::Fixed( void ) : fixedPoint(0) {

    std::cout << "Default constructor called" << std::endl;

}

Fixed::Fixed( const Fixed& other ) {

    std::cout << "Copy constructor called" << std::endl;
    fixedPoint = other.getRawBits();

}

Fixed& Fixed::operator=( const Fixed& other ) {

    std::cout << "Copy assignment operator called" << std::endl;

    if ( this  == &other )
        return *this;

    fixedPoint = other.getRawBits();

    return *this;

}

Fixed::~Fixed( void ) {

    std::cout << "Destructor called" << std::endl;

}


void Fixed::setRawBits( const int raw ) {

    std::cout << "meoooooow" << std::endl;
    fixedPoint = raw;

}


int Fixed::getRawBits( void ) const {

    std::cout << "getRawBits member function called" << std::endl;
    return fixedPoint;

}

Fixed::Fixed( const int rawInt ) {

    fixedPoint = rauInt << fractionalBits;

}

int Fixed::toInt( void ) const {

    return fixedPoint >> fractionalBits;

}

Fixed::Fixed( const float rawFloat ) {

    fixedPoint = roundf( rawFloat * ( 1 << fractionalBits ) );

}

float Fixed::toFloat( void ) const {

    return fixedPoint / ( 1 << fractionalBits );

}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat(); // insert the float version into the stream
    return os; // allow chaining: cout << a << b;
}

