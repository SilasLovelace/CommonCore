/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:47:28 by sopperma          #+#    #+#             */
/*   Updated: 2025/01/13 16:00:09 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void HumanB::attack(){
    std::cout << this->name << " attacks with his " << this->weapon.getType() << "\n";
}

HumanB::HumanB(std::string name, Weapon &weapon){
    this->name = name;
    this->weapon = weapon;
}
HumanB::HumanB(std::string name){
    this->name = name;
}
HumanB::~HumanB(){
    std::cout << this->name << " destroyed\n";
}

void HumanB::setWeapon(Weapon &weapon){
    this->weapon = weapon;
}

