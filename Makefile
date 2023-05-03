# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MAKEFILE                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/27 15:40:19 by maltun            #+#    #+#              #
#    Updated: 2023/05/03 07:41:01 by maltun           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ok 
SERVERBNS = server_bonus
SERVER = server
CLIENT = client
CLIENTBNS = client_bonus
CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: $(SERVER) $(CLIENT)

$(NAME): all

$(SERVER):
	$(CC) $(CFLAGS) lib.c server.c -o $(SERVER)

$(CLIENT):
	$(CC) $(CFLAGS) lib.c client.c -o $(CLIENT)

bonus: $(SERVERBNS) $(CLIENTBNS)

$(SERVERBNS):
	$(CC) $(CFLAGS) lib.c server_bonus.c -o $(SERVERBNS)

$(CLIENTBNS):
	$(CC) $(CFLAGS) lib.c client_bonus.c -o $(CLIENTBNS)

clean:
	rm -rf $(SERVER) $(CLIENT)

bclean:
	rm -rf $(SERVERBNS) $(CLIENTBNS)

fclean: clean bclean

re: fclean all bonus

.PHONY: all flean clean re