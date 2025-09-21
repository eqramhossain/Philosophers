/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 12:26:50 by ehossain          #+#    #+#             */
/*   Updated: 2025/09/21 11:33:16 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_monitor(void *data)
{
	t_philo	*tmp;

	tmp = (t_philo *)data;
	while (1)
	{
		if (ft_is_simulation_end(tmp) == true || ft_all_ate_enough(tmp) == true)
			break ;
	}
	return (NULL);
}
