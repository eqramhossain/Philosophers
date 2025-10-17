/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 20:49:12 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/17 18:18:34 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define SUCCESS 0
# define ERROR 1

# define EAT "is_eating"
# define SLEEP "is_sleeping"
# define THINK "is_thinking"
# define TAKE_FORK "has_taken_a_fork"

// 1 sec is equal to 1000 milliseconde

typedef struct s_input
{
	int				nb_philo;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	int				meals_required;
}					t_input;

typedef struct s_data
{
	time_t			start_time;
	t_input			*input;
	int				nb_philo;
	bool			simulation_end;
	pthread_mutex_t	simulation_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	*fork;
	pthread_t		monitor;
}					t_data;

typedef struct s_philo
{
	t_data			*data;
	time_t			start_time;
	int				id;
	pthread_t		philo;
	bool			eating;
	int				meals_eaten;
	time_t			last_meal_time;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}					t_philo;

/* ========================================================================== */
/*                                PHILO                                       */
/* ========================================================================== */

void				ft_init_t_input(t_input *input, int ac, char **av);
void				ft_print_t_input(t_input *input, int ac);
int					ft_init_t_data(t_data *data, int ac, char **av);

void				ft_init_all_philo(t_data *data, t_philo *philo);
void				ft_print_all_philo(t_philo *philo, int nb_philo);

void				*ft_monitor(void *data);

void				ft_destroy_mutex(t_data *data);
void				ft_destroy_free_mutexs(t_data *data, t_philo *philo);

void				ft_create_threads(t_philo *philo, int nb_philo);
bool				ft_if_all_philos_alive(t_philo *philo, int nb_philo);
bool				ft_all_ate_enough(t_philo *philo, int nb_philo);

void				*ft_routine(void *philo);
void				ft_eating(t_philo *philo);
void				ft_sleeping(t_philo *philo);
void				ft_thinking(t_philo *philo);
bool				ft_is_simulation_end(t_philo *data);

void				ft_print_message(const char *msg, t_philo *philo);

time_t				ft_get_current_time(void);
int					ft_usleep(time_t miliseconds);

/* ========================================================================== */
/*                                UTILS                                       */
/* ========================================================================== */

void				ft_putstr(char *str);
void				ft_error(char *str);
void				ft_error_exit(char *str);
void				ft_putnbr(unsigned int nbr);
void				*ft_calloc(size_t nmemb, size_t size);
int					ft_atoi(char *str);
long				ft_atol(char *str);
void				ft_free(void **content);

#endif
