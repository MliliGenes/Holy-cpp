#pragma once

#include <iostream>
#include <cmath>


class Fixed {

    private :

        int fixedPoint;
        const static int fractionalBits = 8;

    public :

        Fixed( void );
        Fixed( const Fixed& other );
        Fixed& operator=( const Fixed& other);
        ~Fixed( void );

        bool operator<( const Fixed& right ) const;
        bool operator<=( const Fixed& right ) const;
        bool operator>( const Fixed& right ) const;
        bool operator>=( const Fixed& right ) const;

        bool operator==( const Fixed& right ) const;
        bool operator!=( const Fixed& right ) const;

        Fixed operator+(const Fixed& other ) const;
        Fixed operator-(const Fixed& other ) const;
        Fixed operator*(const Fixed& other ) const;
        Fixed operator/(const Fixed& other ) const;

        Fixed& operator++( void );
        Fixed operator++( int );
        Fixed& operator--( void );
        Fixed operator--( int );

        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);

        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);

        int getRawBits( void ) const;
        void setRawBits( const int raw );

        Fixed( const int rawInt );
        Fixed( const float rawFloat );

        float toFloat( void ) const;
        int toInt( void ) const;

};

std::ostream& operator<<( std::ostream&, const Fixed& );

