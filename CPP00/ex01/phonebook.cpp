/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:28:56 by sopperma          #+#    #+#             */
/*   Updated: 2025/03/21 11:39:19 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main () {
    PhoneBook phonebook;
    while (1) {
        std::string input;
        std::cout << "Enter ADD or SEARCH or EXIT: ";
        if (!std::getline(std::cin, input))
            exit(0);
        if (input == "ADD")
            phonebook.addContact();
        else if (input == "SEARCH")
            phonebook.search();
        else if (input == "EXIT")
            break;
    }
    return (0);
}