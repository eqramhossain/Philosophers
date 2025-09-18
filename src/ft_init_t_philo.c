/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_t_philo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 12:38:52 by ehossain          #+#    #+#             */
/*   Updated: 2025/09/18 13:22:34 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_t_philo(t_philo *philo, t_data *data)
{
	int	id;

	id = 0;
	while (id != data->input.nb_philo)
	{
		philo->id = id;
		pthread_create(philo->thread, NULL, &ft_routine, NULL);
		id++;
	}
}
