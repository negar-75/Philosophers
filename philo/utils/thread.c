#include "../philo.h"

void thread_creation (t_philo *philo)
{
    int i;
    pthread_t observer;

    i = 0;
    if (pthread_create(&observer, NULL, &monitor, (void *)philo) != 0)
        destroy_program("Thread creation error", philo->data, 1);
    while (i < philo->data->num_of_philos)
    {
        if (pthread_create(&philo[i].thread, NULL, &routine, (void *)&philo[i]) != 0)
            destroy_program("Thread creation error", philo->data, 1);
        i++;
    }
    i = 0;
    while (i < philo->data->num_of_philos)
    {
        if (pthread_join(philo[i].thread, NULL) != 0)
            destroy_program("Thread join error", philo->data, 1);
        i++;
    }
    if (pthread_join(observer, NULL) != 0)
        destroy_program("Observer thread join error", philo->data, 1);
}
