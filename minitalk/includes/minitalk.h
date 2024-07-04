/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:51:38 by sopperma          #+#    #+#             */
/*   Updated: 2024/07/04 16:18:00 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
// #define _POSIX_C_SOURCE 200809L

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h> 
#include <signal.h>
#include <stdio.h>

typedef struct s_bits
{
    int current;
    int *bit;
    int size;
    int encoded_bits;
}   t_bits;

typedef struct s_bits_recieved
{
    int current;
    int *bit;
    int size;
}   t_bits_recieved;
#endif