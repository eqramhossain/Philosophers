/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_t_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 11:47:32 by ehossain          #+#    #+#             */
/*   Updated: 2025/09/21 11:41:05 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_t_data(t_data *data)
{
	int	i;

	i = 0;
	data->start_time = ft_get_current_time();
	data->simulation_end = false;
	pthread_mutex_init(&data->simulation_lock, NULL);
	pthread_mutex_init(&data->meal_lock, NULL);
	pthread_mutex_init(&data->write_lock, NULL);
	data->fork = ft_calloc(data->input.nb_philo, sizeof(pthread_mutex_t));
	if (!data->fork)
		return (ERROR);
	while (i != data->input.nb_philo)
	{
		pthread_mutex_init(&data->fork[i], NULL);
		i++;
	}
	return (SUCCESS);
}
