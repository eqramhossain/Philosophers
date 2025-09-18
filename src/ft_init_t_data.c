/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_t_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 11:47:32 by ehossain          #+#    #+#             */
/*   Updated: 2025/09/18 12:35:02 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_t_data(t_data *data)
{
	int	fork_id;

	fork_id = 0;
	data->start_time = ft_get_current_time();
	data->simulation_end = false;
	pthread_mutex_init(&data->simulation_lock, NULL);
	pthread_mutex_init(&data->meal_lock, NULL);
	pthread_mutex_init(&data->write_lock, NULL);
	data->forks = ft_calloc(data->input.nb_philo, sizeof(pthread_mutex_t));
	while (fork_id != data->input.nb_philo)
	{
		pthread_mutex_init(&data->forks[fork_id], NULL);
		fork_id++;
	}
	pthread_create(&data->monitor, NULL, &ft_monitor, (void *)data);
	pthread_detach(data->monitor);
	return (return_success);
}
