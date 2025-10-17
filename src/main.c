/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 20:50:08 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/17 18:40:40 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char *av[])
{
	t_data	data;
	t_philo	*philo;

	if (ac == 5 || ac == 6)
	{
		if (ft_init_t_data(&data, ac, av) == ERROR)
		{
			ft_destroy_mutex(&data);
			free(data.input);
			free(data.fork);
			return (ERROR);
		}
	}
	else
		return (ERROR);
	philo = ft_calloc(data.nb_philo, sizeof(t_philo));
	if (!philo)
	{
		ft_destroy_mutex(&data);
		exit(EXIT_FAILURE);
	}
	ft_init_all_philo(&data, philo);
	ft_create_threads(philo, data.nb_philo);
	ft_destroy_free_mutexs(&data, philo);
	return (SUCCESS);
}
