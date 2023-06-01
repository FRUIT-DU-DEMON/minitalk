/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:40:42 by hlabouit          #+#    #+#             */
/*   Updated: 2023/06/01 23:52:24 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*convert_to_binary(unsigned char c)
{
	char	*byte;
	int		reminder;
	int		i;

	byte = malloc(9);
	byte[8] = '\0';
	reminder = 1;
	i = 7;
	while (i >= 0)
	{
		reminder = c % 2;
		c = c / 2;
		byte[i] = reminder + '0';
		i--;
	}
	// printf("%s\n", byte);
	// exit(0);
	return (byte);
}

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
			usleep(9000);
		}
		i++;
	}
}

int main(int ac, char **av)
{
	client(80675, "ayo..this message is from Morocco to Cuba");
}