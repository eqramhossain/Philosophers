/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 20:49:12 by ehossain          #+#    #+#             */
/*   Updated: 2025/09/18 12:40:24 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define return_success 0
# define return_error 1

# define EAT "is_eating"
# define SLEEP "is_sleeping"
# define THINK "is_thinking"
# define TAKE_FORK "has_taken_a_fork"

// 1 sec is equal to 1000 milliseconde

typedef struct s_input
{
	int nb_philo;         // The number of philosophers
	time_t time_to_die;   // The time a philosopher will die if does not eat
	time_t time_to_eat;   // The time it takes to eat
	time_t time_to_sleep; // The time it takes to sleep
	int meals_required;   // number_of_times_each_philosopher_must_eat
}			t_input;

typedef struct s_data
{
	time_t start_time;   // the time when the program started
	t_input input;       // all the input variable
	bool simulation_end; // flag to indicate simulation end
	// (in case of death or all philosophers ate enough meals_required times)
	pthread_mutex_t simulation_lock; // mutex to protect simulation_end flag
	pthread_mutex_t meal_lock;       // mutex to protect meal counting
	pthread_mutex_t write_lock;      // mutex to protect console output
	pthread_mutex_t *forks;          // array of mutex for all forks
	pthread_t monitor;               // thread for death monitor
}			t_data;

typedef struct s_philo
{
	int id;                  // philosopher number (1 to nb_philo)
	pthread_t thread;        // thread for this philosopher
	int meals_eaten;         // how many times philosopher had eaten
	int num_meals_to_eat;    // how many meals have to eat
	time_t last_meal_time;   // timestamp of last meal start
	pthread_mutex_t *r_fork; // pointer to his right fork
	pthread_mutex_t *l_fork; // pointer to his left fork
	t_data	*data;
}			t_philo;

/* ========================================================================== */
/*                                PHILO                                       */
/* ========================================================================== */

void		ft_philo(t_data *data);

// Parse command line arguments and initialize input struct
void		ft_init_t_input(t_input *input, int ac, char **av);

// prints all variable inside *input
void		ft_print_t_input(t_input *input, int ac);

// Initialize data structure (mutexes, start time, etc.)
int			ft_init_t_data(t_data *data);

// Initialize philosophers and their attributes
int			ft_init_t_philo(t_philo *philo, t_data *data);

// Initialize forks (mutexes)
int			init_forks(t_data *data);

// monitior all the philosophers in case of death end the program
void		*ft_monitor(void *data);

/* ========================================================================== */
/*                                UTILS                                       */
/* ========================================================================== */

void		ft_putchar(char c);
void		ft_putstr(char *str);
void		ft_putstr_error(char *str);
void		ft_putnbr(unsigned int nbr);
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_atoi(char *str);
long		ft_atol(char *str);
time_t		ft_get_current_time(void);
int			ft_usleep(time_t miliseconds);

#endif
