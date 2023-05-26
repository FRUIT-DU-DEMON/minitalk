/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:29:53 by hlabouit          #+#    #+#             */
/*   Updated: 2023/05/26 23:47:38 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void type(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr_fd("done\n", 1);
}

int main(int ac, char **av)
{
	pid_t pid;
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
	signal(SIGUSR1, type);
	while (1) 
	{
		pause();
	}
	return 0;
}
