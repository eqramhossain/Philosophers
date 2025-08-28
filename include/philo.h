/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 20:49:12 by ehossain          #+#    #+#             */
/*   Updated: 2025/08/28 20:00:35 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define ac_limit 5
# define ac_limit_op 6

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

// 1 sec is equal to 1000 milliseconde

typedef struct s_input
{
	int		nb_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int optional; // number_of_times_each_philosopher_must_eat

}			t_input;

typedef struct s_philo
{
	t_input	input;
}			t_philo;

/*  ====================  UTILS  ====================  */
void		ft_putchar(char c);
void		ft_putstr(char *str);
void		ft_putstr_error(char *str);
void		ft_putnbr(unsigned int nbr);
int			ft_atoi(char *str);

#endif
