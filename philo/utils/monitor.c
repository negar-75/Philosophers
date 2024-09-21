#include "../philo.h"

void print_msg(char *str, t_philo *philo, int id)
{
    size_t time;
    pthread_mutex_lock(philo->write_lock);
    time = get_current_time() - philo->data->start_time;
    if(search_for_dead(philo) == 0)
        printf("%zu\t %d %s\n",time,id,str);
    pthread_mutex_unlock(philo->write_lock);

}

int is_dead (t_philo *philo)
{
    int is_dead;

    is_dead = 0;
    pthread_mutex_lock(philo->meal_lock);
    if(get_current_time() - philo->last_meal  >= philo->data->time_to_die)
        is_dead = 1;
    pthread_mutex_unlock(philo->meal_lock);
    return (is_dead);
}

int if_all_dead(t_philo *philo)
{
    int i;

    i = 0;
    while(i < philo->data->num_of_philos)
    {
        if(is_dead(&philo[i]) == 1)
        {
            print_msg("dead", &philo[i], philo[i].id);
            pthread_mutex_lock(philo->dead_lock);
            *philo[i].dead= 1;
            pthread_mutex_unlock(philo->dead_lock);
            return (1);
        }
        i++;
    }
    return(0);
}

int if_all_eat(t_philo *philo)
{
    int i;
    int eaten;

    if(philo->data->num_times_to_eat == -1)
        return (0);
    i = 0;
    eaten = 0;
    while(i < philo->data->num_of_philos)
    {
        pthread_mutex_lock(philo[i].meal_lock);
        if(philo[i].meals_eaten == philo->data->num_times_to_eat)
            eaten++;
        pthread_mutex_unlock(philo->meal_lock);
        i++;
    }
   if(eaten == philo->data->num_of_philos)
    {
        pthread_mutex_lock(&philo->data->dead_lock);
        philo->data->dead_flag = 1;
        pthread_mutex_unlock(&philo->data->dead_lock);
        return (1);        
    }
    return(0);
}

void *monitor(void* pointer)
{
    t_philo *philos;

    philos = (t_philo *)pointer;
    while(1)
    {
        if(if_all_dead(philos) == 1 || if_all_eat(philos) == 1)
            break;
    }
        return (pointer);
}
