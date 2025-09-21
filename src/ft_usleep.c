/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 04:31:40 by ehossain          #+#    #+#             */
/*   Updated: 2025/09/20 15:20:49 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_usleep(time_t miliseconds)
{
	time_t	start_time;

	start_time = ft_get_current_time();
	if (start_time == 1)
		return (ERROR);
	while ((ft_get_current_time() - start_time) < miliseconds)
	{
		if (usleep(500) == -1)
		{
			ft_error("usleep error\n");
			return (ERROR);
		}
	}
	return (SUCCESS);
}
