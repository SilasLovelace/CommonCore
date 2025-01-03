/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:02:24 by sopperma          #+#    #+#             */
/*   Updated: 2025/01/02 17:19:27 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <sstream>

#define caseNumber 0
#define caseFirstName 1
#define caseLastName 2
#define caseNickname 3
#define caseSecret 4
#define caseError 5
#define caseIndex 6
#define caseRange 7
#define caseNaN 8

#define prompt_Number "Enter the number: "
#define prompt_FirstName "Enter the first name: "
#define prompt_LastName "Enter the last name: "
#define prompt_Nickname "Enter the nickname: "
#define prompt_Secret "Enter the darkest: "
#define prompt_Notempty "Input cannot be empty!\n"
#define prompt_Index "Enter the index: "
#define prompt_Range_Error "Index out of Range!\n"
#define prompt_NaN "Input must consist only of numbers\n"


class Contact {
private:
    std::string phoneNumber;
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string darkestSecret;
public:
    Contact () {}

    Contact(std::string phoneNumber, std::string firstName, std::string lastName, std::string nickname, std::string secret) {
        this->phoneNumber = phoneNumber;
        this->firstName = firstName;
        this->lastName = lastName;
        this->nickname = nickname;
        this->darkestSecret = secret;
    }
    std::string getPhoneNumber() {
        return phoneNumber;
    }
    std::string getFirstName() {
        return firstName;
    }
    std::string getLastName() {
        return lastName;
    }
    std::string getNickname() {
        return nickname;
    }
    std::string getDarkestSecret() {
        return darkestSecret;
    }
};

class PhoneBook {
private:
    Contact contacts[8];
    int index{0};
    int size{0};

    bool isValidInt(std::string input) {
        for (char c : input) {
            if (!std::isdigit(c))
                return false;
        }
        return true;
    }

    std::string getprompt (int prompt)
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
            default:
                return prompt_Notempty;
        }
    }

    std::string prompt (int prompt){
        while (1) {
            std::string input;
            std::cout << getprompt(prompt);
            std::getline(std::cin, input);
            if (input.empty()) {
                std::cout << getprompt(caseError);
                continue;
            }
            if (prompt == caseIndex) {
                if (!isValidInt(input)) {
                    std::cout << getprompt(caseNaN);
                    continue;
                }
                if (std::stoi(input) < 0 || std::stoi(input) >= size){
                    std::cout << getprompt(caseRange);
                    continue;
                }
            }
            if (prompt == caseNumber && !isValidInt(input)) {
                std::cout << getprompt(caseNaN);
                continue;
            }
            return input;
        }
    }

    std::string printColumn (std::string info, bool last) {
        if (info.length() > 10)
            return info.substr(0, 9) + "." + (last ? "\n" : "|");
        if (info.length() < 10)
            return std::string(10 - info.length(), ' ') + info + (last ? "\n" : "|");
        return info;
    }
    
    std::string printInfo (Contact contact) {
        std::string info = "";
        info += contact.getFirstName() + "\n";
        info += contact.getLastName() + "\n";
        info += contact.getNickname() + "\n";
        info += contact.getPhoneNumber() + "\n";
        info += contact.getDarkestSecret() + "\n";
        return info;
    }
    
public:
    PhoneBook(){}
    
    void addContact() {
        std::string phonenumber = prompt(caseNumber);
        std::string firstName = prompt(caseFirstName);
        std::string lastName = prompt(caseLastName);
        std::string nickname = prompt(caseNickname);
        std::string secret = prompt(caseSecret);
        contacts[index] = Contact(phonenumber, firstName, lastName, nickname, secret);
        index = (index + 1) % 8;
        size = (size < 8) ? size + 1 : 8;
    }

    void search() {
        if (size == 0) {
            std::cout << "No contacts\n";
            return;
        }
        int i = 0;
        for (Contact contact : contacts) {
            if (contact.getDarkestSecret().empty())
                break;
            std::cout << printColumn(std::to_string(i), false);
            std::cout << printColumn(contact.getFirstName(), false);
            std::cout << printColumn(contact.getLastName(), false);
            std::cout << printColumn(contact.getNickname(), true);
            i++;
        }
        i = std::stoi(prompt(caseIndex));
        std::cout << printInfo(contacts[i]);
    }
};

#endif