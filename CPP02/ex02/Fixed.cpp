#include "Fixed.hpp"

Fixed::Fixed(){
    this->_fixed_point = 0;
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value){
    if (value < (-8388608) || value > 8388607){
        std::cout << "Int-Value out of range -8388608 -> 8388607!\n";
        return;
    }
    this->_fixed_point = (1 << _bits) * value;
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const float value){
    if (value < (-8388608) || value > 8388607 + (1 - 255/256)){
        std::cout << "Float-Value out of range -8388608 -> 8388607.99609375!\n";
        return;
    }
    int temp= roundf(value * (1 <<_bits));  
    this->_fixed_point = temp;
    // std::cout << "Default constructor called" << std::endl;
}

float Fixed::toFloat(void) const{
    return static_cast<float>(this->_fixed_point) / (1 <<_bits);
}

int Fixed::toInt(void) const{
    return this->_fixed_point >> _bits;
}

Fixed::Fixed(const Fixed &src){
    this->_fixed_point = src._fixed_point;
    // std::cout << "Copy constructor called" << std::endl;
    *this = src;
}


std::ostream& operator<<(std::ostream& os, const Fixed& rhs){
    os << rhs.toFloat();
    return os;
}

Fixed::~Fixed(){
    // std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const{
    // std::cout << "getRawBits member function called\n";
    return this->_fixed_point;
}

bool Fixed::operator>(const Fixed& rhs) const {
    return this->_fixed_point > rhs.getRawBits();
}

bool Fixed::operator<(const Fixed& rhs) const {
    return this->_fixed_point < rhs.getRawBits();
}

bool Fixed::operator>=(const Fixed& rhs) const {
    return this->_fixed_point >= rhs.getRawBits();
}

bool Fixed::operator<=(const Fixed& rhs) const {
    return this->_fixed_point <= rhs.getRawBits();
}

bool Fixed::operator==(const Fixed& rhs) const {
    return this->_fixed_point == rhs.getRawBits();
}

bool Fixed::operator!=(const Fixed& rhs) const {
    return this->_fixed_point != rhs.getRawBits();
}

Fixed Fixed::operator+(const Fixed& rhs) const{
    return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed& rhs) const{
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed& rhs) const{
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed& rhs) const{
    return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed& Fixed::operator++(){
    this->_fixed_point++;
    return *this;
}

Fixed Fixed::operator++(int){
    Fixed temp(*this);
    this->_fixed_point++;
    return temp;
}

Fixed& Fixed::operator--(){
    this->_fixed_point--;
    return *this;
}

Fixed Fixed::operator--(int){
    Fixed temp(*this);
    this->_fixed_point--;
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b){
    return a < b ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b){
    return a < b ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b){
    return a > b ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b){
    return a > b ? a : b;
}

Fixed& Fixed::operator=(const Fixed& rhs){
    std::cout << "Copy assignment operator called" << std::endl;
     if (this != &rhs){
    _fixed_point = rhs.getRawBits();
    }
    return *this;
}
