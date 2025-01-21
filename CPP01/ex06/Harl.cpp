/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:59:45 by sopperma          #+#    #+#             */
/*   Updated: 2025/01/21 14:46:29 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
    std::cout << "Harl orders a Burger." << "\n";
}
Harl::~Harl()
{
    std::cout << "Harl gets shot." << "\n";
}
void Harl::debug(void){
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "Bacon." << "\n";
}
void Harl::info(void){
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "Why no bacon?" << "\n";
}
void Harl::warning(void){
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "Gimme bacon or else!" << "\n";
}
void Harl::error(void){
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "Segfault<no bacon>!" << "\n";
}

void Harl::complain(std::string level)
{
    int levelIndex = -1;
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++) {
        if (level == levels[i]) {
            levelIndex = i;
            break;
        }
    }

    switch (levelIndex) {
        case 0:
            this->debug();
        case 1:
            this->info();
        case 2:
            this->warning();
        case 3:
            this->error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}