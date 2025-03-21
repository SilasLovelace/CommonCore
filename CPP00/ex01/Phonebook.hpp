/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:02:24 by sopperma          #+#    #+#             */
/*   Updated: 2025/03/21 15:00:05 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <sstream>
#include "Contact.hpp"

#define caseNumber 0
#define caseFirstName 1
#define caseLastName 2
#define caseNickname 3
#define caseSecret 4
#define caseError 5
#define caseIndex 6
#define caseRange 7
#define caseNaN 8
#define caseTooLong 9
#define caseInvalidCharacters 10

#define prompt_Number "Enter the number: "
#define prompt_FirstName "Enter the first name: "
#define prompt_LastName "Enter the last name: "
#define prompt_Nickname "Enter the nickname: "
#define prompt_Secret "Enter the darkest secret: "
#define prompt_Notempty "Input cannot be empty!\n"
#define prompt_Index "Enter the index: "
#define prompt_Range_Error "Index out of Range!\n"
#define prompt_NaN "Input must consist only of numbers\n"
#define prompt_Too_Long "Max length of Input 50 Characters\n"
#define prompt_Invalid_Characters "Invalid Characters! Can only contain printable characters! -> ASCII\n"

class PhoneBook {
private:
    Contact contacts[8];
    int index = 0;
    int size = 0;
    bool isValidInt(std::string);
    bool isValidString(std::string);
    
public:
    PhoneBook();
    ~PhoneBook();
    std::string trim(const std::string&);
    std::string getprompt (int);
    std::string prompt (int);
    std::string printColumn (std::string, bool);
    std::string printInfo (Contact);  
    void addContact(void);
    void search();
};

#endif