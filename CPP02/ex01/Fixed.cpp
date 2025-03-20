#include "Fixed.hpp"

Fixed::Fixed(){
    this->_fixed_point = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value){
    if (value < (-8388608) || value > 8388607){
        std::cout << "Int-Value out of range -8388608 -> 8388607!\n";
        return;
    }
    this->_fixed_point = (int)(value << _bits);
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const float value){
    if (value < (-8388608) || value > 8388607 + (1 - 255/256)){
        std::cout << "Float-Value out of range -8388608 -> 8388607.99609375!\n";
        return;
    }
    double temp= static_cast<double>(value * (1 <<_bits));
    printf("temp: %f\n", temp);

    this->_fixed_point = roundf(temp); 
    printf("this->_fixed_point: %d\n", this->_fixed_point);

    std::cout << "Default constructor called" << std::endl;
}

float Fixed::toFloat(void) const{
    return static_cast<float>((this->_fixed_point / (1 <<_bits)));
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
