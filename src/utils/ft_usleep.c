/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 04:31:40 by ehossain          #+#    #+#             */
/*   Updated: 2025/09/17 07:25:13 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_get_current_time(void);

int	ft_usleep(size_t miliseconds)
{
	size_t	start_time;

	start_time = ft_get_current_time();
	if (start_time == 1)
		return (return_error);
	while (ft_get_current_time() - start_time < miliseconds)
	{
		if (usleep(500) == -1)
		{
			ft_putstr_error("usleep error\n");
			return (return_error);
		}
	}
	return (return_success);
}

size_t	ft_get_current_time(void)
{
	struct timeval	s_time;
	size_t			curr_time;

	if (gettimeofday(&s_time, NULL) == -1)
	{
		ft_putstr_error("gettimeofday error\n");
		return (return_error);
	}
	curr_time = ((s_time.tv_sec * 1000) + (s_time.tv_usec / 1000));
	return (curr_time);
}
