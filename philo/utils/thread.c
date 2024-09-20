#include "../philo.h"

void philo_thread_creation (t_philo *philo)
{
    int i;

    i = 0;
    while (i < philo->data->num_of_philos)
    {
        if(pthread_create(&philo[i].thread,NULL, &routine, &philo[i]) != 0)
            destroy_program("Thread creation error",philo->data,1);
        if(pthread_join(philo[i].thread,NULL) != 0)
            destroy_program("Thread creation error",philo->data,1);
    }
}

void monitor_thread_creation (t_philo *philo)
{
    pthread_t observer;
    if (pthread_create(&observer,NULL,&monitor,philo->data) != 0)
        destroy_program("Thread creation error",philo->data, 1);
    if(pthread_join(observer,NULL) != 0)
        destroy_program("Observer thread join error", philo->data, 1);
}