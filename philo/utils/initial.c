/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:02:00 by nnasiri           #+#    #+#             */
/*   Updated: 2024/09/24 14:07:38 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	clean_mutexes(t_rule *data)
{
	pthread_mutex_destroy(&data->write_lock);
	pthread_mutex_destroy(&data->full_eaten);
	pthread_mutex_destroy(&data->meal_lock);
}

void	clean_up_all(t_rule *data, int i)
{
	while (--i >= 0)
		pthread_mutex_destroy(&data->forks[i]);
	clean_mutexes(data);
}
//data.meal_lock --> last_meal
void	init_philos(t_rule *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].last_meal = get_current_time();
		data->philos[i].meals_eaten = 0;
		data->philos[i].eaten_enough = 0;
		data->philos[i].l_fork = i;
		data->philos[i].r_fork = (i + 1) % data->num_of_philos;
		data->philos[i].data = data;
		i++;
	}
}

void	init_forks(t_rule *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			ft_err("Error initialising mutex", 1);
		i++;
	}
}

void	init_program( char **argv ,t_rule *data)
{
	if (pthread_mutex_init(&data->write_lock, NULL) != 0
		|| pthread_mutex_init(&data->full_eaten, NULL) != 0
		|| pthread_mutex_init(&data->meal_lock, NULL) != 0)
	{
		ft_err("Error initializing mutex", 1);
	}
	data->num_of_philos = atoi(argv[1]);
	data->time_to_die = atoi(argv[2]);
	data->time_to_eat = atoi(argv[3]);
	data->time_to_sleep = atoi(argv[4]);
	data->finished = 0;
	if (argv[5])
		data->num_times_to_eat = atoi(argv[5]);
	else
		data->num_times_to_eat = -1;
	
}
