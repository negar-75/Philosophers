/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:01:44 by nnasiri           #+#    #+#             */
/*   Updated: 2024/09/24 15:15:03 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	think(t_philo *philo)
{
	print_msg("is thinking", philo, philo->id);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_msg("has taken a left fork", philo, philo->id);
	if (philo->data->num_of_philos == 1)
	{
		ft_sleep(philo->data->time_to_die);
		pthread_mutex_unlock(philo->l_fork);
		return ;
	}
	pthread_mutex_lock(philo->r_fork);
	print_msg("has taken a right fork", philo, philo->id);
	philo->eating = 1;
	print_msg("is eating", philo, philo->id);
	 (philo->meal_lock);
	philo->meals_eaten++;
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(philo->meal_lock);
	ft_sleep(philo->data->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	dream(t_philo *philo)
{
	print_msg("is sleeping", philo, philo->id);
	ft_sleep(philo->data->time_to_sleep);
}

void	*routine(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	if (philo->id % 2 == 0)
		ft_sleep(1);
	while (!search_for_dead(philo))
	{
		eat(philo);
		dream(philo);
		think(philo);
	}
	return (pointer);
}
