#include "Fixed.hpp"

Fixed::Fixed(){
    this->_fixed_point = 0;
}

Fixed::Fixed(const int value){
    if (value < -8388608 || value > 8388607){
        throw std::invalid_argument("Int-Value out of range -8388608 and 8388607!\n");
    }
    this->_fixed_point = (1 << _bits) * value;
}

Fixed::Fixed(const float value){
    if (value < -8388608 || value > 8388607){
        throw std::invalid_argument("Float-Value out of range -8388608 and 8388607!\n");
    }
    int temp= roundf(value * (1 <<_bits));  
    this->_fixed_point = temp;
}

float Fixed::toFloat(void) const{
    return static_cast<float>(this->_fixed_point) / (1 <<_bits);
}

int Fixed::toInt(void) const{
    return this->_fixed_point >> _bits;
}

Fixed::Fixed(const Fixed &src){
    this->_fixed_point = src._fixed_point;
    *this = src;
}


std::ostream& operator<<(std::ostream& os, const Fixed& rhs){
    os << rhs.toFloat();
    return os;
}

Fixed::~Fixed(){
}

int Fixed::getRawBits(void) const{
    return this->_fixed_point;
}

void Fixed::setRawBits(int const raw){
    this->_fixed_point = raw;
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
    // return Fixed((float)((long)this->getRawBits() * (long)rhs.getRawBits()) / (1 << 16));
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
