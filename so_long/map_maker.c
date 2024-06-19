/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_maker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:04:29 by sopperma          #+#    #+#             */
/*   Updated: 2024/06/19 20:05:15 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int choose_asset(t_mlx_data *data, char *path, int x, int y)
{
	int h = ASSET_H;
	data->img.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, path, &h, &h);
	if (data->img.img_ptr)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr, x, y);
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
		return (1);
	}
	return (0);
}

static int set_asset(t_mlx_data *data, int x, int y, char p)
{
	if((p == '1' && choose_asset(data, "assets/wall.xpm", x, y)) \
		|| (p == '0' && choose_asset(data, "assets/empty.xpm", x, y)) \
		|| (p == 'P' && choose_asset(data, "assets/me.xpm", x, y)) \
		|| (p == 'E' && choose_asset(data, "assets/exit.xpm", x, y)) \
		|| (p == 'X' && choose_asset(data, "assets/diamond.xpm", x, y)))
		return (1);
	return (0);
}

int paint_map(t_mlx_data *data)
{
	int i;
	int	j;
	int x;
	int y;
	
	x = 0;
	y = 0;
	i = 0;
	j = 0;
	while(data->map[i])
	{
		while(data->map[i][j])
		{
			set_asset(data, x, y, data->map[i][j]);
			x += 20;
			j++;
		}
		j = 0;
		x = 0;
		y += 20;
		i++;
	}
	return (0);
}