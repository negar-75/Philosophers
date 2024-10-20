/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:03:26 by nnasiri           #+#    #+#             */
/*   Updated: 2024/09/24 14:06:23 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define MAX_NUM 200

struct	s_rule;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				meals_eaten;
	int				eaten_enough;
	size_t			last_meal;
	int				r_fork;
	int 			l_fork;
	struct s_rule	*data;
}					t_philo;
typedef struct s_rule
{
	int				num_of_philos;
	int				num_times_to_eat;
	size_t			start_time;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	pthread_t		observer;
	pthread_mutex_t	full_eaten;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	forks[MAX_NUM];
	t_philo			philos[MAX_NUM];
	int				finished;
}					t_rule;

void				ft_putchar_fd(char c, int fd);
void			
	ft_putendl_fd(char *s, int fd);
void				ft_putstr_fd(char *s, int fd);
size_t				ft_atoi(const char *str);

void				ft_err(char *err_msg, int err_code);
void				check_args(char **args);
void				init_program( char **argv ,t_rule *data);
void				init_philos(t_rule *data);
void				init_forks(t_rule *data);
void				destroy_program(char *str, t_rule *data, int err);
size_t				get_current_time(void);
void				*monitor(void *pointer);
void				ft_sleep(size_t milisec);
void				print_msg(char *str, t_philo *philo, int force);
void				thread_creation(t_rule *data);
void				*routine(void *pointer);
void	run_philos(t_rule *data);
int	threads_join(t_rule *data);

#endif