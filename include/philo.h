/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 20:49:12 by ehossain          #+#    #+#             */
/*   Updated: 2025/08/12 13:39:27 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int	nb_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int optional; // number_of_times_each_philosopher_must_eat

}		t_philo;

/*  ====================  UTILS  ====================  */
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putstr_error(char *str);
void	ft_putnbr(unsigned int nbr);
int		ft_atoi(char *str);

#endif
