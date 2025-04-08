#include "ScavTrap.hpp"


int main(){
    ScavTrap bub("Bub");
    bub.attack("The Financial system");
    bub.takeDamage(5);
    bub.beRepaired(10);
    bub.beRepaired(5);
    bub.beRepaired(5);
    bub.attack("My Neighbor's Lawn Gnome");
    bub.guardGate();
    bub.guardGate();
    return 0;
}