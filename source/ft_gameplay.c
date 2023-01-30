/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gameplay.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbolat <bbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:13:38 by bbolat            #+#    #+#             */
/*   Updated: 2022/08/26 14:22:29 by bbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SLHEADER.h"

static int	keypress(int keycode, t_data *data)
{
	data->control = 1;
	if (keycode == ESC || keycode == Q)
	{
		write(1, "\033[1;34m\nTHE GAME WAS FINISHED.\n", 34);
		exit_game(data);
	}
	keyprocessing(keycode, data);
	if (data->control == 1)
	{
		ft_putstr_color_fd(ANSI_YELLOW, "\rMoves: ", 1);
		ft_putstr_fd(ANSI_GREEN, 1);
		ft_printnbr(data->moves);
	}
	return (0);
}

void	gameplay(t_data *data)
{
	mlx_hook(data->win, 2, 0, keypress, data);
	mlx_hook(data->win, 17, 0, exit_game, data);
	mlx_hook(data->win, 12, 0, map_draw, data);
}
