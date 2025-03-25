/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:59:45 by sopperma          #+#    #+#             */
/*   Updated: 2025/03/25 11:38:18 by sopperma         ###   ########.fr       */
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
    int i = 0;
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    while (level != levels[i] && i < 4) i++;

    switch (i) {
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