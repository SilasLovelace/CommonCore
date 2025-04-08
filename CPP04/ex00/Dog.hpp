
#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal{
    public:
        Dog();
        Dog &operator=(Dog &rhs);
        Dog(Dog &src);
        ~Dog();

        void makeSound() const;
};

#endif