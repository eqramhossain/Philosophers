/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_t_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 11:46:59 by ehossain          #+#    #+#             */
/*   Updated: 2025/09/20 12:17:26 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief
 * this function store all the input from main in t_input variable
 * in case of an error the program end without an error message
 * @param input
 * @param ac
 * @param av
 */
void	ft_init_t_input(t_input *input, int ac, char **av)
{
	input->nb_philo = ft_atoi(av[1]);
	input->time_to_die = ft_atol(av[2]);
	input->time_to_eat = ft_atol(av[3]);
	input->time_to_sleep = ft_atol(av[4]);
	if (ac == 6)
		input->meals_required = ft_atol(av[5]);
	else
		input->meals_required = -1;
}
