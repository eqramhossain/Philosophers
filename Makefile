# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/07 20:46:16 by ehossain          #+#    #+#              #
#    Updated: 2025/09/22 11:35:22 by ehossain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRC = ./src/ft_destroy_free_mutexs.c \
	  ./src/ft_destroy_mutex.c \
	  ./src/ft_get_curr_time.c \
	  ./src/ft_init_all_philo.c \
	  ./src/ft_print_all_philo.c \
	  ./src/ft_init_t_data.c \
	  ./src/ft_init_t_input.c \
	  ./src/ft_monitor.c \
	  ./src/ft_routine.c \
	  ./src/ft_usleep.c \
	  ./src/main.c \
	  ./src/ft_create_monitor_thread.c \
	  ./src/ft_create_philos_threads.c \
	  ./src/utils/ft_atoi.c \
	  ./src/utils/ft_atol.c \
	  ./src/utils/ft_calloc.c \
	  ./src/utils/ft_error.c \
	  ./src/utils/ft_error_exit.c \
	  ./src/utils/ft_free.c \

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
