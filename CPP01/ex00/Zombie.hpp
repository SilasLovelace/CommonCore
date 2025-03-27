/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:49:15 by sopperma          #+#    #+#             */
/*   Updated: 2025/03/25 14:16:16 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie{
    private:
        std::string name;
    public:
        Zombie();
        Zombie(std::string name);
        ~Zombie();
        void announce();
};

void randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif