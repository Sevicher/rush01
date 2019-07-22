# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oleland <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/22 18:35:43 by oleland           #+#    #+#              #
#    Updated: 2019/07/22 18:37:14 by oleland          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -o

NAME = display_file

CFILES = *.c

HFILES =

OFILES =

all: $(NAME)
$(NAME):
	$(CC) $(CFLAGS) $(NAME) $(HFILES) $(CFILES)

clean:
	/bin/rm -rf $(NAME)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all

