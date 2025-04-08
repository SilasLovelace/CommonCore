
#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal{
    private:
        Brain *brain;
    public:
        Dog();
        Dog &operator=(Dog &rhs);
        Dog(Dog &src);
        ~Dog();

        void makeSound() const;
        Brain *getBrain() const;
};

#endif