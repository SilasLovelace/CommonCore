#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void fill_brian(Brain *brain, std::string type)
{
    for (int i = 0; i < 100; i++)
        brain->setIdea(type + " Idea " + std::to_string(i));
}

int main(){
    // Animal Animal = new Animal();
    Cat *cat = new Cat();
    cat->makeSound();

    delete cat;
    return 0;
}