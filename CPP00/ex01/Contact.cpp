/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:02:24 by sopperma          #+#    #+#             */
/*   Updated: 2025/03/21 15:02:45 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::getPhoneNumber() {return phoneNumber;}
std::string Contact::getFirstName() {return firstName;}
std::string Contact::getLastName() {return lastName;}
std::string Contact::getNickname() {return nickname;}
std::string Contact::getDarkestSecret() {return darkestSecret;}
Contact::Contact(std::string phoneNumber, std::string firstName, std::string lastName, std::string nickname, std::string secret) {
    this->phoneNumber = phoneNumber;
    this->firstName = firstName;
    this->lastName = lastName;
    this->nickname = nickname;
    this->darkestSecret = secret;
}
Contact::Contact(){};
