/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbolat <bbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:13:22 by bbolat            #+#    #+#             */
/*   Updated: 2022/08/25 13:13:23 by bbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SLHEADER.h"

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->mapstr[i])
	{
		free(data->mapstr[i]);
		i++;
	}
	free(data->mapstr);
}

int	exit_game(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img_backg);
	mlx_destroy_image(data->mlx, data->img_wall);
	mlx_destroy_image(data->mlx, data->img_player);
	mlx_destroy_image(data->mlx, data->img_collect);
	mlx_destroy_image(data->mlx, data->img_exit);
	mlx_destroy_window(data->mlx, data->win);
	free_map(data);
	free(data->mlx);
	exit(0);
	return (0);
}
