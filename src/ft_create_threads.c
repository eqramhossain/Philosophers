/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_threads.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 11:54:42 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/17 17:30:59 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_create_threads(t_philo *philo, int nb_philo)
{
	int	i;

	i = 0;
	if (pthread_create(&philo->data->monitor, NULL, &ft_monitor,
			&philo[0]) != 0)
	{
		ft_destroy_mutex(philo->data);
		ft_error_exit("error_creating_monitor_thread");
	}
	while (i < nb_philo)
	{
		if (pthread_create(&philo[i].philo, NULL, &ft_routine, &philo[i]) != 0)
		{
			ft_destroy_mutex(philo->data);
			ft_error_exit("error_creating_philosophers_threads");
		}
		i++;
	}
	if (pthread_join(philo[0].data->monitor, NULL) != 0)
	{
		ft_destroy_mutex(philo->data);
		ft_error_exit("error_join_monitor_thread");
	}
	i = 0;
	while (i < nb_philo)
	{
		if (pthread_join(philo[i].philo, NULL) != 0)
		{
			ft_destroy_mutex(philo->data);
			ft_error_exit("error_join_philosophers_threads");
		}
		i++;
	}
}
