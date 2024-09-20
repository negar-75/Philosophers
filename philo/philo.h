#ifndef PHILO_H
#define PHILO_H

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include <limits.h>
#include<pthread.h>
#include<sys/time.h>

#define MAX_NUM 200

struct s_rule;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
    int				*dead;
    size_t          last_meal;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
    struct s_rule   *data;
}					t_philo;
typedef struct s_rule
{
	int				dead_flag;
	int				num_of_philos;
	int				num_times_to_eat;
	size_t			start_time;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}					t_rule;

void	    ft_putchar_fd(char c, int fd);
void	    ft_putendl_fd(char *s, int fd);
void	    ft_putstr_fd(char *s, int fd);
size_t	    ft_atoi(const char *str);

void    ft_err(char *err_msg, int err_code);
void    check_args (char   **args);
void    init_program(t_rule *data, t_philo* philos, char **argv, pthread_mutex_t *forks);
void    init_philos(t_philo *philo, pthread_mutex_t *forks, t_rule *data);
void    init_forks(t_rule *data);
void	destroy_program(char *str,t_rule *data, int err);
size_t  get_current_time(void);
void    *monitor(void* pointer);
int     search_for_dead (t_philo *philo);
void    ft_sleep(size_t milisec);
void    print_msg(char *str, t_philo *philo, int id);
void 	monitor_thread_creation (t_philo *philo);
void    philo_thread_creation (t_philo *philo);
void    *routine(void *pointer);

#endif