/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:01:45 by sopperma          #+#    #+#             */
/*   Updated: 2025/01/13 12:52:38 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(){
    int i = 5;
    int j = 0;
    Zombie* horde = zombieHorde(i, "Baba");
    while (j < i){
        horde[j].announce();
        j++;
    }
    delete [] horde;
    return 0;
}