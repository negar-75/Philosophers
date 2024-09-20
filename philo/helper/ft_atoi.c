#include "../philo.h"


size_t	ft_atoi(const char *str)
{
	size_t		i;
	size_t		res;

	i = 0;
	res = 0;
    while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
    if (str[i] == '-')
		return (0);
	if (str[i] == '+')
		i++;

	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
        res = res * 10 + (str[i] - '0');
        if (res > INT_MAX)
			return (0); 
        i++;
	}
    return (res);
}
