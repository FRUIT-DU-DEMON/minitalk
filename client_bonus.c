/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:40:42 by hlabouit          #+#    #+#             */
/*   Updated: 2023/06/04 17:10:54 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	client(pid_t pid, char *message)
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
			usleep(500);
		}
		i++;
	}
}

int	main(void)
{
	client(55514, "😘😗🤨🧐ayo😋😛..this m😋😛essage is f😋😛rom 😋Morocco to Cuba😋");
}
