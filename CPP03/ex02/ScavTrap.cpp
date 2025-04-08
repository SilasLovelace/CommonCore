#include "ScavTrap.hpp"

void ScavTrap::attack(std::string const & target){
    if (this->energy_points > 0 && this->hitpoints > 0){
        std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
        this->energy_points -= 1;
    }
    else
        std::cout << "ScavTrap " << this->name << " is out of energy points or dead and can't attack!" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount){
    if (this->hitpoints > amount)
    {
        std::cout << "ScavTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
        this->hitpoints -= amount;
    }
    else
    {
        std::cout << "ScavTrap " << this->name << " takes " << this->hitpoints << " points of damage and is dead!" << std::endl;
        this->hitpoints = 0;
    }
}

void ScavTrap::beRepaired(unsigned int amount){
    if (this->hitpoints > 0)
    {
        if (this->energy_points > 0){
            if (this->hitpoints + amount < amount){
                std::cout << "Overflow points!" << std::endl;
            }
            else if (this->hitpoints + amount > this->max_hitpoints && this->hitpoints != this->max_hitpoints){
                amount = this->max_hitpoints - this->hitpoints;
                this->hitpoints += amount;
                std::cout << "ScavTrap " << this->name << " is being repaired for " << amount << " points!" << std::endl;
            }
            else if (this->hitpoints == this->max_hitpoints){
                std::cout << "ScavTrap " << this->name << " is already at max hitpoints!" << std::endl;
                return;
            }
            else{
                this->hitpoints += amount;
                std::cout << "ScavTrap " << this->name << " is being repaired for " << amount << " points!" << std::endl;
            }
            this->energy_points -= 1;
        }
        else{
            std::cout << "ScavTrap " << this->name << " is out of energy points and can't repair!" << std::endl;
        }
    }
    else{
        std::cout << "ScavTrap " << this->name << " is dead and can't be repaired!" << std::endl;
    }
}

ScavTrap::ScavTrap(): ClapTrap(){
    std::cout << "ScavTrap default constructor called" << std::endl;
    hitpoints = 100;
    max_hitpoints = 100;
    energy_points = 50;
    attack_damage = 20;
}


ScavTrap::ScavTrap(std::string name): ClapTrap(){
    std::cout << "ScavTrap parameter constructor called" << std::endl;
    this->name = name;
    hitpoints = 100;
    max_hitpoints = 100;
    energy_points = 50;
    attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &tmp){
    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = tmp;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &tmp){
    std::cout << "ScavTrap assignation operator called" << std::endl;
    name = tmp.name;
    hitpoints = tmp.hitpoints;
    max_hitpoints = tmp.max_hitpoints;
    energy_points = tmp.energy_points;
    attack_damage = tmp.attack_damage;
    return *this;
}

void ScavTrap::guardGate(){
    if (!this->is_guarding){
        if (hitpoints > 0 && energy_points > 0)
        {
            std::cout << "ScavTrap " << name << " has entered in Gate keeper mode" << std::endl;
            energy_points -= 1;
            is_guarding = true;
        }
        else
        std::cout << "ScavTrap " << name << " is out of energy or dead, either way no guard duty!" << std::endl;
    }
    else
        std::cout << "ScavTrap " << name << " is already guarding the gate!" << std::endl;
}

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap destructor called" << std::endl;
}