/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_all_philo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 08:27:11 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/17 20:09:21 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_init_philo(t_philo *philo, t_data *data, int id);

void	ft_init_all_philo(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		ft_init_philo(&philo[i], data, i + 1);
		i++;
	}
}

static void	ft_init_philo(t_philo *philo, t_data *data, int id)
{
	int	n;

	int i; // 0 based index
	philo->data = data;
	philo->id = id;
	philo->start_time = ft_get_current_time();
	philo->meals_eaten = 0;
	philo->last_meal_time = ft_get_current_time();
	philo->eating = false;
	n = philo->data->nb_philo;
	i = philo->id - 1;
	// Left fork is "this seat", right fork is the next seat around the table
	philo->l_fork = &philo->data->fork[i];           // [0..n-1]
	philo->r_fork = &philo->data->fork[(i + 1) % n]; // wrap with modulo
}
