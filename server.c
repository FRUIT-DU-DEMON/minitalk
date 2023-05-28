/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:29:53 by hlabouit          #+#    #+#             */
/*   Updated: 2023/05/28 01:46:03 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <math.h>

// void	server()


void track_signal(int signal, siginfo_t *info, void *context)
{
	char byte[8];
	static int	i = 0;

	byte[7] = '\0';
	while (i < 8)
	{
		if (signal == SIGUSR1)
			byte[i] = '0';
		else if (signal == SIGUSR2)
			byte[i] = '1';
		i++;
	}
	printf("%s\n", byte);
}


int main(int ac, char **av)
{
	printf("%f\n",pow(2, 3));
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
