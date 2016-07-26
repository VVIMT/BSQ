# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: becorbel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/25 12:02:55 by becorbel          #+#    #+#              #
#    Updated: 2016/07/26 19:35:32 by becorbel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = SRCS/ft_putchar.c SRCS/ft_putstr.c SRCS/ft_strcat.c SRCS/create_buff.c SRCS/bsq.c SRCS/ft_print.c SRCS/caracters.c SRCS/verif_argc.c SRCS/read.c SRCS/main.c

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
