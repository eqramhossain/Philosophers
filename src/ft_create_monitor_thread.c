/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_monitor_thread.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 11:54:42 by ehossain          #+#    #+#             */
/*   Updated: 2025/09/22 12:00:58 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_create_monitor_thread(t_philo *philo)
{
	if (pthread_create(&philo->data->monitor, NULL, &ft_monitor,
			(void *)philo) != 0)
	{
		ft_destroy_free_mutexs(philo->data);
		exit(EXIT_FAILURE);
	}
	if (pthread_join(philo->data->monitor, NULL) != 0)
	{
		ft_destroy_free_mutexs(philo->data);
		exit(EXIT_FAILURE);
	}
}
