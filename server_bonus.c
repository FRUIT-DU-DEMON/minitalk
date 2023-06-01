/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:51:19 by hlabouit          #+#    #+#             */
/*   Updated: 2023/06/01 22:01:29 by hlabouit         ###   ########.fr       */
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
	static char byte[33];
	static int	i = 0;
	int c;

	if (c_current_pid != info->si_pid)
	{
		i = 0;
		ft_putstr_fd("\n", 1);
		c_current_pid = info->si_pid;
	}
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
	if (byte[0] == '1' && byte[1] == '1' && byte[2] == '0' && i == 16)
	{
		c = convert_to_decimal(ft_atoi(byte, 0));
		write(1, &c, 1);
		c = convert_to_decimal(ft_atoi(byte, 8));
		write(1, &c, 1);
		i = 0;
	}
	if (byte[0] == '1' && byte[1] == '1' && byte[2] == '1' && byte[3] == '0' && i == 24)
	{
		c = convert_to_decimal(ft_atoi(byte, 0));
		write(1, &c, 1);
		c = convert_to_decimal(ft_atoi(byte, 8));
		write(1, &c, 1);
		c = convert_to_decimal(ft_atoi(byte, 16));
		write(1, &c, 1);
		i = 0;
	}
	else if (byte[0] == '1' && byte[1] == '1' && byte[2] == '1' && byte[3] == '1' && byte[4] == '0' && i == 32)
	{
		c = convert_to_decimal(ft_atoi(byte, 0));
		write(1, &c, 1);
		c = convert_to_decimal(ft_atoi(byte, 8));
		write(1, &c, 1);
		c = convert_to_decimal(ft_atoi(byte, 16));
		write(1, &c, 1);
		c = convert_to_decimal(ft_atoi(byte, 24));
		write(1, &c, 1);
		i = 0;
	}
	else if (byte[0] == '0' && i == 8)
	{
		c = convert_to_decimal(ft_atoi(byte, 0));
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
	// printf("%c\n", ));
	return 0;
}
