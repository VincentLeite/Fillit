#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vleite <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/03 15:23:25 by vleite            #+#    #+#              #
#    Updated: 2015/12/14 15:37:20 by mlavanan         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

LIB = libft.a

SRC = 	ft_fillit.c \
		ft_printmap.c \
		ft_setupleft.c \
		ft_checktetro.c \
		ft_move.c \
		ft_tetro.c \
		ft_tmp.c \
		ft_checktools.c

all:
	make -C libft all
	gcc -Wall -Wextra -Werror $(SRC) $(LIB) -Ilibft -o $(NAME)

clean:
	make -C libft clean

fclean: clean
	make -C libft fclean
	rm -rf $(NAME)

re: fclean all
	make -C libft re