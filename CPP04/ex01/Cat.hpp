#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"
class Cat : public Animal{
    private:
        Brain *brain;
    public:
        Cat();
        Cat &operator=(Cat &rhs);
        Cat(Cat &src);
        ~Cat();

        void makeSound() const;
        Brain *getBrain() const;
};
#endif