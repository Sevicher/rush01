/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleland <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 17:42:20 by oleland           #+#    #+#             */
/*   Updated: 2019/07/22 20:51:24 by oleland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		valid(char **argv)
{
	int		i;
	int		j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!((argv[i][j] >= '.' && argv[i][j] <= '9') ||
						argv[i][j] == '.'))
				return (0);
			if (argv[i][j] >= '1' && argv[i][j] <= '9')
				--g_freecount;
		}
		if (j != 9)
			return (0);
	}
	return (1);
}

int		is_x(char **argv, int y, char pod)
{
	int		i;

	i = -1;
	while (++i < 9)
		if (argv[y][i] == pod)
			return (0);
	return (1);
}

int		is_y(char **argv, int x, char pod)
{
	int		i;

	i = 0;
	while (++i < 10)
		if (argv[i][x] == pod)
			return (0);
	return (1);
}

int		is_norm_square(char **argv, int yi, int xi, char pod)
{
	int		xmax;
	int		ymax;
	int		i;

	xmax = xi + 3;
	ymax = yi + 3;
	while (yi < ymax)
	{
		i = xi - 1;
		while (++i < xmax)
			if (argv[yi][i] == pod)
				return (0);
		++yi;
	}
	return (1);
}

int		is_square(char **argv, int y, int x, char pod)
{
	int		yi;
	int		xi;

	yi = 1;
	xi = 0;
	if (y == 1)
		yi = 4;
	if (x == 1)
		xi = 3;
	if (y > 1)
		yi = 7;
	if (x > 1)
		xi = 6;
	return (is_norm_square(argv, yi, xi, pod));
}
