/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 01:36:18 by hlabouit          #+#    #+#             */
/*   Updated: 2023/06/01 21:47:00 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <fcntl.h>

int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
long	ft_atoi(const char *str, int start);
int		ft_isdigit(int c);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
char	**ft_split(char *s, char c);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
#endif