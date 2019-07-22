/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleland <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 17:32:21 by oleland           #+#    #+#             */
/*   Updated: 2019/07/22 18:39:13 by oleland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		main(int argc, char **argv)
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
