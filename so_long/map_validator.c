/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:58:59 by sopperma          #+#    #+#             */
/*   Updated: 2024/06/24 15:05:33 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_obj_pos(char **map, int *y, int *x, char obj)
{
	int	i;

	i = 0;
	while (map[i] && !ft_strchr(map[i], obj))
		i++;
	*y = i;
	*x = ft_strchr(map[i], obj) - map[i];
	return (1);
}

static int	flood_fill(t_mlx_data *data, int y, int x, char c)
{
	int	i;

	i = 0;
	if (x < 0 || x > data->map_w - 1 || y < 0 || !data->map[y])
		return (i);
	if (data->map[y][x] == WALL || data->map[y][x] == PLAYER)
		return (i);
	if (c == COLL && data->map[y][x] == EXIT)
		return (i);
	if (data->map[y][x] == c)
		i++;
	data->map[y][x] = PLAYER;
	i += flood_fill(data, y, x + 1, c);
	i += flood_fill(data, y, x - 1, c);
	i += flood_fill(data, y + 1, x, c);
	i += flood_fill(data, y - 1, x, c);
	return (i);
}

static int	accessible_by_player(t_mlx_data *data, int y, int x)
{
	if (data->map[y - 1][x] == PLAYER || data->map[y + 1][x] == PLAYER \
		|| data->map[y][x - 1] == PLAYER || data->map[y][x + 1] == PLAYER)
		return (1);
	return (0);
}

static int	validate_map_2(t_mlx_data *data, char *mapname)
{
	int	exit_y;
	int	exit_x ;

	data->map[data->player_y][data->player_x] = EMPTY;
	if (!(flood_fill(data, data->player_y, data->player_x, COLL) \
		== data->diamonds))
	{
		ft_printf("ERROR: Collectibles not accesible\n");
		return (0);
	}
	exit_y = 0;
	exit_x = 0;
	get_obj_pos(data->map, &exit_y, &exit_x, EXIT);
	if (!accessible_by_player(data, exit_y, exit_x))
	{
		ft_printf("ERROR: Exit not accessible\n");
		return (0);
	}
	free_map(data->map);
	data->map = create_map(mapname, &data->readline_failed);
	if (!data->map)
		return (0);
	return (1);
}

int	validate_map(t_mlx_data *data, char *mapname)
{
	if (!check_rectanglar(data))
	{
		ft_printf("ERROR: Map not rectangular\n");
		return (0);
	}
	if (!check_walls(data))
	{
		ft_printf("ERROR: walls not surround\n");
		return (0);
	}
	if (!parse_map(data))
	{
		ft_printf("ERROR: Wrong assets\n");
		return (0);
	}
	return (validate_map_2(data, mapname));
}
