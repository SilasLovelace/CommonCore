#include "Fixed.hpp"
#include <limits>

Fixed::Fixed(){
    this->_fixed_point = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value){
    if (value < -8388608 || value > 8388607){
        throw std::invalid_argument("Int-Value out of range -8388608 and 8388607!\n");
    }
    this->_fixed_point = (1 << _bits) * value;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const float value){
    if (value < -8388608 || value > 8388607){
        throw std::invalid_argument("Float-Value out of range -8388608 and 8388607!\n");
    }
    int temp= roundf(value * (1 <<_bits));  
    this->_fixed_point = temp;
    std::cout << "Default constructor called" << std::endl;
}

float Fixed::toFloat(void) const{
    return static_cast<float>(this->_fixed_point) / (1 <<_bits);
}

int Fixed::toInt(void) const{
    return this->_fixed_point >> _bits;
}

Fixed::Fixed(const Fixed &src){
    this->_fixed_point = src._fixed_point;
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed& Fixed::operator=(const Fixed& rhs){
    std::cout << "Copy assignment operator called" << std::endl;
     if (this != &rhs){
    _fixed_point = rhs.getRawBits();
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& rhs){
    os << rhs.toFloat();
    return os;
}

Fixed::~Fixed(){
    std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const{
    std::cout << "getRawBits member function called\n";
    return this->_fixed_point;
}

void Fixed::setRawBits(int const raw){
    std::cout << "setRawBits member function called\n";
    this->_fixed_point = raw;
}
