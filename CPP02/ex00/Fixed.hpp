#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <sstream>

class Fixed{
    private:
        int fixed_point;
        static const int bits = 8;
    public:
        Fixed();
        Fixed(Fixed &src);
        Fixed& operator=(const Fixed& rhs);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits( int const raw );
};

#endif