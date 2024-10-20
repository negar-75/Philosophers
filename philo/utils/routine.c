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
	print_msg("is thinking", philo, 0);
}

void	dream(t_philo *philo)
{
	print_msg("is sleeping", philo, 0);
	ft_sleep(philo->data->time_to_sleep);
}
void	meals_eaten_util(t_philo *philo)
{
	philo->meals_eaten += 1;
	pthread_mutex_lock(&philo->data->full_eaten);
	if (!philo->eaten_enough
		&& (philo->meals_eaten == philo->data->num_times_to_eat))
		philo->eaten_enough = 1;
	pthread_mutex_unlock(&philo->data->full_eaten);
}
int	eat(t_philo *philo)
{
	// Lock the left fork
	if (philo->id % 2 == 1)
		pthread_mutex_lock(&(philo->data->forks[philo->l_fork]));
	else
		pthread_mutex_lock(&(philo->data->forks[philo->r_fork]));
	
	print_msg("has taken a fork 🍴", philo, 0);

	// If only one philosopher, unlock and return
	if (philo->data->num_of_philos == 1)
	{
		pthread_mutex_unlock(&(philo->data->forks[philo->l_fork]));
		return 1;
	}

	// Lock the right fork
	if (philo->id % 2 == 1)
		pthread_mutex_lock(&(philo->data->forks[philo->r_fork]));
	else
		pthread_mutex_lock(&(philo->data->forks[philo->l_fork]));
	
	print_msg("has taken a fork 🍴", philo, 0);

	// Update the last meal time
	pthread_mutex_lock(&philo->data->meal_lock);
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(&philo->data->meal_lock);
	
	print_msg("is eating 🍝", philo, 0);
	ft_sleep(philo->data->time_to_eat);
	meals_eaten_util(philo);
	
	// Unlock the forks after eating
	pthread_mutex_unlock(&(philo->data->forks[philo->r_fork]));
	pthread_mutex_unlock(&(philo->data->forks[philo->l_fork]));

	print_msg("is sleeping 💤", philo, 0);
	ft_sleep(philo->data->time_to_sleep);
	print_msg("is thinking 💡", philo, 0);
	return 0;
}



void	*routine(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	if (philo->id % 2 == 0)
	{
		printf("philo%d is waiting", philo->id);
		ft_sleep(philo->data->time_to_eat);
	}
	while (1)
	{
		if (eat(philo))
		{
			pthread_mutex_lock(&philo->data->write_lock);
			philo->data->finished = 1;
			return (pthread_mutex_unlock(&philo->data->write_lock), NULL);
		}
		pthread_mutex_lock(&philo->data->write_lock);
		if (philo->data->finished == 1)
			return (pthread_mutex_unlock(&philo->data->write_lock), NULL);
		if ( philo->data->num_of_philos % 2 == 1)
			ft_sleep((philo->data->time_to_eat * 2) - philo->data->time_to_sleep);
	}
	return (NULL);
}
