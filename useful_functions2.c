/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_functions2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 02:16:58 by hlabouit          #+#    #+#             */
/*   Updated: 2023/06/05 02:17:24 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

long	atoi_demo(const char *str, int start)
{
	int		i;
	long	nb;

	i = start;
	nb = 0;
	while (i < start + 8)
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (nb);
}
