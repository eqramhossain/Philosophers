/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 20:50:08 by ehossain          #+#    #+#             */
/*   Updated: 2025/08/12 14:30:06 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_t_philo_init(char **av, t_philo *philo, int option);

int	main(int ac, char *av[])
{
	t_philo	philo;

	if (ac < 5 || ac > 6)
		return (1);
	if (ac == 5)
		ft_t_philo_init(av, &philo, 0);
	if (ac == 6)
		ft_t_philo_init(av, &philo, 1);
	return (0);
}

static void	ft_t_philo_init(char **av, t_philo *philo, int option)
{
	if (option == 1)
	{
	}
	else
	{
	}
}
