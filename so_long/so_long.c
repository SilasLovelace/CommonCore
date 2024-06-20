/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:13:35 by sopperma          #+#    #+#             */
/*   Updated: 2024/06/20 17:58:09 by sopperma         ###   ########.fr       */
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
// char	*file = NULL??;

char	**create_map(char	*mapname)
{
	int			fd;
	char		*line;
	static char	*file = NULL;
	char		**map;
	char		*tmp;

	fd = open(mapname, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	while (line)
	{
		tmp = file;
		file = ft_strjoin(tmp, line);
		if (!file)
			return (free(tmp), free(line), get_next_line(-1), NULL);
		free(tmp);
		free(line);
		line = get_next_line(fd);
	}
	map = ft_split(file, '\n');
	free(file);
	if (close(fd) == -1)
		return (free_map(map), NULL);
	return (map);
}

int	set_windowsize_player_pos(t_mlx_data *data)
{
	int	i;
	int	y;
	
	i = 0;
	while (data->map[i])
		i++;
	data->map_h = i;
	i = 0;
	while (data->map[0][i])
		i++;
	data->map_w = i;
	y = 0;
	while (!ft_strchr(data->map[y], PLAYER))
		y++;
	data->player_y = y;
	data->player_x = ft_strchr(data->map[y], PLAYER) - data->map[y];
	return (1);
}

// check statics allowed?

int	main(int ac, char **av)
{
	static t_mlx_data	data;

	if (ac == 2)
	{
		ft_bzero(&data, sizeof(data));
		data.map = create_map(av[1]);
		if (!data.map)
			return (0);
		set_windowsize_player_pos(&data);
		if (!validate_map(&data, av[1]))
			return (free_map(data.map), 0);
		data.mlx_ptr = mlx_init();
		if (data.mlx_ptr == NULL)
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
		mlx_loop(data.mlx_ptr);
	}
	printf("Wrong amount of arguments!!!!\n");
	return (0);
}
