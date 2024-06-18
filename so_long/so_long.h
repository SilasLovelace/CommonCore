/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:18:54 by sopperma          #+#    #+#             */
/*   Updated: 2024/06/18 12:28:05 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <X11/keysym.h>
# include "get_nextline/get_next_line.h"
# include <fcntl.h>

typedef struct s_img
{
    void    *img_ptr;
    char    *img_pixel;
    int     bits_per_pixel;
    int     endian;
    int     line_len;
}       t_img;

typedef struct s_data
{
    void    *mlx_ptr;
    void    *win_ptr;
    t_img   img;
    char     **map;
}   t_mlx_data;

typedef enum movement
{
	move_up = 119,
	move_down = 115,
	move_left = 97,
	move_right = 100,
    escape = 65307
	// ON_MOUSEDOWN = 4,
	// ON_MOUSEUP = 5,
	// ON_MOUSEMOVE = 6,
	// ON_EXPOSE = 12,
	// ON_DESTROY = 17
}   t_key_enum;

#endif