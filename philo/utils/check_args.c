/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:02:42 by nnasiri           #+#    #+#             */
/*   Updated: 2024/09/24 14:24:51 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	if_all_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

void	check_args(char **argv)
{
	if (ft_atoi(argv[1]) > MAX_NUM || ft_atoi(argv[1]) <= 0
		|| if_all_digit(argv[1]))
		ft_err("Invalid philosophers number", 1);
	if (ft_atoi(argv[2]) < 60 || if_all_digit(argv[2]))
		ft_err("Invalid time to die number", 1);
	if (ft_atoi(argv[3]) < 60 || if_all_digit(argv[3]))
		ft_err("Invalid time to eat number", 1);
	if (ft_atoi(argv[4]) < 60 || if_all_digit(argv[4]))
		ft_err("Invalid time to sleep number", 1);
	if (argv[5] && (ft_atoi(argv[5]) <= 0 || if_all_digit(argv[5])))
		ft_err("Invalid number of time each philosopher should eat", 1);
}
