/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 08:27:11 by ehossain          #+#    #+#             */
/*   Updated: 2025/09/15 04:17:50 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_t_philo_init(t_philo *philo, t_input *input);
static void	ft_create_thread(t_philo *philo);

void	ft_philo(t_input *input)
{
	t_philo	philo;

	ft_t_philo_init(&philo, input);
	ft_create_thread(&philo);
	return ;
}

static void	ft_t_philo_init(t_philo *philo, t_input *input)
{
	philo->input = input;
	philo->threads = ft_calloc(philo->input->nb_philo, sizeof(pthread_t));
	if (!philo->threads)
	{
		ft_putstr_error("Malloc Failed");
		exit(1);
	}
}

static void	ft_create_thread(t_philo *philo)
{
	int	i;

	i = 0;
	while (i != philo->input->nb_philo)
	{
	}
}
