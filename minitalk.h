/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 21:49:32 by hlabouit          #+#    #+#             */
/*   Updated: 2023/05/31 18:28:29 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "libft/libft.h"

pid_t c_current_pid ;

char	*convert_to_binary(unsigned char c);
void	client(pid_t pid, char *message);
int	pwr(int number, int power);
int	convert_to_decimal(int binary);
void track_signal(int signal, siginfo_t *info, void *context);



#endif