/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:29:53 by hlabouit          #+#    #+#             */
/*   Updated: 2023/05/30 15:33:24 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	pwr(int number, int power)
{
	int result;
	
	result = 1;
	while (power)
	{
		result = result * number;
		power--;
	}
	return (result);
}

int	convert_to_decimal(int binary)
{
	int decimal;
	int reminder;
	int i;

	i = 0;
	decimal = 0;
	while (binary != 0)
	{
		reminder = binary % 10;
		binary = binary / 10;
		decimal = decimal + reminder * pwr(2, i);
		i++;
	}
	return (decimal);
}

void track_signal(int signal, siginfo_t *info, void *context)
{
	static char byte[9];
	static int	i = 0;
	char c;

	if (signal == SIGUSR1)
	{
		byte[i] = '0';
		i++;
	}
	else if (signal == SIGUSR2)
	{
		byte[i] = '1';
		i++;
	}
	if (i == 8)
	{
		c = convert_to_decimal(ft_atoi(byte));
		write(1, &c, 1);
		i = 0;
	}
}


int main(int ac, char **av)
{
	pid_t pid;
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
	struct sigaction sig_a;
	sig_a.sa_sigaction = track_signal;
	sigaction(SIGUSR1, &sig_a, NULL);
	sigaction(SIGUSR2, &sig_a, NULL);
	while (1) 
	{
		pause();
	}
	return 0;
}
