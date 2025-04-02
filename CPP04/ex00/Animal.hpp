#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal{
    protected:
        std::string type;
    public:
        Animal();
        Animal(std::string type);
        Animal &operator=(Animal &rhs);
        Animal(Animal &src);
        ~Animal();

        void makeSound() const;
        std::string getType() const;
};

#endif