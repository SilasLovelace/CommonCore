#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(){
    ScavTrap bub("Bub");
    bub.attack("The Financial system");
    bub.takeDamage(5);
    bub.beRepaired(5);
    bub.attack("My Neighbor's Lawn Gnome");
    bub.guardGate();

    FragTrap bub2("Bub2");
    bub2.attack("The Financial system");
    bub2.highFivesGuys();
    bub2.takeDamage(100);
    bub2.beRepaired(100);
    bub2.attack("My Neighbor's Lawn Gnome");
    bub2.highFivesGuys();

    return 0;
}