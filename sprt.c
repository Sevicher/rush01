/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprt.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleland <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:16:14 by oleland           #+#    #+#             */
/*   Updated: 2019/07/22 20:51:22 by oleland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		sprt_rec_sol(int *x, int *y)
{
	*x = 0;
	++*y;
	return (*y);
}

int		can_use(char **argv, int y, int x, char pod)
{
	return (is_x(argv, y, pod) && is_y(argv, x, pod)
			&& is_square(argv, (y - 1) / 3, x / 3, pod));
}

int		rec_sol(char ***argv, int y, int x)
{
	char		pod;
	char		**ar;

	ar = *argv;
	pod = '1';
	if (x > 8)
		sprt_rec_sol(&x, &y);
	if (g_freecount == 0)
		return (1);
	if (ar[y][x] != '.')
		return (rec_sol(argv, y, x + 1));
	while (pod <= '9')
	{
		if (can_use(*argv, y, x, pod))
		{
			ar[y][x] = pod;
			--g_freecount;
			if (rec_sol(argv, y, x + 1))
				return (1);
			++g_freecount;
			ar[y][x] = '.';
		}
		++pod;
	}
	return (0);
}

void	print_sudoku(char **argv)
{
	int		y;
	int		x;

	y = 0;
	while (++y < 10)
	{
		x = -1;
		while (++x < 9)
		{
			write(1, &argv[y][x], 1);
			if (x < 8)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
}

int		solution(char ***argv)
{
	if (!rec_sol(argv, 1, 0))
		return (0);
	return (1);
}
