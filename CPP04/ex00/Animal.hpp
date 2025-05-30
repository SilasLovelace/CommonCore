#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal{
    protected:
        std::string type;
    public:
        Animal();
        Animal &operator=(Animal &rhs);
        Animal(Animal &src);
        virtual ~Animal();

        virtual void makeSound() const;
        std::string getType() const;
};

#endif