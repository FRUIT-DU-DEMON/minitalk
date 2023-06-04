/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:29:53 by hlabouit          #+#    #+#             */
/*   Updated: 2023/06/04 01:22:20 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	server(int signal, siginfo_t *info, void *context)
{
	static char	byte[9];
	static int	i = 0;
	char c;

	(void)context;
	if (g_pid != info->si_pid)
	{
		i = 0;
		ft_putstr_fd("\n", 1);
		g_pid = info->si_pid;
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
	if (i == 8)
	{
		c = convert_to_decimal(ft_atoi(byte, 0));
		write(1, &c, 1);
		i = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sig_a;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
	sig_a.sa_sigaction = server;
	sigaction(SIGUSR1, &sig_a, NULL);
	sigaction(SIGUSR2, &sig_a, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
