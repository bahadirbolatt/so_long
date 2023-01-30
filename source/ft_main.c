/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbolat <bbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:13:55 by bbolat            #+#    #+#             */
/*   Updated: 2022/08/26 14:25:08 by bbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SLHEADER.h"

static int	argv_checker(char *argv)
{
	int	i;

	if (!argv)
		return (0);
	i = 0;
	while (argv[i])
		i++;
	i -= 1;
	if (argv[i] == 'r' && argv[i - 1] == 'e' && argv[i - 2] == 'b'
		&& argv [i - 3] == '.')
		return (1);
	return (0);
}

int	control(t_data *data, char *path)
{
	int	result;

	data->coord_x = ft_get_mapsx(path);
	data->coord_y = ft_get_mapsy(path);
	ft_create_matrix(data, path, 0, 0);
	result = ft_map_control(data);
	if (result == 0)
		exit(1);
	else
		return (1);
}

int	main(int argc, char *map[])
{
	t_data	data;
	int		result;

	if (argc == 2)
	{
		result = argv_checker(map[1]);
		if (result && control(&data, map[1]))
		{
			map_init(&data);
			gameplay(&data);
			mlx_loop(data.mlx);
		}
		else
			write(1, "\033[0;36mError\nfile ext. error!\n", 30);
	}
	else
	{
		write(1, "\033[0;36mError\narg error!\n", 24);
		exit(1);
	}
	return (0);
}
