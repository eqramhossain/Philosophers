/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:53:25 by ehossain          #+#    #+#             */
/*   Updated: 2025/09/23 10:03:02 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	// if ((philo->data->nb_philo % 2) == 0)
	// 	ft_usleep(5);
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
	pthread_mutex_lock(philo->r_fork);
	ft_print_message("has_taken_a_fork", philo);
	pthread_mutex_lock(philo->l_fork);
	ft_print_message("has_taken_a_fork", philo);
	philo->eating = 1;
	ft_print_message("is_eating", philo);
	pthread_mutex_lock(&philo->data->meal_lock);
	philo->last_meal_time = ft_get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->data->meal_lock);
	ft_usleep(philo->data->input.time_to_sleep);
	philo->eating = 0;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	ft_sleeping(t_philo *philo)
{
	ft_print_message("is_sleeping", philo);
	ft_usleep(philo->data->input.time_to_sleep);
}

void	ft_thinking(t_philo *philo)
{
	ft_print_message("is_thinking", philo);
}
