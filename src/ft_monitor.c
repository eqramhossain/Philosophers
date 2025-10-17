/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 12:26:50 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/17 18:02:53 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	ft_philo_alive(t_philo *philo);

void	*ft_monitor(void *data)
{
	t_philo	*tmp;

	tmp = (t_philo *)data;
	while (1)
	{
		if (ft_if_all_philos_alive(tmp, tmp->data->nb_philo) == false
			|| ft_all_ate_enough(tmp, tmp->data->nb_philo) == true)
			break ;
	}
	return (NULL);
}

bool	ft_if_all_philos_alive(t_philo *philo, int nb_philo)
{
	int	i;

	i = 0;
	while (i < nb_philo)
	{
		if (ft_philo_alive(&philo[i]) == false)
		{
			ft_print_message("died", &philo[i]);
			pthread_mutex_lock(&philo[i].data->simulation_lock);
			philo[i].data->simulation_end = true;
			pthread_mutex_unlock(&philo[i].data->simulation_lock);
			return (false);
		}
		i++;
	}
	return (true);
}

static bool	ft_philo_alive(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->meal_lock);
	if (ft_get_current_time()
		- philo->last_meal_time >= philo->data->input->time_to_die
		&& philo->eating == false)
	{
		pthread_mutex_unlock(&philo->data->meal_lock);
		return (false);
	}
	pthread_mutex_unlock(&philo->data->meal_lock);
	return (true);
}

bool	ft_all_ate_enough(t_philo *philo, int nb_philo)
{
	int	i;
	int	meal_count;

	if (philo->data->input->meals_required == -1)
		return (false);
	i = 0;
	meal_count = 0;
	while (i < nb_philo)
	{
		pthread_mutex_lock(&philo[i].data->meal_lock);
		if (philo[i].meals_eaten >= philo[i].data->input->meals_required)
			meal_count++;
		pthread_mutex_unlock(&philo[i].data->meal_lock);
		i++;
	}
	if (meal_count == nb_philo)
	{
		pthread_mutex_lock(&philo->data->simulation_lock);
		philo->data->simulation_end = true;
		pthread_mutex_unlock(&philo->data->simulation_lock);
		return (true);
	}
	return (false);
}
