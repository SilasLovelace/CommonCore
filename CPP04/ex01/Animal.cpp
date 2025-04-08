#include "Animal.hpp"

Animal::Animal() {
    this->type = "Animal";
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(Animal &src) {
    this->type = src.type;
    std::cout << "Animal copy constructor called" << std::endl;
}
Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}
Animal &Animal::operator=(Animal &rhs) {
    if (this != &rhs) {
        this->type = rhs.type;
    }
    return *this;
}
void Animal::makeSound() const {
    std::cout << "Generic animal sound" << std::endl;
}
std::string Animal::getType() const {
    return this->type;
}