/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:47:22 by sopperma          #+#    #+#             */
/*   Updated: 2025/01/13 15:50:53 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type){
    this->type = type;
}

Weapon::~Weapon(){
    std::cout << this->type << " destroyed\n";
}

const std::string &Weapon::getType() const{
    return this->type;
}

void Weapon::setType(std::string type){
    this->type = type;
}