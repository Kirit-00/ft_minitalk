# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/27 15:40:19 by maltun            #+#    #+#              #
#    Updated: 2023/05/06 00:46:51 by maltun           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ok 
SERVERBNS = server
SERVER = server
CLIENT = client
CLIENTBNS = client
CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: $(SERVER) $(CLIENT)

bonus:
	$(CC) $(CFLAGS) lib.c server_bonus.c -o $(SERVER)
	$(CC) $(CFLAGS) lib.c client_bonus.c -o $(CLIENT)

$(NAME): all

$(SERVER):
	$(CC) $(CFLAGS) lib.c server.c -o $(SERVER)

$(CLIENT):
	$(CC) $(CFLAGS) lib.c client.c -o $(CLIENT)

clean:
	rm -rf $(SERVER) $(CLIENT)

fclean: clean

re: fclean all

.PHONY: all fclean clean re bonus