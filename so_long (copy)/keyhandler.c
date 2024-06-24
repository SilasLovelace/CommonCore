/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:13:33 by sopperma          #+#    #+#             */
/*   Updated: 2024/06/24 11:30:01 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	get_target(t_mlx_data *data, int y, int x)
{
	return (data->map[data->player_y + y][data->player_x + x]);
}

char	valid_move(char move, t_mlx_data *data)
{
	if (move == UP)
		if (data->player_y != 0 && get_target(data, -1, 0) != WALL)
			return (get_target(data, -1, 0));
	if (move == DOWN)
		if (data->player_y < data->map_h - 1 && get_target(data, 1, 0) != WALL)
			return (get_target(data, 1, 0));
	if (move == LEFT)
		if (data->player_x != 0 && get_target(data, 0, -1) != WALL)
			return (get_target(data, 0, -1));
	if (move == RIGHT)
		if (data->player_x < data->map_w - 1 && get_target(data, 0, 1) != WALL)
			return (get_target(data, 0, 1));
	return (0);
}

int	perform_move(t_mlx_data *data, char move, int y, int x)
{
	if (valid_move(move, data))
	{
		if (valid_move(move, data) == COLL)
			data->diamonds--;
		if (valid_move(move, data) == EXIT && !data->diamonds)
			keyhandler(XK_Escape, data);
		if (valid_move(move, data) == EXIT && data->diamonds)
			return (1);
		data->map[data->player_y + y][data->player_x + x] = PLAYER;
		data->player_y += y;
		data->player_x += x;
		data->map[data->player_y - y][data->player_x - x] = EMPTY;
		data->steps++;
		printf("steps: %d\n", data->steps);
	}
	return (1);
}

int	check_move(char move, t_mlx_data *data)
{
	if (move == UP && valid_move(move, data))
		perform_move(data, move, -1, 0);
	if (move == DOWN && valid_move(move, data))
		perform_move(data, move, 1, 0);
	if (move == LEFT && valid_move(move, data))
		perform_move(data, move, 0, -1);
	if (move == RIGHT && valid_move(move, data))
		perform_move(data, move, 0, 1);
	paint_map(data);
	return (0);
}

int	keyhandler(int key, t_mlx_data	*data)
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
		check_move(UP, data);
	if (key == XK_s)
		check_move(DOWN, data);
	if (key == XK_a)
		check_move(LEFT, data);
	if (key == XK_d)
		check_move(RIGHT, data);
	if (key == XK_space)
	{
		printf("player at x:%d y:%d\n", data->player_x, data->player_y);
		printf("diamonds: %d\n", data->diamonds);
		printf("steps: %d\n", data->steps);
		printf("height: %d\n", data->map_h);
		printf("width: %d\n", data->map_w);
	}
	// if (key == XK_f)
	// {
	// 	printf("flodding\n");
	// 	data->map[data->player_y][data->player_x] = EMPTY;
	// 	paint_map(data);
	// 	printf("coins found %d\n", flood_fill(data, data->player_y, data->player_x, COLL));
	// 	// printf("doors found %d\n", flood_fill(data, data->player_y, data->player_x, EXIT));
	// 	printf("flooded\n");
	// }
	return (0);
}
