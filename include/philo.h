/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 20:49:12 by ehossain          #+#    #+#             */
/*   Updated: 2025/09/15 07:55:02 by ehossain         ###   ########.fr       */
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

// 1 sec is equal to 1000 milliseconde

typedef struct s_input
{
	time_t	nb_philo;
	time_t	time_to_die;
	time_t	time_to_eat;
	time_t	time_to_sleep;
	time_t	optional;
	// number_of_times_each_philosopher_must_eat

}			t_input;

typedef struct s_philo
{
	t_input	*input;
	pthread_t *threads;    // array of threads/philosophers
	pthread_mutex_t mutex; //
}			t_philo;

/* ========================================================================== */
/*                                PHILO                                       */
/* ========================================================================== */

void		ft_philo(t_input *input);
void		*ft_algorithm(void *philo);

/* ========================================================================== */
/*                                UTILS                                       */
/* ========================================================================== */

void		ft_putchar(char c);
void		ft_putstr(char *str);
void		ft_putstr_error(char *str);
void		ft_putnbr(unsigned int nbr);
void		*ft_calloc(size_t nmemb, size_t size);
long		ft_atol(char *str);

#endif
