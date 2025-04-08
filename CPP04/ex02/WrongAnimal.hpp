#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal{
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal &operator=(WrongAnimal &rhs);
        WrongAnimal(WrongAnimal &src);
        ~WrongAnimal();

        void makeSound() const;
};

#endif