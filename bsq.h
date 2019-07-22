/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleland <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 17:42:36 by oleland           #+#    #+#             */
/*   Updated: 2019/07/22 20:51:27 by oleland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int		valid(char **argv);
int		is_x(char **argv, int y, char pod);
int		is_y(char **argv, int x, char pod);
int		is_norm_square(char **argv, int yi, int xi, char pod);
int		is_square(char **argv, int y, int x, char pod);
int		can_use(char **argv, int y, int x, char pod);
int		rec_sol(char ***argv, int y, int x);
void	print_sudoku(char **argv);
int		solution(char ***argv);

int		g_freecount;

#endif
