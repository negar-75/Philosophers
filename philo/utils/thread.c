/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:01:33 by nnasiri           #+#    #+#             */
/*   Updated: 2024/09/24 14:01:36 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	run_philos(t_rule *data)
{
	int	i;

	pthread_create(&data->observer, NULL, monitor, (void *)data);
	i = -1;
	while (++i < data->num_of_philos)
	{
		pthread_create(&data->philos[i].thread, NULL, routine,
			(void *)&data->philos[i]);
	}
}
int	threads_join(t_rule *data)
{
	int	i;

	i = -1;
	while (++i < data->num_of_philos)
		if (pthread_join(data->philos[i].thread, NULL) != 0)
			return (write(2, "pthread_join error\n", 19), 1);
	if (pthread_join(data->observer, NULL) != 0)
		return (write(2, "pthread_join error\n", 19), 1);
	return (0);
}
// void	thread_creation(t_rule *data)
// {
// 	int			i;

// 	i = 0;
// 	if (pthread_create(&data->observer, NULL, monitor, (void *)data) != 0)
// 		destroy_program("Thread creation error", data, 1);
// 	while (i < data->num_of_philos)
// 	{
// 		if (pthread_create(&data->philos[i].thread, NULL, &routine,
// 				(void *)&data->philos[i]) != 0)
// 			destroy_program("Thread creation error", data, 1);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < data->num_of_philos)
// 	{
// 		if (pthread_join(data->philos[i].thread, NULL) != 0)
// 			destroy_program("Thread join error", data, 1);
// 		i++;
// 	}
// 	if (pthread_join(data->observer, NULL) != 0)
// 		destroy_program("Observer thread join error", data, 1);
// }
