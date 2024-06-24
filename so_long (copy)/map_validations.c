/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:17:30 by sopperma          #+#    #+#             */
/*   Updated: 2024/06/20 15:54:42 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectanglar(t_mlx_data *data)
{
	int		y;
	int	len;

	y = 0;
	len = ft_strlen_gnl(data->map[y]);
	while (data->map[y])
	{
		if (ft_strlen_gnl(data->map[y]) != len)
			return (0);
		y++;
	}
	return (1);
}

static void	set_numbers(int *x, int *y, int a, int b)
{
	*x = a;
	*y = b;
}

int	check_walls(t_mlx_data *data)
{
	int			x;
	int			y;
	t_wallsize	walls;

	set_numbers(&x, &y, 0, 0);
	while (data->map[0][x] && data->map[0][x] == WALL)
		x++;
	walls.top = x;
	set_numbers(&x, &y, 0, data->map_h - 1);
	while (data->map[y][x] && data->map[y][x] == WALL)
		x++;
	walls.bottom = x;
	set_numbers(&x, &y, 0, 0);
	while (data->map[y] && data->map[y][0] == WALL)
		y++;
	walls.left = y;
	set_numbers(&x, &y, data->map_w - 1, 0);
	while (data->map[y] && data->map[y][x] == WALL)
		y++;
	walls.right = y;
	if (walls.top != data->map_w || walls.bottom != data->map_w \
		|| walls.left != data->map_h || walls.right != data->map_h)
		return (0);
	return (1);
}
