/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_message.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 19:24:46 by ehossain          #+#    #+#             */
/*   Updated: 2025/09/23 09:53:57 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_message(const char *msg, t_philo *philo)
{
	time_t	timestamp;

	timestamp = 0;
	pthread_mutex_lock(&philo->data->write_lock);
	timestamp = ft_get_current_time() - philo->last_meal_time;
	if (ft_is_simulation_end(philo) != true)
		printf("%ld %d %s\n", timestamp, philo->id, msg);
	pthread_mutex_unlock(&philo->data->write_lock);
}
