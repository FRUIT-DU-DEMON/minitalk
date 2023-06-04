/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 22:52:49 by hlabouit          #+#    #+#             */
/*   Updated: 2023/06/03 23:24:48 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	assemble_bytes(char *byte, int *i, int start, int bits)
{
	char	c;

	*i = 0;
	while (start < bits)
	{
		c = convert_to_decimal(ft_atoi(byte, start));
		write(1, &c, 1);
		start = start + 8;
	}
}

void	output_message(char *byte, int *i)
{
	if (byte[0] == '0' && *i == 8)
		assemble_bytes(byte, i, 0, 8);
	else if (byte[0] == '1' && byte[1] == '1' && byte[2] == '0' && *i == 16)
		assemble_bytes(byte, i, 0, 16);
	else if (byte[0] == '1' && byte[1] == '1'
		&& byte[2] == '1' && byte[3] == '0' && *i == 24)
		assemble_bytes(byte, i, 0, 24);
	else if (byte[0] == '1' && byte[1] == '1'
		&& byte[2] == '1' && byte[3] == '1' && byte[4] == '0' && *i == 32)
		assemble_bytes(byte, i, 0, 32);
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

int	pwr(int number, int power)
{
	int	result;

	result = 1;
	while (power)
	{
		result = result * number;
		power--;
	}
	return (result);
}
