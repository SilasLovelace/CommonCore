#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    this->type = "WrongAnimal";
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal &src) {
    this->type = src.type;
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}
WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
}
WrongAnimal &WrongAnimal::operator=(WrongAnimal &rhs) {
    if (this != &rhs) {
        this->type = rhs.type;
    }
    return *this;
}
void WrongAnimal::makeSound() const {
    std::cout << "Generic wrong-animal sound" << std::endl;
}