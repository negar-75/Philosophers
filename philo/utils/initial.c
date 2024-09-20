#include "../philo.h"

void clean_mutexes(t_rule *data)
{
    pthread_mutex_destroy(&data->write_lock);
    pthread_mutex_destroy(&data->dead_lock);
    pthread_mutex_destroy(&data->meal_lock);
}
void clean_up_all(t_rule *data, int i)
{
    while( --i >= 0)
        pthread_mutex_destroy(&data->forks[i]);
    clean_mutexes(data);
}



void    init_philos(t_philo *philo, pthread_mutex_t *forks, t_rule *data)
{
    int i;

    i = 0;
    while (i < data->num_of_philos)
    {
        philo[i].id = i + 1;
        philo[i].last_meal = 0;
        philo[i].dead = &data->dead_flag;
        philo[i].meals_eaten = 0;
        philo[i].l_fork = &forks[i];
        philo[i].r_fork = &forks[(i + 1) % data->num_of_philos];
        philo[i].data = data;  // No need for &data, it's already a pointer
        philo[i].write_lock = &data->write_lock;
        philo[i].dead_lock = &data->dead_lock;
        philo[i].meal_lock = &data->meal_lock;
        i++;
    }
}
void    init_forks(t_rule *data)
{
    int i;

    i = 0;
    while (i < data->num_of_philos)
    {
        if(pthread_mutex_init(&data->forks[i],NULL) != 0)
        {
            clean_up_all(data,i);
            ft_err("Error initialising mutex",1);
        }
        i++;
    }
}
void    init_program(t_rule *data, t_philo* philos, char **argv, pthread_mutex_t *forks)
{
    data->dead_flag = 0;
    data->philos = philos;
    data->forks = forks;
    data->start_time = get_current_time();
    data->num_of_philos = atoi(argv[1]);
    data->time_to_die = atoi(argv[2]);
    data->time_to_eat = atoi(argv[3]);
    data->time_to_sleep = atoi(argv[4]);
    if (argv[5])
        data->num_times_to_eat = atoi(argv[5]);
    else
        data->num_times_to_eat = -1;
    if (pthread_mutex_init(&data->write_lock, NULL) != 0 ||
        pthread_mutex_init(&data->dead_lock, NULL) != 0 ||
        pthread_mutex_init(&data->meal_lock, NULL) != 0)
    {
        clean_mutexes(data);
        ft_err("Error initializing mutex", 1);
    }
}
