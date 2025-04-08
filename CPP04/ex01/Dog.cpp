#include "Dog.hpp"

Dog::Dog() {
    this->type = "Dog";
    this->brain = new Brain();
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(Dog &src) {
    this->type = src.type;
    this->brain = src.brain;
    std::cout << "Dog copy constructor called" << std::endl;
}
Dog::~Dog() {
    delete this->brain;
    std::cout << "Dog destructor called" << std::endl;
}
Dog &Dog::operator=(Dog &rhs) {
    if (this != &rhs) {
        this->type = rhs.type;
        *this->brain = *rhs.brain;
    }
    return *this;
}
void Dog::makeSound() const {
    std::cout << "Barking" << std::endl;
}
Brain *Dog::getBrain() const {
    return this->brain;
}