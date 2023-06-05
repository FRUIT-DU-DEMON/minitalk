# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/04 00:32:53 by hlabouit          #+#    #+#              #
#    Updated: 2023/06/05 02:53:52 by hlabouit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = client
NAME2 = server
NAME1_BNS = client_bonus
NAME2_BNS = server_bonus

SRCS = useful_functions.c useful_functions2.c\
	   $(addprefix libft/, ft_putstr_fd.c ft_putnbr_fd.c \
	   ft_strlen.c ft_atoi.c ft_isdigit.c)
		
OBJS = $(SRCS:.c=.o)
CC =  cc
CFLAGS = -Werror -Wall -Wextra

all: $(NAME2) $(NAME1)

bonus: $(NAME1_BNS) $(NAME2_BNS)

$(NAME1): $(OBJS) libft/libft.a
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a client.c  -o $(NAME1)

$(NAME2): $(OBJS) libft/libft.a
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a server.c -o $(NAME2)

$(NAME1_BNS): $(OBJS) libft/libft.a
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a client_bonus.c -o $(NAME1_BNS)

$(NAME2_BNS): $(OBJS) libft/libft.a
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a server_bonus.c -o $(NAME2_BNS)


libft/libft.a:
	@$(MAKE) -C libft

%.o: %.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) clean -C libft
	@rm -f $(OBJS) client.o server.o client_bonus.o server_bonus.o 

fclean: clean
	@$(MAKE) fclean -C libft
	@rm -f $(NAME1) $(NAME2)

re: fclean all

.PHONY: all clean fclean re