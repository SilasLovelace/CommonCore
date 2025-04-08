#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
    this->name = "Orphan";
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name){
    std::cout << "ClapTrap parameter constructor called" << std::endl;
    name.empty() ? this->name = "Orphan" : this->name = name;
}

ClapTrap::ClapTrap(ClapTrap &src){
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = src;
}

ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap &rhs){
    this->name = rhs.name;
    this->hitpoints = rhs.hitpoints;
    this->energy_points = rhs.energy_points;
    this->attack_damage = rhs.attack_damage;
    return *this;
}

void ClapTrap::attack(std::string const & target){
    if (this->energy_points > 0 && this->hitpoints > 0){
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
        this->energy_points -= 1;
        
    }
    else{
        std::cout << "ClapTrap " << this->name << " is out of energy points or dead and can't attack!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount){
    if (this->hitpoints > amount)
    {
        std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
        this->hitpoints -= amount;
    }
    else
    {
        std::cout << "ClapTrap " << this->name << " takes " << this->hitpoints << " points of damage and is dead!" << std::endl;
        this->hitpoints = 0;
    }
}

void ClapTrap::beRepaired(unsigned int amount){
    if (this->hitpoints > 0)
    {
        if (this->energy_points > 0){
            if (this->hitpoints + amount < amount){
                std::cout << "Overflow points!" << std::endl;
            }
            else if (this->hitpoints + amount > this->max_hitpoints && this->hitpoints != this->max_hitpoints){
                amount = this->max_hitpoints - this->hitpoints;
                this->hitpoints += amount;
                std::cout << "ClapTrap " << this->name << " is being repaired for " << amount << " points!" << std::endl;
            }
            else if (this->hitpoints == this->max_hitpoints){
                std::cout << "ClapTrap " << this->name << " is already at max hitpoints!" << std::endl;
                return;
            }
            else{
                this->hitpoints += amount;
                std::cout << "ClapTrap " << this->name << " is being repaired for " << amount << " points!" << std::endl;
            }
            this->energy_points -= 1;
        }
        else{
            std::cout << "ClapTrap " << this->name << " is out of energy points and can't repair!" << std::endl;
        }
    }
    else{
        std::cout << "ClapTrap " << this->name << " is dead and can't be repaired!" << std::endl;
    }
}
