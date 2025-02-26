#include "Fixed.hpp"

Fixed::Fixed(){
    this->fixed_point = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value){
    if (value < (-8388608) || value > 8388607){
        std::cout << "Int-Value out of range -8388608 -> 8388607!\n";
        return;
    }
    this->fixed_point = (int)value << bits;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const float value){
    if (value < (-8388608) || value > 8388607 + (1 - 255/256)){
        std::cout << "Float-Value out of range -8388608 -> 8388607.99609375!\n";
        return;
    }
    this->fixed_point = (int)value * (1<<bits);
    std::cout << "Default constructor called" << std::endl;
}

float Fixed::toFloat(void) const{
    return (float)this->fixed_point / (2^bits);
}

int Fixed::toInt(void) const{
    return this->fixed_point >> bits;
}

Fixed::Fixed(const Fixed &src){
    this->fixed_point = src.fixed_point;
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed& Fixed::operator=(const Fixed& rhs){
    std::cout << "Copy assignment operator called" << std::endl;
     if (this != &rhs){
    fixed_point = rhs.getRawBits();
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& rhs){
    // Extract integer part
    int integerPart = rhs.fixed_point >> Fixed::bits;
    // Extract fractional part
    int fractionalPart = (rhs.fixed_point & ((1 << Fixed::bits) - 1)); // Mask to get fractional bits
    // Convert to float representation
    float floatValue = integerPart + (fractionalPart / (float)(1 << Fixed::bits));
    
    // Output to the stream
    os << floatValue;
    return os;
}

Fixed::~Fixed(){
    std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const{
    std::cout << "getRawBits member function called\n";
    return this->fixed_point;
}
