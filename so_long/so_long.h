/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:59:59 by sopperma          #+#    #+#             */
/*   Updated: 2024/06/24 14:32:52 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "libft/libft.h"
# include <fcntl.h>

# define MALLOC_ERROR	1
# define ASSET_W		   20
# define ASSET_H		   20

# define PLAYER	'P'
# define WALL	'1'
# define COLL	'C'
# define EXIT	'E'
# define EMPTY	'0'

# define NL		'\n'
# define UP		'w'
# define DOWN	's'
# define LEFT	'a'
# define RIGHT	'd'

typedef struct s_counters
{
	int	p;
	int	e;
	int	c;
}	t_counters;

typedef struct s_wallsize
{
	int	top;
	int	bottom;
	int	left;
	int	right;
}	t_wallsize;

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixel;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	char	**map;
	int		map_h;
	int		map_w;
	int		player_x;
	int		player_y;
	int		diamonds;
	int		steps;
	int		readline_failed;
}	t_mlx_data;

int		paint_map(t_mlx_data *data);
int		keyhandler(int key, t_mlx_data	*data);
void	free_map(char **map);
char	**create_map(char	*mapname, int *fail);
int		close_game(t_mlx_data	*data);

int		validate_map(t_mlx_data *data, char *mapname);

int		check_rectanglar(t_mlx_data *data);
int		check_walls(t_mlx_data *data);
int		parse_map(t_mlx_data *data);
int		get_obj_pos(char **map, int *y, int *x, char obj);
#endif