# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/04 00:32:53 by hlabouit          #+#    #+#              #
#    Updated: 2023/06/04 17:27:43 by hlabouit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = client
NAME2 = server

SRCS1 = client.c useful_functions.c \
	   $(addprefix libft/, ft_putstr_fd.c ft_putnbr_fd.c \
	   ft_strlen.c ft_atoi.c ft_isdigit.c)
	
SRCS2 = server.c useful_functions.c \
	   $(addprefix libft/, ft_putstr_fd.c ft_putnbr_fd.c \
	   ft_strlen.c ft_atoi.c ft_isdigit.c)
		
OBJS1 = $(SRCS1:.c=.o)
OBJS2 = $(SRCS2:.c=.o)
CC =  cc
CFLAGS = -Werror -Wall -Wextra

all: $(NAME2) $(NAME1)

$(NAME1): $(OBJS1) libft/libft.a
	$(CC) $(CFLAGS) $(OBJS1) libft/libft.a -o $(NAME1)

$(NAME2): $(OBJS2) libft/libft.a
	$(CC) $(CFLAGS) $(OBJS2) libft/libft.a -o $(NAME2)

libft/libft.a:
	@$(MAKE) -C libft

%.o: %.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) clean -C libft
	@rm -f $(OBJS1) $(OBJS2) client.o server.o

fclean: clean
	@$(MAKE) fclean -C libft
	@rm -f $(NAME1) $(NAME2)

re: fclean all

.PHONY: all clean fclean re