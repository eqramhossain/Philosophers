/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 20:50:08 by ehossain          #+#    #+#             */
/*   Updated: 2025/09/21 11:44:36 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char *av[])
{
	t_data	data;
	t_philo	*philo;

	if (ac == 5 || ac == 6)
	{
		ft_init_t_input(&data.input, ac, av);
		ft_print_t_input(&data.input, ac);
	}
	else
		return (ERROR);
	if (ft_init_t_data(&data) != SUCCESS)
		return (ERROR);
	data.nb_philo = data.input.nb_philo;
	philo = malloc((sizeof(t_philo) * data.input.nb_philo));
	if (!philo)
	{
		ft_destroy_free_mutexs(&data);
		exit(EXIT_FAILURE);
	}
	ft_init_all_philo(&data, philo);
	ft_create_monitor_thread(&data);
	ft_create_philo_thread(philo);
	ft_destroy_free_mutexs(&data);
	return (SUCCESS);
}

/**
 * @brief this funtion print the t_input variable
 * @param input
 * @param ac
 */
void	ft_print_t_input(t_input *input, int ac)
{
	printf("nb_philo = %d\n", input->nb_philo);
	printf("time_to_die = %ld\n", input->time_to_die);
	printf("time_to_eat = %ld\n", input->time_to_eat);
	printf("time_to_sleep = %ld\n", input->time_to_sleep);
	if (ac == 6)
		printf("meals_required = %d\n", input->meals_required);
}
