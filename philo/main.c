/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:00:17 by nnasiri           #+#    #+#             */
/*   Updated: 2024/09/24 14:06:04 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	main(int argc, char **argv)
{
	t_rule			data;

	if (argc != 5 && argc != 6)
		ft_err("WRONG NUMBER OF ARGS", 1);
	check_args(argv);
	init_program(argv, &data);
	data.start_time = get_current_time();
	init_forks(&data);
	init_philos(&data);
	printf("Write lock mutex address: %p\n", (void *)&data.write_lock);
    printf("Full eaten mutex address: %p\n", (void *)&data.full_eaten);
    printf("Meal lock mutex address: %p\n", (void *)&data.meal_lock);

    for (int i = 0; i < data.num_of_philos; i++)
    {
        printf("Fork %d mutex address: %p\n", i, (void *)&data.forks[i]);
    }
	for (int i = 0; i < data.num_of_philos; i++)
    {
        printf("Philosopher %d\n", data.philos[i].id);
        printf(" Left fork: %d\n", data.philos[i].l_fork);
        printf(" Right fork: %d\n", data.philos[i].r_fork);
        printf(" Last meal: %zu\n", data.philos[i].last_meal);
        printf(" Meals eaten: %d\n", data.philos[i].meals_eaten);
    }
	run_philos(&data);
	threads_join(&data);
	destroy_program(NULL, &data, 0);
	return (0);
}
