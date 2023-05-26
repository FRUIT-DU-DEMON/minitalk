/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:26:38 by hlabouit          #+#    #+#             */
/*   Updated: 2023/05/26 23:48:44 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*convert_to_binary(char c)
{
	int		binary;
	char	*str_binary;
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
	str_binary = ft_itoa(binary);
	return (str_binary);
}

void	client(pid_t pid, char *message)
{
	int i;
	int j;
	char	*binary;

	i = 0;
	while (message[i])
	{
		j = 0;
		binary = convert_to_binary(message[i]);
		while (binary[j])
		{
			if (binary[j] == '0')
				kill(pid, SIGUSR1);
			usleep(37);
			if (binary[j] == '1')
				kill(pid, SIGUSR2);
			usleep(37);
			j++;
		}
		usleep(37);
		i++;
	}
}

int main(int ac, char **av)
{
	client(14441, "wach les hommes");
}