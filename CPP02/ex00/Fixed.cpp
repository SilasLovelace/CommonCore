#include "Fixed.hpp"

Fixed::Fixed(){
    this->fixed_point = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed &src){
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

Fixed::~Fixed(){
    std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const{
    std::cout << "getRawBits member function called\n";
    return this->fixed_point;
}

void Fixed::setRawBits(int const raw){
    std::cout << "setRawBits member function called\n";
    this->fixed_point = raw;
}