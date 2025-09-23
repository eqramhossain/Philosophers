/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_threads.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 11:54:42 by ehossain          #+#    #+#             */
/*   Updated: 2025/09/23 10:00:19 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_create_threads(t_philo *philo, int nb_philo)
{
	int	i;

	i = 0;
	if (pthread_create(&philo->data->monitor, NULL, &ft_monitor,
			(void *)philo) != 0)
	{
		ft_destroy_free_mutexs(philo->data);
		exit(EXIT_FAILURE);
	}
	while (i != nb_philo)
	{
		if (pthread_create(&philo[i].philo, NULL, &ft_routine,
				(void *)&philo[i]) != 0)
		{
			ft_destroy_free_mutexs(philo->data);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	if (pthread_join(philo->data->monitor, NULL) != 0)
	{
		ft_destroy_free_mutexs(philo->data);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i != nb_philo)
	{
		if (pthread_join(philo[i].philo, NULL) != 0)
		{
			ft_destroy_free_mutexs(philo->data);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
