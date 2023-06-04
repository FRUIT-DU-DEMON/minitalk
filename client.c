/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:26:38 by hlabouit          #+#    #+#             */
/*   Updated: 2023/06/04 18:18:06 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void_t pid, char *message)
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
			usleep(9000);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac != 3)
		return 0;
	
	while (av[1][i])
	{
		if (ft_isdigit(av[1][i]) != 1)
			return 0;
		i++;
	}
	
	client(atoi(av[1]), av[2]);
}
