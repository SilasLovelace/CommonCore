/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:05:41 by sopperma          #+#    #+#             */
/*   Updated: 2024/07/05 10:19:59 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h> 
# include <signal.h>
# include <stdio.h>

typedef struct s_bits
{
	int	current;
	int	*bit;
	int	size;
	int	encoded_bits;
}	t_bits;

typedef struct s_bits_recieved
{
	int	current;
	int	*bit;
	int	size;
}	t_bits_recieved;

void	send_signal(int pid, int signum, t_bits *g_bits);
#endif