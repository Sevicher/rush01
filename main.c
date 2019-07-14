/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleland <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 19:25:44 by oleland           #+#    #+#             */
/*   Updated: 2019/07/14 20:05:32 by oleland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"
#include <stdio.h>
int 		valid(char **argv)
{
	int 	i;
	int 	j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!((argv[i][j] >= '.' && argv[i][j] <= '9') || argv[i][j] == '.'))
				return (0);
			if (argv[i][j] >= '1' && argv[i][j] <= '9')
				--g_freecount;
		}
		if (j != 9)
			return (0);
	}
	return (1);
}

int 		is_x(char **argv, int y, char pod)
{
	int 	i;

	i = -1;
	while (++i < 9)
		if (argv[y][i] == pod)
			return (0);
	return (1);
}

int 		is_y(char **argv, int x, char pod)
{
	int 	i;

	i = 0;
	while (++i < 10)
		if (argv[i][x] == pod)
			return (0);
	return (1);
}

int 		is_norm_square(char **argv, int yi, int xi, char pod)
{
	int 	xmax;
	int 	ymax;
	int 	i;

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

int 		is_square(char **argv, int y, int x, char pod)
{
	int 	yi;
	int 	xi;

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

int 		can_use(char **argv, int y, int x, char pod)
{
	return (is_x(argv, y, pod) && is_y(argv, x, pod)
		&& is_square(argv, (y - 1)/3, x/3, pod));
}

int 		rec_sol(char ***argv, int y, int x)
{
	char 	pod;
	char 	**ar;

	ar = *argv;
	pod = '1';
	if (x > 8)
	{
		x = 0;
		++y;
	}
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

void		print_sudoku(char **argv)
{
	int 	y;
	int 	x;

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

int 		solution(char ***argv)
{
	if (!rec_sol(argv, 1, 0))
		return (0);
	return (1);
}

int 		main(int argc, char **argv)
{
	g_freecount = 81;

	if (argc == 10 && valid(argv))
	{
		if (solution(&argv))
			print_sudoku(argv);
		else
			write(1, "No solvation\n", 13);
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
