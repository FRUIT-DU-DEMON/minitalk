# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/04 00:32:53 by hlabouit          #+#    #+#              #
#    Updated: 2023/06/04 01:47:19 by hlabouit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = client
NAME2 = server
SRCS =  useful_functions.c \
	   $(addprefix libft/, ft_putstr_fd.c ft_putnbr_fd.c \
	   ft_strlen.c ft_atoi.c ft_isdigit.c)
		
OBJS = $(SRCS:.c=.o)
CC =  cc
CFLAGS = -Werror -Wall -Wextra

all: $(NAME1) $(NAME2) libft/libft.a

$(NAME1): $(OBJS) libft/libft.a
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a client.c -o $(NAME1)
$(NAME2): $(OBJS) libft/libft.a
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a server.c -o $(NAME2)

libft/libft.a:
	@$(MAKE) -C libft

%.o: %.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) clean -C libft
	@rm -f $(OBJS) client.o server.o

fclean: clean
	@$(MAKE) fclean -C libft
	@rm -f $(NAME1) $(NAME2)

re: fclean all

.PHONY: all clean fclean re