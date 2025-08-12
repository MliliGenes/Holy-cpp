#pragma once

#include <iostream>
// #include ""
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

        int getRawBits( void ) const;
        void setRawBits( const int raw );


};
