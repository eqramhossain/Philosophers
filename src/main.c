/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 20:50:08 by ehossain          #+#    #+#             */
/*   Updated: 2025/09/18 12:43:48 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char *av[])
{
	t_input	input;
	t_data	data;
	t_philo	*philo;

	if (ac == 5 || ac == 6)
	{
		ft_init_t_input(&input, ac, av);
		ft_print_t_input(&input, ac);
	}
	else
		return (return_error);
	data.input = input;
	ft_init_t_data(&data);
	philo = ft_calloc(data.input.nb_philo, sizeof(t_philo));
	ft_init_t_philo(philo, &data);
	return (return_success);
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
