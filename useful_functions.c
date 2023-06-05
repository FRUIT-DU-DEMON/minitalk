/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 22:52:49 by hlabouit          #+#    #+#             */
/*   Updated: 2023/06/05 17:53:02 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	assemble_bytes(char *byte, int *i, int bits, siginfo_t *info)
{
	int		start;
	char	c;

	start = 0;
	*i = 0;
	while (start < bits)
	{
		c = convert_to_decimal(atoi_demo(byte, start));
		if (c == 0)
		{
			kill(info->si_pid, SIGUSR1);
			break ;
		}
		write(1, &c, 1);
		start = start + 8;
	}
}

void	output_message(char *byte, int *i, siginfo_t *info)
{
	if (byte[0] == '0' && *i == 8)
		assemble_bytes(byte, i, 8, info);
	else if (byte[0] == '1' && byte[1] == '1' && byte[2] == '0' && *i == 16)
		assemble_bytes(byte, i, 16, info);
	else if (byte[0] == '1' && byte[1] == '1'
		&& byte[2] == '1' && byte[3] == '0' && *i == 24)
		assemble_bytes(byte, i, 24, info);
	else if (byte[0] == '1' && byte[1] == '1'
		&& byte[2] == '1' && byte[3] == '1' && byte[4] == '0' && *i == 32)
		assemble_bytes(byte, i, 32, info);
}

char	*convert_to_binary(unsigned char c)
{
	char	*byte;
	int		reminder;
	int		i;

	byte = malloc(9);
	byte[8] = '\0';
	reminder = 1;
	i = 7;
	while (i >= 0)
	{
		reminder = c % 2;
		c = c / 2;
		byte[i] = reminder + '0';
		i--;
	}
	return (byte);
}

int	convert_to_decimal(int binary)
{
	int	decimal;
	int	reminder;
	int	i;

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
