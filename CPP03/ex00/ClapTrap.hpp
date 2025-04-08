#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap{
    private:
        std::string name;
        unsigned int hitpoints = 10;
        unsigned int energy_points = 10;
        unsigned int attack_damage = 0;
        unsigned int max_hitpoints = 10;
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap &operator=(ClapTrap &rhs);
        ClapTrap(ClapTrap &src);
        ~ClapTrap();

        void attack(std::string const & target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        unsigned int getHitpoints() const;
};

#endif