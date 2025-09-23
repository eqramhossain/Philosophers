/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_all_philo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 08:27:11 by ehossain          #+#    #+#             */
/*   Updated: 2025/09/23 09:40:17 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_init_philo(t_philo *philo);

void	ft_init_all_philo(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i != data->nb_philo)
	{
		philo[i].data = data;
		philo[i].id = i;
		ft_init_philo(&philo[i]);
		i++;
	}
}

static void	ft_init_philo(t_philo *philo)
{
	philo->start_time = ft_get_current_time();
	philo->meals_eaten = 0;
	philo->last_meal_time = ft_get_current_time();
	philo->eating = false;
	if (philo->id == 0)
		philo->r_fork = &philo->data->fork[philo->data->nb_philo];
	else
		philo->r_fork = &philo->data->fork[philo->id - 1];
	philo->l_fork = &philo->data->fork[philo->id];
}
