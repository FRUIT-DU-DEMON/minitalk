/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 21:49:32 by hlabouit          #+#    #+#             */
/*   Updated: 2023/06/05 02:51:43 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "libft/libft.h"

pid_t	g_pid;

void	client(int pid, char *message);
void	server(int signal, siginfo_t *info, void *context);
char	*convert_to_binary(unsigned char c);
int		convert_to_decimal(int binary);
int		pwr(int number, int power);
long	atoi_demo(const char *str, int start);
void	output_message(char *byte, int *i);
void	assemble_bytes(char *byte, int *i, int start, int bits);
void	check_errors(int ac, char **av);

#endif