/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:40:42 by hlabouit          #+#    #+#             */
/*   Updated: 2023/06/05 02:37:49 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	client(int pid, char *message)
{
	char	*byte;
	int		i;
	int		j;

	i = 0;
	while (message[i])
	{
		j = 0;
		byte = convert_to_binary(message[i]);
		while (byte[j])
		{
			if (byte[j] == '0')
				kill(pid, SIGUSR1);
			else if (byte[j] == '1')
				kill(pid, SIGUSR2);
			j++;
			usleep(700);
		}
		i++;
	}
}

void	check_errors(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac != 3)
	{
		ft_putstr_fd("invalid arguments", 2);
		exit(EXIT_FAILURE);
	}
	while (av[1][i])
	{
		if (ft_isdigit(av[1][i]) != 1)
		{
			ft_putstr_fd("invalid pid", 2);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	if (ft_atoi(av[1]) < 0)
	{
		ft_putstr_fd("invalid pid", 2);
		exit(EXIT_FAILURE);
	}
}

int	main(int ac, char **av)
{
	int		pid;
	char	*message;

	check_errors(ac, av);
	pid = ft_atoi(av[1]);
	message = av[2];
	client(pid, message);
}
