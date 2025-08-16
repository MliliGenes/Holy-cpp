#pragma once

#include <iostream>
#include <cmath>
// #include ""


class Fixed {

    private :

        int fixedPoint;
        const static int fractionalBits = 8;

    public :

        Fixed( void );
        Fixed( const Fixed& other );
        Fixed& operator=( const Fixed& other);
        ~Fixed( void );

        bool operator<( const Fixed& right );
        bool operator<=( const Fixed& right );
        bool operator>( const Fixed& right );
        bool operator>=( const Fixed& right );

        bool operator==( const Fixed& right );
        bool operator!=( const Fixed& right );

        Fixed operator+( const Fixed& other ) const;
        FIxed operator-( const Fixed& other ) const;
        FIxed operator*( const Fixed& other ) const;
        FIxed operator/( const Fixed& other ) const;

        Fixed& operator++( void );
        Fixed operator++( int );

        Fixed& operator++( void );
        Fixed operator++( int );

        int getRawBits( void ) const;
        void setRawBits( const int raw );

        Fixed( const int rawInt );
        Fixed( const float rawFloat );

        float toFloat( void ) const;
        int toInt( void ) const;

};

std::ostream& operator<<( std::ostream&, const Fixed& );
