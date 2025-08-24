#include "Fixed.hpp"

Fixed::Fixed( void ) : fixedPoint(0) {

    // std::cout << "Default constructor called" << std::endl;

}

Fixed::Fixed( const Fixed& other ) {

    // std::cout << "Copy constructor called" << std::endl;
    fixedPoint = other.getRawBits();

}

Fixed& Fixed::operator=( const Fixed& other ) {

    // std::cout << "Copy assignment operator called" << std::endl;

    if ( this  == &other )
        return *this;

    fixedPoint = other.getRawBits();

    return *this;

}

Fixed::~Fixed( void ) {

    // std::cout << "Destructor called" << std::endl;

}


void Fixed::setRawBits( const int raw ) {

    // std::cout << "meoooooow" << std::endl;
    fixedPoint = raw;

}


int Fixed::getRawBits( void ) const {

    // std::cout << "getRawBits member function called" << std::endl;
    return fixedPoint;

}

Fixed::Fixed( const int rawInt ) {

    // std::cout << "Int constructor called" << std::endl;
    fixedPoint = rawInt << fractionalBits;

}

int Fixed::toInt( void ) const {

    return fixedPoint >> fractionalBits;

}

Fixed::Fixed( const float rawFloat ) {

    // std::cout << "Float constructor called" << std::endl;
    fixedPoint = roundf( rawFloat * ( 1 << fractionalBits ) );

}

float Fixed::toFloat( void ) const {

    return (float)fixedPoint / ( 1 << fractionalBits );

}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat(); // insert the float version into the stream
    return os; // allow chaining: cout << a << b;
}


bool Fixed::operator<( const Fixed& right ) const {

    return fixedPoint < right.fixedPoint;

}


bool Fixed::operator<=( const Fixed& right ) const {

    return fixedPoint <= right.fixedPoint;

}

bool Fixed::operator>( const Fixed& right ) const {

    return fixedPoint > right.fixedPoint;

}

bool Fixed::operator>=( const Fixed& right ) const {

    return fixedPoint >= right.fixedPoint;

}

bool Fixed::operator==( const Fixed& right ) const {

    return fixedPoint == right.fixedPoint;

}

bool Fixed::operator!=( const Fixed& right ) const {

    return fixedPoint != right.fixedPoint;

}

Fixed Fixed::operator+( const Fixed& other ) const {

    return Fixed( fixedPoint + other.fixedPoint );

}

Fixed Fixed::operator-( const Fixed& other ) const {

    return Fixed( fixedPoint - other.fixedPoint );

}

Fixed Fixed::operator*( const Fixed& other ) const {

    return Fixed( this->toFloat() * other.toFloat() );

}

Fixed Fixed::operator/( const Fixed& other ) const {

    return Fixed( this->toFloat() / other.toFloat() );

}

Fixed& Fixed::operator++( void ) {

    fixedPoint++;
    return *this;

}

Fixed  Fixed::operator++( int ) {

    Fixed old;
    old.setRawBits( fixedPoint );
    fixedPoint++;
    return old;

}

Fixed& Fixed::operator--() {
    fixedPoint--;   // -ε
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed old(*this); // store old state
    fixedPoint--;     // -ε
    return old;       // return old value
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}
