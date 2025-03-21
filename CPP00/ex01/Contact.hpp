/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:02:24 by sopperma          #+#    #+#             */
/*   Updated: 2025/03/21 11:50:10 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <string>

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

#endif