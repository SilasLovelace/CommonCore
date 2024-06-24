/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:13:35 by sopperma          #+#    #+#             */
/*   Updated: 2024/06/24 15:06:29 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_diamonds(char *map)
{
	int	diamonds;

	diamonds = 0;
	while (*map)
	{
		if (*map == COLL)
			diamonds++;
		map++;
	}
	return (diamonds);
}

char	**create_map(char	*mapname, int *fail)
{
	int			fd;
	char		*line;
	char		*file;
	char		**map;
	char		*tmp;

	file = NULL;
	fd = open(mapname, O_RDONLY);
	line = get_next_line(fd, fail);
	if (!line)
		return (NULL);
	while (line)
	{
		tmp = file;
		file = ft_strjoin(tmp, line);
		if (!file)
			return (free(tmp), free(line), get_next_line(-1, fail), NULL);
		free(tmp);
		free(line);
		line = get_next_line(fd, fail);
	}
	map = ft_split(file, '\n');
	if ((close(fd) == -1 || *fail) && map)
		return (free_map(map), free(file), ft_printf("Mapmake fail\n"), NULL);
	return (free(file), map);
}

int	set_windowsize_player_pos(t_mlx_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
		i++;
	data->map_h = i;
	i = 0;
	while (data->map[0][i])
		i++;
	data->map_w = i;
	get_obj_pos(data->map, &data->player_y, &data->player_x, PLAYER);
	return (1);
}

int	initialize_game(t_mlx_data	*data, char *mapname)
{
	if (ft_strlen(mapname) < 5 || ft_strncmp(mapname + ft_strlen(mapname) - 4, \
		".ber", 4))
		return (ft_printf("Invalid Map name\n"), 0);
	if (open(mapname, O_RDONLY) == -1)
		return (ft_printf("Map not found\n"), 0);
	ft_bzero(data, sizeof(data));
	data->map = create_map(mapname, &data->readline_failed);
	if (!data->map)
		return (0);
	set_windowsize_player_pos(data);
	if (!validate_map(data, mapname))
	{
		if (data->map)
			free_map(data->map);
		return (0);
	}
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	static t_mlx_data	data;

	if (ac == 2)
	{
		if (!initialize_game(&data, av[1]))
			return (0);
		data.win_ptr = mlx_new_window(data.mlx_ptr, (ASSET_W * data.map_w), \
			(ASSET_H * data.map_h), "GAME");
		if (data.win_ptr == NULL)
		{
			mlx_destroy_display(data.mlx_ptr);
			free(data.mlx_ptr);
			return (MALLOC_ERROR);
		}
		paint_map(&data);
		mlx_key_hook(data.win_ptr, keyhandler, &data);
		mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, \
			&close_game, &data);
		mlx_loop(data.mlx_ptr);
	}
	ft_printf("Wrong amount of arguments!!!!\n");
	return (0);
}
