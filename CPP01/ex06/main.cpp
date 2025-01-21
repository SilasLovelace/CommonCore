/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:01:45 by sopperma          #+#    #+#             */
/*   Updated: 2025/01/21 14:47:46 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char const *argv[]) {
    Harl harl;

if (argc != 2) {   
    std::cout << "Wrong amount of Arguments!" << std::endl;
    return 1;
}
    harl.complain(argv[1]);
    return 0;
}
