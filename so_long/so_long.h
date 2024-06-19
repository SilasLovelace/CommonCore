/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:18:54 by sopperma          #+#    #+#             */
/*   Updated: 2024/06/19 20:06:35 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <X11/keysym.h>
# include "libft/libft.h"
# include <fcntl.h>

#define MALLOC_ERROR	1
#define ASSET_W		   20
#define ASSET_H		   20

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
    int     map_h;
    int     map_w;
    int     player_x;
    int     player_y;
}   t_mlx_data;

int paint_map(t_mlx_data *data);
#endif