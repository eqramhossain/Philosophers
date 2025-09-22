/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_simulation_end.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 12:14:04 by ehossain          #+#    #+#             */
/*   Updated: 2025/09/22 12:06:08 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
