/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:02:16 by nnasiri           #+#    #+#             */
/*   Updated: 2024/09/24 14:07:03 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_sleep(size_t milisec)
{
	size_t	start;

	start = get_current_time();
	while (get_current_time() - start < milisec)
		usleep(500);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		ft_err("gettimeofday() error\n", 1);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	destroy_program(char *str, t_rule *data, int err)
{
	int	i;

	i = 0;
	if (str)
		ft_putstr_fd(str, 2);
	pthread_mutex_destroy(&data->write_lock);
	pthread_mutex_destroy(&data->meal_lock);
	pthread_mutex_destroy(&data->write_lock);
	while (i < data->num_of_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	if (err)
		exit(1);
}
