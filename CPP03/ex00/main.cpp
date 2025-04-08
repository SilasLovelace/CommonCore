#include "ClapTrap.hpp"

unsigned int ClapTrap::getHitpoints() const{
    return this->hitpoints;
}

int main(){
    ClapTrap bub("Bub");
    bub.attack("The Financial system");
    bub.takeDamage(5);
    std::cout << "Bub's hitpoints: " << bub.getHitpoints() << std::endl;
    bub.beRepaired(3);
    std::cout << "Bub's hitpoints: " << bub.getHitpoints() << std::endl;
    bub.beRepaired((unsigned int)4294967295);
    std::cout << "Bub's hitpoints: " << bub.getHitpoints() << std::endl;
    bub.beRepaired(3);
    bub.beRepaired(3);
    bub.attack("My Neighbor's Lawn Gnome");
    bub.attack("The DMV Waiting Line");
    bub.attack("My Cat's Indifference");
    bub.attack("Monday Mornings");
    bub.attack("IKEA Assembly Instructions");
    bub.attack("Automated Phone Support");
    bub.attack("My Printer");
    bub.attack("Existential Dread");
    bub.attack("Quantum Physics");
    bub.beRepaired(5);
    bub.takeDamage(5);
    bub.takeDamage(5);
    bub.beRepaired(5);
    return 0;
}