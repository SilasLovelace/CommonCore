/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:13:35 by sopperma          #+#    #+#             */
/*   Updated: 2024/06/18 13:19:48 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


#define MALLOC_ERROR	1
#define WIDTH		   400
#define HEIGHT		   400

void free_map(char **map)
{
	int i = 0;
	while(map[i])
		free(map[i++]);
	free(map);
	map = NULL;
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
	printf("%d pressed\n", key);
	return (0);
}


char **create_map(char	*mapname)
{
	
	int		fd = open(mapname, O_RDONLY);
	char	*line;
	int i = 0;
	int lines = 0;
	
	line = get_next_line(fd);
	while (line)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	printf("%d lines\n", lines);
	close(fd);
	char	**map = malloc(sizeof(char **) * (lines + 1));
	fd = open(mapname, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		map[i++] = line;
		free(line);
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

int main (int ac, char **av)
{
	static t_mlx_data	data = {NULL, NULL};
	int h = 400;
	int i = 0;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (0);
	data.win_ptr = mlx_new_window(data.mlx_ptr, HEIGHT, WIDTH, "GAME");
	if (data.win_ptr == NULL)
	{
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return(MALLOC_ERROR);
	}
	data.map = create_map("map.map");
	/* while (i < 3)
		printf("%s", data.map[i++]); */
	data.img.img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "test.xpm", &h, &h);
	if (data.img.img_ptr)
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.img_ptr, 0, 0);
	mlx_destroy_image(data.mlx_ptr, data.img.img_ptr);
	mlx_key_hook(data.win_ptr, keyhandler, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}