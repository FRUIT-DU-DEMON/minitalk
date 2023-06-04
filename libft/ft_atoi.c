/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:48:01 by hlabouit          #+#    #+#             */
/*   Updated: 2023/06/03 17:16:33 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *str, int start)
{
	int		i;
	long	nb;
	int		sign;

	i = start;
	nb = 0;
	sign = 1;
	while (i < start + 8)
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (nb * sign);
}
