/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   map_validator.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: sopperma <sopperma@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/06/20 12:34:15 by sopperma		  #+#	#+#			 */
/*   Updated: 2024/06/20 15:06:49 by sopperma		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "so_long.h"

int get_obj_pos(t_mlx_data *data, char obj)
{
	int	i;

	i = 0;
	while (!ft_strchr(data->map[i], obj))
		i++;
	data->player_y = i;
	data->player_x = ft_strchr(data->map[i], obj) - data->map[i];
	return (1);
}

int flood_fill(char **map, int y, int x, char c)
{
	int	i;

	i = 0;
	if (x < 0 || !map[x] || y < 0 || !map[y])
		return (i);
	if (map[y][x] == WALL || map[y][x] == PLAYER)
		return (i);
	if (c == COLL && map[y][x] == EXIT)
		return (i);
	if(map[y][x] == c)
		i++;
	map[y][x] = PLAYER;
	// paint_map(data);
	i += flood_fill(map, y, x+1, c);
    i += flood_fill(map, y, x-1, c);
    i += flood_fill(map, y+1, x, c);
    i += flood_fill(map, y-1, x, c);
	return (i);
}

/* int flood_fill(t_mlx_data *data, int y, int x, char c)
{
	int	i;

	i = 0;
	if (x < 0 || x > data->map_w - 1 || y < 0 || !data->map[y])
		return (i);
	if (data->map[y][x] == WALL || data->map[y][x] == PLAYER)
		return (i);
	if (c == COLL && data->map[y][x] == EXIT)
		return (i);
	if(data->map[y][x] == c)
		i++;
	data->map[y][x] = PLAYER;
	// paint_map(data);
	i += flood_fill(data, y, x+1, c);
    i += flood_fill(data, y, x-1, c);
    i += flood_fill(data, y+1, x, c);
    i += flood_fill(data, y-1, x, c);
	return (i);
} */

int	validate_map(t_mlx_data *data, char *mapname)
{
	char	**mapcopy;

	mapcopy = create_map(mapname);
	
	(void)mapname;
	if (!check_rectanglar(data))
	{
		printf("ERROR: Map not rectangular\n");
		return (0);
	}
	if (!check_walls(data))
	{
		printf("ERROR: walls not surround\n");
		return (0);
	}
	if (!parse_map(data))
	{
		printf("ERROR: Wrong assets\n");
		return (0);
	}
	mapcopy[data->player_y][data->player_x] = EMPTY;
	printf("colls : %d\n", data->diamonds);
	printf("colls accesible: %d\n", flood_fill(mapcopy, data->player_y, data->player_x, COLL));
	data->map[data->player_y][data->player_x] = EMPTY;
	printf("colls accesible: %d\n", flood_fill(data->map, data->player_y, data->player_x, COLL));
	/* if (!(flood_fill(mapcopy, data->player_y, data->player_x, COLL) == data->diamonds))
	{
		printf("ERROR: colls not accesible\n");
		return (0);
	} */
	return (1);
}
