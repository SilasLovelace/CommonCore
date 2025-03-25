/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:47:28 by sopperma          #+#    #+#             */
/*   Updated: 2025/03/25 10:42:03 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void HumanB::attack(){
    std::cout << this->name << " attacks with his " << (this->weapon ? this->weapon->getType() : "huge dong") << "\n";
}

HumanB::HumanB(std::string name, Weapon &weapon){
    this->name = name;
    this->weapon = &weapon;
}
HumanB::HumanB(std::string name){
    this->name = name;
    this->weapon = NULL;
}
HumanB::~HumanB(){
    std::cout << this->name << " destroyed\n";
}

void HumanB::setWeapon(Weapon &weapon){
    this->weapon = &weapon;
}

