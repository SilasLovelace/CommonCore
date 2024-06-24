/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopperma <sopperma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:43:33 by sopperma          #+#    #+#             */
/*   Updated: 2024/06/24 14:44:06 by sopperma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_mlx_data	*data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_map(data->map);
	exit(1);
}
