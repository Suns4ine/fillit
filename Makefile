#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cshawnee <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/12 19:49:54 by cshawnee          #+#    #+#              #
#    Updated: 2019/11/15 16:31:41 by cshawnee         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

FLAGS = -Wall -Wextra -Werror -o

NAME = fillit

INC = ./libft/libft.a

SRC = stuff.c checker.c mp.c validator.c answer.c first.c solution.c

OBJ = stuff.o checker.o mp.o validator.o answer.o first.o solution.o

all: $(NAME)

$(NAME):
		make -C ./libft
		gcc $(FLAGS) $(NAME) $(SRC) $(INC)

clean:
	/bin/rm -rf $(OBJ)
	make -C ./libft fclean

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
