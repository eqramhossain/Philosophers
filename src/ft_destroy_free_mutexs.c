/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_free_mutexs.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:11:28 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/17 18:01:04 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_destroy_free_mutexs(t_data *data, t_philo *philo)
{
	ft_destroy_mutex(data);
	free(data->input);
	free(philo);
	free(data->fork);
}
