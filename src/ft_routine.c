/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:53:25 by ehossain          #+#    #+#             */
/*   Updated: 2025/09/22 20:35:05 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (ft_is_simulation_end(philo) != true)
	{
		ft_eating(philo);
		ft_sleeping(philo);
		ft_thinking(philo);
	}
	return (NULL);
}

bool	ft_is_simulation_end(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->simulation_lock);
	if (philo->data->simulation_end == true)
	{
		pthread_mutex_unlock(&philo->data->simulation_lock);
		return (true);
	}
	pthread_mutex_unlock(&philo->data->simulation_lock);
	return (false);
}

void	ft_eating(t_philo *philo)
{
	ft_print_message("eating", philo);
}

void	ft_sleeping(t_philo *philo)
{
	ft_print_message("sleeping", philo);
	ft_usleep(philo->data->input.time_to_sleep);
}

void	ft_thinking(t_philo *philo)
{
	ft_print_message("thinking", philo);
}
