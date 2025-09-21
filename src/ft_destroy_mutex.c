/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_mutex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 14:56:54 by ehossain          #+#    #+#             */
/*   Updated: 2025/09/20 15:09:45 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_destroy_mutex(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&data->simulation_lock);
	pthread_mutex_destroy(&data->meal_lock);
	pthread_mutex_destroy(&data->write_lock);
	while (i != data->input.nb_philo)
	{
		pthread_mutex_destroy(&data->fork[i]);
		i++;
	}
}
