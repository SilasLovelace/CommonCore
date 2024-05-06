/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                        :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:38:24 by sopperma          #+#    #+#             */
/*   Updated: 2024/04/25 13:38:25 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int	ft_printf(const char *s, ...);
int	handle_i_d(int i);
int	handle_u(unsigned int u);
int	handle_x(unsigned int i, char *base, int adress);
int	handle_x_upper(unsigned int i, char *base, int adress);
int	handle_p(void *i, char *base, int adress);

#endif
