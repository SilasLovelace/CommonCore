#include "Dog.hpp"

Dog::Dog() {
    this->type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
}
Dog::Dog(std::string type) {
    this->type = type;
    std::cout << "Dog constructor called" << std::endl;
}
Dog::Dog(Dog &src) {
    this->type = src.type;
    std::cout << "Dog copy constructor called" << std::endl;
}
Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}
Dog &Dog::operator=(Dog &rhs) {
    if (this != &rhs) {
        this->type = rhs.type;
    }
    return *this;
}
void Dog::makeSound() const {
    std::cout << "Barking" << std::endl;
}