#include "Cat.hpp"

Cat::Cat() {
    this->type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
}
Cat::Cat(std::string type) {
    this->type = type;
    std::cout << "Cat constructor called" << std::endl;
}
Cat::Cat(Cat &src) {
    this->type = src.type;
    std::cout << "Cat copy constructor called" << std::endl;
}
Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}
Cat &Cat::operator=(Cat &rhs) {
    if (this != &rhs) {
        this->type = rhs.type;
    }
    return *this;
}
void Cat::makeSound() const {
    std::cout << "Meowing" << std::endl;
}