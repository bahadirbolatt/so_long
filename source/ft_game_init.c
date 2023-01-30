/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbolat <bbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:13:34 by bbolat            #+#    #+#             */
/*   Updated: 2022/08/25 20:25:32 by bbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SLHEADER.h"

static void	img_init(t_data *data)
{
	data->img_backg = mlx_xpm_file_to_image
		(data->mlx, "assets/bg.xpm", &data->img_w, &data->img_h);
	data->img_wall = mlx_xpm_file_to_image
		(data->mlx, "assets/obs.xpm", &data->img_w, &data->img_h);
	data->img_player = mlx_xpm_file_to_image
		(data->mlx, "assets/mr.xpm", &data->img_w, &data->img_h);
	data->img_collect = mlx_xpm_file_to_image
		(data->mlx, "assets/c.xpm", &data->img_w, &data->img_h);
	data->img_exit = mlx_xpm_file_to_image
		(data->mlx, "assets/dc.xpm", &data->img_w, &data->img_h);
	data->img_player2 = mlx_xpm_file_to_image
		(data->mlx, "assets/ml.xpm", &data->img_w, &data->img_h);
}

void	map_init(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->coord_x * PIXEL,
			data->coord_y * PIXEL, "so_long");
	data->moves = 0;
	img_init(data);
	map_draw(data, 2);
}
