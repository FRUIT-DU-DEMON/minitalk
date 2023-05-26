/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:29:53 by hlabouit          #+#    #+#             */
/*   Updated: 2023/05/26 01:25:02 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void type(int sig)
{
	if (sig == SIGUSR1)
		printf("done\n");
}

int main(int ac, char **av)
{
	pid_t pid;
	pid = getpid();
	printf("%d\n", pid);

	struct sigaction sa;
	sa.sa_handler = type;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	while (1) 
	{
		pause();
	}
	return 0;
}
