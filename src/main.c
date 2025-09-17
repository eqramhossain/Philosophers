/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 20:50:08 by ehossain          #+#    #+#             */
/*   Updated: 2025/09/17 09:55:05 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_init_t_input(t_input *input, int ac, char **av);
static void	ft_print_t_input(t_input *input, int ac);

int	main(int ac, char *av[])
{
	t_input	input;
	t_data	data;

	if (ac == 5 || ac == 6)
	{
		ft_init_t_input(&input, ac, av);
		ft_print_t_input(&input, ac);
	}
	else
		return (return_error);
	data.input = &input;
	ft_philo(&data);
	return (return_success);
}

/**
 * @brief
 * this function store all the input from main in t_input variable
 * in case of an error the program end without an error message
 * @param input
 * @param ac
 * @param av
 */
static void	ft_init_t_input(t_input *input, int ac, char **av)
{
	input->nb_philo = ft_atoi(av[1]);
	if (input->nb_philo < 1)
		exit(1);
	input->time_to_die = ft_atol(av[2]);
	if (input->time_to_die <= 0)
		exit(1);
	input->time_to_eat = ft_atol(av[3]);
	if (input->time_to_eat <= 0)
		exit(1);
	input->time_to_sleep = ft_atol(av[4]);
	if (input->time_to_sleep <= 0)
		exit(1);
	if (ac == 6)
	{
		input->optional = ft_atol(av[5]);
		if (input->optional <= 0)
			exit(1);
	}
	else
	{
		(void)input->optional;
	}
}

/**
 * @brief this funtion print the t_input variable
 * @param input
 * @param ac
 */
static void	ft_print_t_input(t_input *input, int ac)
{
	printf("nb_philo = %d\n", input->nb_philo);
	printf("time_to_die = %ld\n", input->time_to_die);
	printf("time_to_eat = %ld\n", input->time_to_eat);
	printf("time_to_sleep = %ld\n", input->time_to_sleep);
	if (ac == 6)
		printf("optional = %ld\n", input->optional);
}
