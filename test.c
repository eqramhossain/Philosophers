/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 10:31:42 by ehossain          #+#    #+#             */
/*   Updated: 2025/08/29 18:54:49 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>

void	*ft_hello(void *data)
{
	(void)data;
	printf("hello world\n");
	return (NULL);
}

int	main(int ac, char **av)
{
	struct timeval	current_time;
	pthread_t		thread;
	int				rtn;

	(void)ac;
	(void)av;
	gettimeofday(&current_time, NULL);
	printf("current_time.tv_sec = %ld\n", current_time.tv_sec);
	printf("current_time.tv_usec = %ld\n", current_time.tv_usec);
	rtn = pthread_create(&thread, NULL, &ft_hello, NULL);
	pthread_join(thread, NULL);
	printf("var = %d\n", rtn);
	return (1);
}
