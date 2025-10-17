/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_t_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 11:47:32 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/17 18:18:37 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_t_data(t_data *data, int ac, char **av)
{
	int	i;

	i = 0;
	data->start_time = ft_get_current_time();
	data->input = ft_calloc(1, sizeof(t_input));
	if (!data->input)
		return (ERROR);
	ft_init_t_input(data->input, ac, av);
	data->nb_philo = data->input->nb_philo;
	data->simulation_end = false;
	pthread_mutex_init(&data->simulation_lock, NULL);
	pthread_mutex_init(&data->meal_lock, NULL);
	pthread_mutex_init(&data->write_lock, NULL);
	data->fork = ft_calloc(data->nb_philo, sizeof(pthread_mutex_t));
	if (!data->fork)
		return (ERROR);
	while (i < data->nb_philo)
	{
		pthread_mutex_init(&data->fork[i], NULL);
		i++;
	}
	return (SUCCESS);
}
