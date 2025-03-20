/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:09:29 by sopperma          #+#    #+#             */
/*   Updated: 2025/03/20 15:57:31 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main (int argc, char **argv) {
    if (argc > 1)
    {
        int i = 1;
        while (i < argc) {  
            int j = 0;
            while (argv[i][j]) {std::cout << (char)toupper(argv[i][j]);j++;}
            i++;
            std::cout << " ";
        }
        std::cout << "\n";
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n" ;
    return (0);
}