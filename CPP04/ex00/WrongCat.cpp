#include "WrongCat.hpp"

WrongCat::WrongCat() {
    this->type = "WrongCat";
    std::cout << "WrongCat default constructor called" << std::endl;
}
WrongCat::WrongCat(std::string type) {
    this->type = type;
    std::cout << "WrongCat constructor called" << std::endl;
}
WrongCat::WrongCat(WrongCat &src) {
    this->type = src.type;
    std::cout << "WrongCat copy constructor called" << std::endl;
}
WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
}
WrongCat &WrongCat::operator=(WrongCat &rhs) {
    if (this != &rhs) {
        this->type = rhs.type;
    }
    return *this;
}
void WrongCat::makeSound() const {
    std::cout << "Meowing" << std::endl;
}