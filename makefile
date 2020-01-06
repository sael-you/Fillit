#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-kobi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/10 19:17:37 by yel-kobi          #+#    #+#              #
#    Updated: 2019/07/10 19:17:48 by yel-kobi         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit
SRC = ./src/solver.c ./src/shape.c ./src/checker.c ./src/drag.c ./src/tools.c
OBJECT = ./src/solver.o ./src/shape.o ./src/checker.o ./src/drag.o
FLAGS = -Wall -Werror -Wextra 
DELETE = rm -f

all : $(NAME)

$(NAME) : 
	make -C libft
	gcc $(FLAGS) $(SRC) ./libft/libft.a -o $(NAME)
clean :
	make clean -C libft
	$(DELETE) $(OBJECT)

fclean : clean
	make fclean -C libft
	$(DELETE) $(NAME) 

re : fclean all
