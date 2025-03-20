#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

class Fixed{
    private:
        int _fixed_point;
        static const int _bits = 8;
    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed &src);
        Fixed& operator=(const Fixed& rhs);
        friend std::ostream& operator<<(std::ostream& os, const Fixed& rhs);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
};

#endif