/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 20:49:12 by ehossain          #+#    #+#             */
/*   Updated: 2025/09/17 12:11:00 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define return_success 0
# define return_error 1

// 1 sec is equal to 1000 milliseconde

typedef struct s_input
{
	int nb_philo;         // The number of philosophers
	time_t time_to_die;   // The time a philosopher will die if does not eat
	time_t time_to_eat;   // The time it takes to eat
	time_t time_to_sleep; // The time it takes to sleep
	time_t optional;      // number_of_times_each_philosopher_must_eat
}					t_input;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	int				meals_eaten;
	int				num_meals_to_eat;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}					t_philo;

typedef struct s_forks
{
	int				id_fork;
	pthread_mutex_t	*forks;
}					t_forks;

typedef struct s_data
{
	size_t			start_time;
	t_input			*input;
	t_philo			*philos;
	t_forks			*forks;
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_mutex;
}					t_data;

/* ========================================================================== */
/*                                PHILO                                       */
/* ========================================================================== */

void				ft_philo(t_data *data);
void				*ft_algorithm(void *philo);

/* ========================================================================== */
/*                                UTILS                                       */
/* ========================================================================== */

void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putstr_error(char *str);
void				ft_putnbr(unsigned int nbr);
void				*ft_calloc(size_t nmemb, size_t size);
int					ft_atoi(char *str);
long				ft_atol(char *str);
size_t				ft_get_current_time(void);
int					ft_usleep(size_t miliseconds);

#endif
