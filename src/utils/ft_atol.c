/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 23:14:46 by ehossain          #+#    #+#             */
/*   Updated: 2025/09/20 12:20:00 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atol(char *str)
{
	int		i;
	size_t	nbr;
	int		signe;

	i = 0;
	nbr = 0;
	signe = 1;
	if (!str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			ft_error_exit("negative number are forbidden");
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if ((nbr * 10 + (str[i] - '0')) >= LONG_MAX)
			ft_error_exit("Error: integer value exceed the LONG_MAX\n");
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	nbr = nbr * signe;
	return ((long)nbr);
}
