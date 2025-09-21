/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 07:33:50 by ehossain          #+#    #+#             */
/*   Updated: 2025/09/20 12:19:34 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int		i;
	long	result;
	int		signe;

	i = 0;
	result = 0;
	signe = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			ft_error_exit("Error: negative number are forbidden\n");
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		if (result * 10 + (str[i] - '0') >= INT_MAX)
			ft_error_exit("Error: integer value exceed the INT_MAX\n");
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * signe);
}
