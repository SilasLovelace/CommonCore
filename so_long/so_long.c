/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:13:35 by sopperma          #+#    #+#             */
/*   Updated: 2024/06/19 20:06:21 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_map(char **map)
{
	int i = 0;
	while(map[i])
		free(map[i++]);
	free(map);
	map = NULL;
}
int valid_move(char move, t_mlx_data *data)
{
	if (move == 'w')
		if(data->player_y != 0 && data->map[data->player_y - 1][data->player_x] != '1')
			return (1);
	if (move == 's')
		if(data->map[data->player_y + 1] && data->map[data->player_y + 1][data->player_x] != '1')
			return (1);
	/* if (move == 'a')
	if (move == 's')
	if (move == 'd') */
	return (0);
}



int check_move(char move, t_mlx_data *data)
{
	int y;
	(void)move;

	y = 0;
	
	while (!ft_strchr(data->map[y], 'P'))
		y++;
	data->player_y = y;
	data->player_x = ft_strchr(data->map[y], 'P') - data->map[y];
	// printf("player at x:%d y:%d\n", x , y);
	if (move == 'w' && valid_move(move, data))
	{
		printf("move up");
		data->map[data->player_y - 1][data->player_x] = 'P';
		data->map[data->player_y][data->player_x] = '0';
		data->player_y -= 1;
	}
	if (move == 's' && valid_move(move, data))
	{
		printf("move down");
		data->map[data->player_y + 1][data->player_x] = 'P';
		data->map[data->player_y][data->player_x] = '0';
		data->player_y += 1;
	}
/* 	if (move == 'a')
	if (move == 'd') */
	printf("player at x:%d y:%d\n", data->player_x , data->player_y);
	paint_map(data);
	return (0);
}
int keyhandler(int key, t_mlx_data	*data)
{
	if (key == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		free_map(data->map);
		exit(1);
	}
	if (key == XK_w)
		check_move('w', data);
	if (key == XK_s)
		check_move('s', data);
	if (key == XK_space)
		printf("player at x:%d y:%d\n", data->player_x , data->player_y);
	printf("%d pressed\n", key);
	return (0);
}

char **create_map(char	*mapname)
{
	int		fd = open(mapname, O_RDONLY);
	char	*line;
	char	*file = NULL;
	char	**map;
	char	*tmp;
	
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

int set_windowsize(t_mlx_data *data)
{
	int i;
	
	i = 0;
	while(data->map[i])
		i++;
	data->map_h = i;
	i = 0;
	while(data->map[0][i] && data->map[0][i] != '\n')
		i++;
	data->map_w = i;
	return (1);
}


int main (int ac, char **av)
{
	(void) ac;
	(void) av;
	static t_mlx_data	data;
	ft_bzero(&data, sizeof(data));

	data.map = create_map("map.map");
	if (!data.map)
		return (0);
	set_windowsize(&data);
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (0);
	data.win_ptr = mlx_new_window(data.mlx_ptr, (ASSET_W * data.map_w), (ASSET_H * data.map_h), "GAME");
	if (data.win_ptr == NULL)
	{
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return(MALLOC_ERROR);
	}
	paint_map(&data);
	mlx_key_hook(data.win_ptr, keyhandler, &data);
	mlx_loop(data.mlx_ptr);
	return (free_map(data.map), 0);
}
