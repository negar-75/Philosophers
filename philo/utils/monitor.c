/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:01:52 by nnasiri           #+#    #+#             */
/*   Updated: 2024/09/24 14:33:41 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
/*
data.finished --> write_lock
*/
void	print_msg(char *str, t_philo *philo, int force) {
    size_t time;

    pthread_mutex_lock(&philo->data->write_lock);
    time = get_current_time() - philo->data->start_time;
    if (!philo->data->finished || force)
        printf("%zu\t %d %s\n", time, philo->id, str);
    pthread_mutex_unlock(&philo->data->write_lock);
}

int is_dead(t_rule *data) {
    int i = 0;

    while (i < data->num_of_philos) {
        pthread_mutex_lock(&data->meal_lock);
        if (get_current_time() - data->philos[i].last_meal >= data->time_to_die) {
            pthread_mutex_lock(&data->write_lock);
            data->finished = 1;
            print_msg("died", &(data->philos[i]), 1);
            pthread_mutex_unlock(&data->write_lock);
            pthread_mutex_unlock(&data->meal_lock);
            return 1;
        }
        pthread_mutex_unlock(&data->meal_lock);
        i++;
    }
    return 0;
}

/*
meals_eaten --> full_eaten
*/
int	if_all_eat(t_rule *data)
{
	int	i;

	i = -1;
	while (++i < data->num_of_philos)
	{
		pthread_mutex_lock(&data->full_eaten);
		if (!(data->philos[i].eaten_enough))
			return (pthread_mutex_unlock(&data->full_eaten), 0);
		pthread_mutex_unlock(&data->full_eaten);
	}
	return (1);
}

/*
data.finish --> write_lock
*/
void	*monitor(void *pointer)
{
	t_rule	*data;

	data = (t_rule *)pointer;
	while (1)
	{
		if (is_dead(data) == 1)
			break;
		if(data->num_times_to_eat != -1 && if_all_eat(data) == 1)
		{
			pthread_mutex_lock(&data->write_lock);
			data->finished = 1;
			pthread_mutex_unlock(&data->write_lock);
			break;
		}
	}
	return (pointer);
}
