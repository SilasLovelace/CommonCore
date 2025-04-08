#include "Cat.hpp"

Cat::Cat() {
    this->type = "Cat";
    this->brain = new Brain();
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(Cat &src) {
    this->type = src.type;
    this->brain = src.brain;
    std::cout << "Cat copy constructor called" << std::endl;
}
Cat::~Cat() {
    delete this->brain;
    std::cout << "Cat destructor called" << std::endl;
}
Cat &Cat::operator=(Cat &rhs) {
    if (this != &rhs) {
        this->type = rhs.type;
        *this->brain = *rhs.brain;
    }
    return *this;
}
void Cat::makeSound() const {
    std::cout << "Meowing" << std::endl;
}
Brain *Cat::getBrain() const {
    return this->brain;
}