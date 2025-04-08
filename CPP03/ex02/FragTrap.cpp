#include "FragTrap.hpp"

void FragTrap::attack(std::string const & target){
    if (this->energy_points > 0 && this->hitpoints > 0){
        std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
        this->energy_points -= 1;
    }
    else
        std::cout << "FragTrap " << this->name << " is out of energy points or dead and can't attack!" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount){
    if (this->hitpoints > amount)
    {
        std::cout << "FragTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
        this->hitpoints -= amount;
    }
    else
    {
        std::cout << "FragTrap " << this->name << " takes " << this->hitpoints << " points of damage and is dead!" << std::endl;
        this->hitpoints = 0;
    }
}

void FragTrap::beRepaired(unsigned int amount){
    if (this->hitpoints > 0)
    {
        if (this->energy_points > 0){
            if (this->hitpoints + amount < amount){
                std::cout << "Overflow points!" << std::endl;
            }
            else if (this->hitpoints + amount > this->max_hitpoints && this->hitpoints != this->max_hitpoints){
                amount = this->max_hitpoints - this->hitpoints;
                this->hitpoints += amount;
                std::cout << "FragTrap " << this->name << " is being repaired for " << amount << " points!" << std::endl;
            }
            else if (this->hitpoints == this->max_hitpoints){
                std::cout << "FragTrap " << this->name << " is already at max hitpoints!" << std::endl;
                return;
            }
            else{
                this->hitpoints += amount;
                std::cout << "FragTrap " << this->name << " is being repaired for " << amount << " points!" << std::endl;
            }
            this->energy_points -= 1;
        }
        else{
            std::cout << "FragTrap " << this->name << " is out of energy points and can't repair!" << std::endl;
        }
    }
    else{
        std::cout << "FragTrap " << this->name << " is dead and can't be repaired!" << std::endl;
    }
}

FragTrap::FragTrap(): ClapTrap(){
    std::cout << "FragTrap default constructor called" << std::endl;
    hitpoints = 100;
    max_hitpoints = 100;
    energy_points = 100;
    attack_damage = 30;
}

FragTrap::FragTrap(std::string name): ClapTrap(){
    std::cout << "FragTrap parameter constructor called" << std::endl;
    this->name = name;
    hitpoints = 100;
    max_hitpoints = 100;
    energy_points = 100;
    attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &tmp){
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = tmp;
}

FragTrap &FragTrap::operator=(const FragTrap &tmp){
    std::cout << "FragTrap assignation operator called" << std::endl;
    name = tmp.name;
    hitpoints = tmp.hitpoints;
    max_hitpoints = tmp.max_hitpoints;
    energy_points = tmp.energy_points;
    attack_damage = tmp.attack_damage;
    return *this;
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys(){
    if (hitpoints > 0 && energy_points > 0)
    {
        std::cout << "FragTrap " << name << " requests a super-duper high five!" << std::endl;
        energy_points -= 1;
    }
    else
        std::cout << "FragTrap " << name << " is dead or out of energy and therefore does not request a high five!" << std::endl;
}