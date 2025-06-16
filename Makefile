# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/07 20:46:16 by ehossain          #+#    #+#              #
#    Updated: 2025/06/15 12:33:36 by ehossain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRC = ./src/main.c \
	./src/ft_putstr.c \
	./src/ft_philo.c
OBJ = ${SRC:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -pthread
INCLUDE = include
MAKE = make --no-print-directory

all: $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)philo compiled$(END)"

%.o : %.c
	@$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

clean :
	@rm -rf $(OBJ)
	@echo "$(RED)removed objcet files$(END)"

fclean : clean
	@rm -rf $(NAME)
	@echo "$(RED)removed philo$(END)"

re : fclean all

.PHONY : clean fclean re all

# Define color variables
RED    = \033[0;31m
GREEN  = \033[0;32m
END     = \033[0m
