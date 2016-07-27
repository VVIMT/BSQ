# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: becorbel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/27 11:06:36 by becorbel          #+#    #+#              #
#    Updated: 2016/07/27 18:23:49 by becorbel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = SRCS/ft_putchar.c SRCS/ft_putstr.c SRCS/ft_strcat.c SRCS/create_buff.c SRCS/bsq.c SRCS/ft_print.c SRCS/caracters.c SRCS/verif_argc.c SRCS/read.c SRCS/main.c SRCS/ft_atoi.c

OBJS = *.o

NAME = bsq

FLAGS = -Werror -Wextra -Wall

$(NAME) :
	gcc -o $(NAME) $(FLAGS) $(SRCS)

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm $(NAME)

re : fclean all
