# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aomman <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 12:30:39 by aomman            #+#    #+#              #
#    Updated: 2022/03/24 23:05:40 by aomman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



src = draw_map.c\
ft_check_ber.c\
ft_putnbr.c\
ft_split.c\
get_next_line.c\
mouvments.c\
moves.c\
valid_walls.c\
ft_free.c
NAME = so_long

all : $(NAME) $(src)

$(NAME) :
	gcc -Wall -Wextra -Werror $(src) minilibx-linux/libmlx.a -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)

clean : 
	rm -f $(NAME)

fclean : clean

re : fclean all
