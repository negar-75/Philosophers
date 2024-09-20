#include "../philo.h"

void ft_err(char *str, int exit_code)
{
    ft_putendl_fd(str, 2);
	exit(exit_code);
}
