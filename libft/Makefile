#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-kobi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/28 02:31:10 by yel-kobi          #+#    #+#              #
#    Updated: 2019/07/19 01:39:08 by yel-kobi         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRC = *.c
RM = /bin/rm -f
OPTION = -c
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(OPTION) $(CFLAGS) $(SRC)
	ar rc $(NAME) *.o && ranlib $(NAME)

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all
