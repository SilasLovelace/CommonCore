#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal{
    protected:
        std::string type;
        Animal();
        Animal &operator=(Animal &rhs);
        Animal(Animal &src);
        virtual ~Animal() = 0;
        virtual void makeSound() const = 0;
        std::string getType() const;
};

#endif