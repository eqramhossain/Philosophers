/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_curr_time.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 12:16:57 by ehossain          #+#    #+#             */
/*   Updated: 2025/09/18 12:18:12 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	ft_get_current_time(void)
{
	struct timeval	s_time;
	time_t			curr_time;

	if (gettimeofday(&s_time, NULL) == -1)
	{
		ft_putstr_error("gettimeofday error\n");
		return (return_error);
	}
	curr_time = ((s_time.tv_sec * 1000) + (s_time.tv_usec / 1000));
	return (curr_time);
}
