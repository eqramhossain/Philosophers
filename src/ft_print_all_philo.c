/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_all_philo.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 11:20:47 by ehossain          #+#    #+#             */
/*   Updated: 2025/09/22 11:29:29 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_print_philo(t_philo *philo);

void	ft_print_all_philo(t_philo *philo, int nb_philo)
{
	int	i;

	i = 0;
	while (i != nb_philo)
	{
		ft_print_philo(&philo[i]);
		i++;
	}
	exit(EXIT_FAILURE);
}

static void	ft_print_philo(t_philo *philo)
{
	printf("philo->id = %d\n", philo->id);
	printf("	philo->start_time = %ld\n", philo->start_time);
	printf("	philo->meals_eaten = %d\n", philo->meals_eaten);
	printf("	philo->last_meal_time = %ld\n", philo->last_meal_time);
}
