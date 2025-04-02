#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"
class WrongCat : WrongAnimal{
    public:
        WrongCat();
        WrongCat(std::string type);
        WrongCat &operator=(WrongCat &rhs);
        WrongCat(WrongCat &src);
        ~WrongCat();

        void makeSound() const;
};

#endif