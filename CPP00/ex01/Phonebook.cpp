/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:02:24 by sopperma          #+#    #+#             */
/*   Updated: 2025/03/21 15:12:10 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
PhoneBook::PhoneBook() {}
PhoneBook::~PhoneBook() {}

bool PhoneBook::isValidInt(std::string input) {
    for (int i = 0; i < input.length(); i++) {
        if (!std::isdigit(input.at(i)))
            return false;
    }
    return true;
}

bool PhoneBook::isValidString(std::string input) {
    int count = 0;
    for (int i = 0; i < input.length(); i++) {
        if (!(input.at(i) >= 32 && input.at(i) <= 122))
            return false;
        else
            input.at(i) == 32 ? count : count++;
    }
    if (count == 0)
        return false;
    return true;
}

std::string PhoneBook::trim(const std::string& str) {
size_t first = str.find_first_not_of(" \t\n\r");
if (first == std::string::npos) return "";
size_t last = str.find_last_not_of(" \t\n\r");
return str.substr(first, last - first + 1);
}

std::string PhoneBook::getprompt (int prompt)
{
    switch (prompt) {
        case caseNumber:
            return prompt_Number;
        case caseFirstName:
            return prompt_FirstName;
        case caseLastName:
            return prompt_LastName;
        case caseNickname:
            return prompt_Nickname;
        case caseSecret:
            return prompt_Secret;
        case caseIndex:
            return prompt_Index;
        case caseRange:
            return prompt_Range_Error;
        case caseNaN:
            return prompt_NaN;
        case caseTooLong:
            return prompt_Too_Long;
        case caseInvalidCharacters:
            return prompt_Invalid_Characters;
        default:
            return prompt_Notempty;
    }
}

std::string PhoneBook::prompt (int prompt){
    while (1) {
        std::string input;
        std::cout << getprompt(prompt);
        std::getline(std::cin, input);
        if (std::cin.eof())
        {
        std::cerr << "\nError Input!!" << std::endl;
        exit (1) ;
        }
        if (input.length() > 50) {
            std::cout << getprompt(caseTooLong);
            continue;
        }
        if (input.empty()) {
            std::cout << getprompt(caseError);
            continue;
        }
        if (prompt == caseIndex) {
            if (!isValidInt(input)) {
                std::cout << getprompt(caseNaN);
                continue;
            }
            int trimmed_num = std::stoi(trim(input));
            if (trimmed_num < 0 || trimmed_num >= this->size || trimmed_num >= 8) {
                std::cout << getprompt(caseRange);
                continue;
            }
        }
        if (prompt == caseNumber && !isValidInt(input)) {
            std::cout << getprompt(caseNaN);
            continue;
        }
        if (prompt == caseFirstName || prompt == caseLastName || prompt == caseNickname) {
            if (!isValidString(input)) {
                std::cout << getprompt(caseInvalidCharacters);
                continue;
            }
            input = trim(input);
        }
        return input;
    }
}

std::string PhoneBook::printColumn (std::string info, bool last) {
    if (info.length() > 10)
        return info.substr(0, 9) + "." + (last ? "\n" : "|");
    if (info.length() < 10)
        return std::string(10 - info.length(), ' ') + info + (last ? "\n" : "|");
    return info;
}

std::string PhoneBook::printInfo (Contact contact) {
    std::string info = "";
    info +="FIRST NAME : " + contact.getFirstName() + "\n";
    info +="LAST NAME  : " + contact.getLastName() + "\n";
    info +="NICKNAME   : " + contact.getNickname() + "\n";
    info +="NUMBA      : " + contact.getPhoneNumber() + "\n";
    info +="BORING INFO: " + contact.getDarkestSecret() + "\n";
    return info;
}


void PhoneBook::addContact() {
    std::string phonenumber = prompt(caseNumber);
    std::string firstName = prompt(caseFirstName);
    std::string lastName = prompt(caseLastName);
    std::string nickname = prompt(caseNickname);
    std::string secret = prompt(caseSecret);
    contacts[index] = Contact(phonenumber, firstName, lastName, nickname, secret);
    index = (index + 1) % 8;
    size = (size < 8) ? size + 1 : 8;
}

void PhoneBook::search() {
    if (size == 0) {
        std::cout << "No contacts\n";
        return;
    }
    for (int i = 0; i < size; i++) {
        if (contacts[i].getDarkestSecret().empty())
            break;
        std::cout << printColumn(std::to_string(i), false);
        std::cout << printColumn(contacts[i].getFirstName(), false);
        std::cout << printColumn(contacts[i].getLastName(), false);
        std::cout << printColumn(contacts[i].getNickname(), true);
    }
    int i = std::stoi(prompt(caseIndex));
    std::cout << printInfo(contacts[i]);
}
