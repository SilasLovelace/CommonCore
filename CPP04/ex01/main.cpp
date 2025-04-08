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
    Animal *meta[4];
    int i = 0;
    while (i < 4)
    {
        if (i % 2 == 0)
            meta[i] = new Dog();
        else
            meta[i] = new Cat();
        i++;
    }
    for (int j = 0; j < 4; j++)
    {
        delete meta[j];
    }
    std::cout << "------------------------" << std::endl;
    Animal *cat = new Cat();
    std::cout << cat->getType() << std::endl;
    cat->makeSound();
    std::cout << ((Cat *)cat)->getBrain()->getIdea(0) << std::endl;
    fill_brian(((Cat *)cat)->getBrain(), "Cat");
    std::cout << ((Cat *)cat)->getBrain()->getIdea(0) << std::endl;
    ((Cat *)cat)->getBrain()->setIdea("new thought!");
    std::cout << ((Cat *)cat)->getBrain()->getIdea(0) << std::endl;
    std::cout << ((Cat *)cat)->getBrain()->getIdea(1) << std::endl;

    Animal *dog = new Dog();
    std::cout << dog->getType() << std::endl;
    dog->makeSound();
    fill_brian(((Dog *)dog)->getBrain(), "Dog");
    std::cout << ((Dog *)dog)->getBrain()->getIdea(0) << std::endl;
    *cat = *dog;
    std::cout << cat->getType() << std::endl;
    cat->makeSound();
    std::cout << ((Dog *)dog)->getBrain()->getIdea(0) << std::endl;
    std::cout << ((Cat *)cat)->getBrain()->getIdea(0) << std::endl;
    std::cout << "------------------------" << std::endl;
    Animal *newCat = new Cat();
    *(Cat *)newCat = *(Cat *)cat;
    std::cout << ((Cat *)newCat)->getBrain()->getIdea(0) << std::endl;
    std::cout << ((Cat *)newCat)->getBrain()->getIdea(1) << std::endl;
    ((Cat *)cat)->getBrain()->setIdea("new crazy thought!");
    std::cout << ((Cat *)cat)->getBrain()->getIdea(0) << std::endl;
    std::cout << ((Cat *)cat)->getBrain()->getIdea(1) << std::endl;
    std::cout << ((Cat *)newCat)->getBrain()->getIdea(0) << std::endl;
    std::cout << ((Cat *)newCat)->getBrain()->getIdea(1) << std::endl;
    delete newCat;
    delete cat;
    delete dog;
    return 0;
}