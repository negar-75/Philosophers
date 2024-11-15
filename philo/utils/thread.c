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

