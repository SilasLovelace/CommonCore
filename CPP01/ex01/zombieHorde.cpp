/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:23:18 by sopperma          #+#    #+#             */
/*   Updated: 2025/01/13 12:48:26 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name){
    if (N <= 0) {
        std::cerr << "N must be greater than 0\n";
        return NULL;
    }
    Zombie *horde = new Zombie[N];
    int i = 0;
    while(i < N){
        std::cout << "Zombie " << i << " created\n";
        horde[i].setName(name);
        i++;
    }
    return horde;
}
