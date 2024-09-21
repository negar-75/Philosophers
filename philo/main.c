#include "./philo.h"



int main (int   argc, char    **argv)
{
	t_rule data;
	t_philo philos[MAX_NUM];
	pthread_mutex_t forks[MAX_NUM];

	if (argc != 5 && argc != 6 )
		ft_err("WRONG NUMBER OF ARGS",1);
    check_args(argv);
	init_program(&data, philos, argv, forks);
	init_forks(&data);
	init_philos(philos,forks, &data);
	thread_creation(philos);
    //destroy_program(NULL,&data,0);
	return 0;
}