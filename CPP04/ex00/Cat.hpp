#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"
class Cat : public Animal{
    public:
        Cat();
        Cat &operator=(Cat &rhs);
        Cat(Cat &src);
        ~Cat();

        void makeSound() const;
};
#endif