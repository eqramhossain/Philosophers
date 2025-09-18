/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 04:44:59 by ehossain          #+#    #+#             */
/*   Updated: 2025/09/18 05:50:52 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_create_thread(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_init(&data->write_mutex, NULL);
	while (i != data->input->nb_philo)
	{
		pthread_create(&data->philo[i].thread, NULL, &ft_routine, (void *)data);
		i++;
	}
	i = 0;
	while (i != data->input->nb_philo)
	{
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}
	pthread_mutex_destroy(&data->write_mutex);
}

void	*ft_routine(void *data)
{
	t_data		*tmp_data;
	static int	i = 0;

	tmp_data = (t_data *)data;
	pthread_mutex_lock(&tmp_data->write_mutex);
	tmp_data->philo->id = i;
	printf("hello from thread %d\n", tmp_data->philo->id);
	i++;
	pthread_mutex_unlock(&tmp_data->write_mutex);
	return (NULL);
}
