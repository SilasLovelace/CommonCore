/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:29:50 by sopperma          #+#    #+#             */
/*   Updated: 2024/06/20 15:56:54 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_valid_char(char c)
{
	if (c == COLL || c == PLAYER || c == WALL || c == EMPTY || c == EXIT)
		return (1);
	return (0);
}

static void	count(t_counters *counter, char c)
{
	if (c == COLL)
		counter->c++;
	if (c == PLAYER)
		counter->p++;
	if (c == EXIT)
		counter->e++;
}

int	parse_map(t_mlx_data *data)
{
	int			x;
	int			y;
	t_counters	counters;

	ft_bzero(&counters, sizeof(t_counters));
	x = 0;
	y = 0;
	while (data->map[y])
	{
		while (data->map[y][x])
		{
			if (!is_valid_char(data->map[y][x]))
				return (0);
			count(&counters, data->map[y][x]);
			x++;
		}
		y++;
		x = 0;
	}
	if (counters.c < 1 || counters.p != 1 || counters.e != 1)
		return (0);
	data->diamonds = counters.c;
	return (1);
}
