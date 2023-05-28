/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:26:38 by hlabouit          #+#    #+#             */
/*   Updated: 2023/05/28 00:38:06 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*convert_to_binary(char c)
{
	char	*byte;
	int		reminder;
	int		binary;
	int		i;

	binary = 0;
	reminder = 1;
	i = 1;
	while (c != 0)
	{
		reminder = c % 2;
		c = c / 2;
		binary = binary + reminder * i;
		i = i * 10;
	}
	byte = ft_itoa(binary);
	printf("%s\n", byte);
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
			usleep(1337);
			if (byte[j] == '1')
				kill(pid, SIGUSR2);
			j++;
		}
		usleep(1337);
		i++;
	}
}

int main(int ac, char **av)
{
	client(50509, "a");
}