/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_coordinate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbolat <bbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:13:43 by bbolat            #+#    #+#             */
/*   Updated: 2022/08/26 14:21:10 by bbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SLHEADER.h"

int	ft_get_mapsx(char *str)
{
	int			fd;
	int			counter;
	int			byte;
	char		p;

	fd = open(str, O_RDONLY);

	if (fd == -1)
	{
		ft_printf("\033[31;6mError\n\t\033[0mFile not found!!\n");
		exit(1);
	}
	byte = 1;
	counter = 0;
	while (byte != 0)
	{
		byte = read(fd, &p, 1);
		if (p == '\n')
			break ;
		counter++;
	}
	return (counter);
}

int	ft_get_mapsy(char *str)
{
	int			fd;
	int			counter;
	int			byte;
	char		c;

	byte = 1;
	counter = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("\033[31;6mError\n\t\033[0mFile not found!!\n");
		exit(1);
	}

	while (byte != 0)
	{
		byte = read(fd, &c, 1);
		if (c == '\n')
			counter++;
		else if (c == '\0')
			break ;
	}
	close(fd);
	return (counter - 1);
}
