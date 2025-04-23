# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: delhajou <delhajou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/21 18:13:04 by delhajou          #+#    #+#              #
#    Updated: 2025/03/23 01:35:28 by delhajou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client
NAME_SERVER = server
SRCS_CLIENT = client.c\
helpers.c\

SRCS_SERVER = server.c \
helpers.c\

OBJCS_SERVER = $(SRCS_SERVER:%.c=%.o)
OBJCS_CLIENT = $(SRCS_CLIENT:%.c=%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror 

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJCS_CLIENT)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJCS_CLIENT)
$(NAME_SERVER): $(OBJCS_SERVER)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJCS_SERVER)

%.o : %.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJCS_CLIENT) $(OBJCS_SERVER)
fclean : clean
	rm -rf $(NAME_CLIENT) $(NAME_SERVER)
re : clean fclean all
.Phony: clean 