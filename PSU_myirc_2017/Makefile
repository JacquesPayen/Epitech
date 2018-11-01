##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## 
##

SRC1 =	server_src/main.c	\
	server_src/client.c	\
	server_src/buffer.c	\
	server_src/cmd.c	\
	server_src/login.c	\
	server_src/tools.c	\
	server_src/channel.c	\
	server_src/server.c

SRC2 =	client_src/main.c

OBJ1 =	$(SRC1:.c=.o)

OBJ2 =	$(SRC2:.c=.o)

NAME1 =  server

NAME2 =  client

all:	$(NAME1) $(NAME2)

$(NAME1):	$(OBJ1)
		gcc -o $(NAME1) $(OBJ1)

$(NAME2):	$(OBJ2)
		gcc -o $(NAME2) $(OBJ2)

clean:
	rm -f $(OBJ1) $(OBJ2)

fclean:		clean
		rm -f $(NAME1) $(NAME2)

re:	fclean all
