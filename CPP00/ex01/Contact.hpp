/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:02:24 by sopperma          #+#    #+#             */
/*   Updated: 2025/03/21 14:56:01 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact {
private:
    std::string phoneNumber;
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string darkestSecret;
public:
    Contact ();
    Contact(std::string, std::string, std::string, std::string, std::string);
    std::string getPhoneNumber(void);
    std::string getFirstName(void);
    std::string getLastName(void);
    std::string getNickname(void);
    std::string getDarkestSecret(void);

};

#endif