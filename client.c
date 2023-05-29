/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:26:38 by hlabouit          #+#    #+#             */
/*   Updated: 2023/05/29 22:52:37 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*convert_to_binary(unsigned char c)
{
	char	*byte;
	int		binary;
	int		reminder;
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
	// printf("%s\n", byte);
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
			usleep(10000);
		}
		i++;
	}
}

int main(int ac, char **av)
{
	client(94503, "a");
}