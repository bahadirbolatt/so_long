/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyprocess.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbolat <bbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:13:48 by bbolat            #+#    #+#             */
/*   Updated: 2022/08/25 13:13:49 by bbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SLHEADER.h"

int	keyprocessing(int keyevent, t_data *data)
{
	if (keyevent == W || keyevent == UP)
	{
		data->player_y -= 1;
		player_w(data);
	}
	else if (keyevent == A || keyevent == LEFT)
	{
		data->player_x -= 1;
		player_a(data);
	}
	else if (keyevent == D || keyevent == RIGHT)
	{
		data->player_x += 1;
		player_d(data);
	}
	else if (keyevent == S || keyevent == DOWN)
	{
		data->player_y += 1;
		player_s(data);
	}
	return (1);
}
