/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:51:19 by hlabouit          #+#    #+#             */
/*   Updated: 2023/06/05 17:42:05 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	server(int signal, siginfo_t *info, void *context)
{
	static char	byte[33];
	static int	i = 0;
	static int	c_pid = 0;

	(void)context;
	if (c_pid != info->si_pid)
	{
		i = 0;
		ft_putstr_fd("\n", 1);
		c_pid = info->si_pid;
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
	output_message(byte, &i, info);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sig_a;

	sig_a.sa_flags = SA_SIGINFO;
	sig_a.sa_sigaction = server;
	sigaction(SIGUSR1, &sig_a, NULL);
	sigaction(SIGUSR2, &sig_a, NULL);
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
	while (1)
	{
		pause();
	}
	return (0);
}
