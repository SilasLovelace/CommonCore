/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:59:45 by sopperma          #+#    #+#             */
/*   Updated: 2025/03/25 11:17:43 by sopperma         ###   ########.fr       */
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
    std::cout << "Bacon." << "\n";
}
void Harl::info(void){
    std::cout << "Why no bacon?" << "\n";
}
void Harl::warning(void){
    std::cout << "Gimme bacon or else!" << "\n";
}
void Harl::error(void){
    std::cout << "Segfault<no bacon>!" << "\n";
}

void Harl::complain(std::string level)
{
    void (Harl::*messages[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i = 0;
    while (level != levels[i] && i < 4) i++;
    switch (i) {
        case 4:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
        default:
            (this->*messages[i])();
    }
    return;
}

