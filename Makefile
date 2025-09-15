# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/07 20:46:16 by ehossain          #+#    #+#              #
#    Updated: 2025/09/15 10:00:45 by ehossain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRC = ./src/main.c \
	./src/ft_philo.c \
	./src/utils/ft_putstr.c \
	./src/utils/ft_atol.c \
	./src/utils/ft_putstr_error.c \
	./src/utils/ft_putnbr.c \
	./src/utils/ft_even.c \

OBJ = ${SRC:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread -g3
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
