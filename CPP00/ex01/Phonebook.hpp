/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:02:24 by sopperma          #+#    #+#             */
/*   Updated: 2025/03/25 10:18:58 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <sstream>
#include "Contact.hpp"

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