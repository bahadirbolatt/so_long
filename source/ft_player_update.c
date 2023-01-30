/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_update.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbolat <bbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:14:04 by bbolat            #+#    #+#             */
/*   Updated: 2022/08/26 09:23:17 by bbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SLHEADER.h"

void	player_w(t_data *data)
{
	if (data->mapstr[data->player_y][data->player_x] == 'E' && data->coin == 0)
	{
		mlx_clear_window(data->mlx, data->win);
		data->mapstr[data->player_y + 1][data->player_x] = '0';
		data->moves++;
		map_draw(data, 2);
		ft_putstr_color_fd(ANSI_GREEN, "\nFINISHED:)", 1);
		exit(0);
	}
	else if (data->mapstr[data->player_y][data->player_x] == '1'
			|| data->mapstr[data->player_y][data->player_x] == 'E')
	{
		data->player_y += 1;
		data->control = 0;
	}
	else
	{
		mlx_clear_window(data->mlx, data->win);
		if (data->mapstr[data->player_y][data->player_x] == 'C')
			data->coin -= 1;
		data->mapstr[data->player_y][data->player_x] = 'P';
		data->mapstr[data->player_y + 1][data->player_x] = '0';
		data->moves++;
		map_draw(data, 2);
	}
}

void	player_s(t_data *data)
{
	if (data->mapstr[data->player_y][data->player_x] == 'E' && data->coin == 0)
	{
		mlx_clear_window(data->mlx, data->win);
		data->mapstr[data->player_y - 1][data->player_x] = '0';
		data->moves++;
		map_draw(data, 2);
		ft_putstr_color_fd(ANSI_GREEN, "FINISHED:)", 1);
		exit(0);
	}
	else if (data->mapstr[data->player_y][data->player_x] == '1'
		|| data->mapstr[data->player_y][data->player_x] == 'E')
	{
		data->player_y -= 1;
		data->control = 0;
	}
	else
	{
		mlx_clear_window(data->mlx, data->win);
		if (data->mapstr[data->player_y][data->player_x] == 'C')
			data->coin -= 1;
		data->mapstr[data->player_y][data->player_x] = 'P';
		data->mapstr[data->player_y - 1][data->player_x] = '0';
		data->moves++;
		map_draw(data, 2);
	}
}

void	player_d(t_data *data)
{
	if (data->mapstr[data->player_y][data->player_x] == 'E' && data->coin == 0)
	{
		mlx_clear_window(data->mlx, data->win);
		data->mapstr[data->player_y][data->player_x - 1] = '0';
		data->moves++;
		map_draw(data, 3);
		ft_putstr_color_fd(ANSI_GREEN, "\nFINISHED:)", 1);
		exit(0);
	}
	else if (data->mapstr[data->player_y][data->player_x] == '1'
		|| data->mapstr[data->player_y][data->player_x] == 'E')
	{
		data->player_x -= 1;
		data->control = 0;
	}
	else
	{
		mlx_clear_window(data->mlx, data->win);
		if (data->mapstr[data->player_y][data->player_x] == 'C')
			data->coin -= 1;
		data->mapstr[data->player_y][data->player_x] = 'P';
		data->mapstr[data->player_y][data->player_x - 1] = '0';
		data->moves++;
		map_draw(data, 3);
	}
}

void	player_a(t_data *data)
{
	if (data->mapstr[data->player_y][data->player_x] == 'E' && data->coin == 0)
	{
		mlx_clear_window(data->mlx, data->win);
		data->mapstr[data->player_y][data->player_x + 1] = '0';
		data->moves++;
		map_draw(data, 1);
		ft_putstr_color_fd(ANSI_GREEN, "\nFINISHED:)", 1);
		exit(0);
	}
	else if (data->mapstr[data->player_y][data->player_x] == '1'
		|| data->mapstr[data->player_y][data->player_x] == 'E')
	{
		data->control = 0;
		data->player_x += 1;
	}
	else
	{
		mlx_clear_window(data->mlx, data->win);
		if (data->mapstr[data->player_y][data->player_x] == 'C')
			data->coin -= 1;
		data->mapstr[data->player_y][data->player_x] = 'P';
		data->mapstr[data->player_y][data->player_x + 1] = '0';
		data->moves++;
		map_draw(data, 1);
	}
}
