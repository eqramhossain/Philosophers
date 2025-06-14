# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/07 20:46:16 by ehossain          #+#    #+#              #
#    Updated: 2025/06/14 13:11:35 by ehossain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
MAIN = ./src/main.c
SRC = ./src/ft_putstr.c \

OBJ = ${SRC:.c=.o} 
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
INCLUDE = include
MAKE = make --no-print-directory

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -I$(INCLUDE) -o $(NAME) $(MAIN) $(OBJ)

$(OBJ) : $(SRC)
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean :
	$(MAKE) clean
	rm -rf $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY : clean fclean re
