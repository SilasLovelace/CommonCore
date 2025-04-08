#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"
class WrongCat : public WrongAnimal{
    public:
        WrongCat();
        WrongCat &operator=(WrongCat &rhs);
        WrongCat(WrongCat &src);
        ~WrongCat();

        void makeSound() const;
};

#endif