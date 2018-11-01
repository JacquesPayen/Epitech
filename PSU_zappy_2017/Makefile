##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## 
##

CFLAGS	=	-lSDL -lSDL_ttf	

SRC	=	server/src/asset.c	\
		server/src/broadcast.c	\
		server/src/configuration.c	\
		server/src/connect_nbr.c	\
		server/src/death.c	\
		server/src/ejection.c	\
		server/src/fork.c	\
		server/src/get_arguments.c	\
		server/src/graphic.c	\
		server/src/graphic_draw.c	\
		server/src/graphic_gestion.c	\
		server/src/graphic_texte.c	\
		server/src/interaction.c	\
		server/src/inventory.c	\
		server/src/look.c	\
		server/src/main.c	\
		server/src/map_gestion.c	\
		server/src/move.c	\
		server/src/sound.c	\
		server/src/take.c	\
		server/src/turn.c	\
		server/src/incantation.c	\
		server/src/level1_5.c	\
		server/src/level6_7.c	\
		server/src/win.c

OBJ	=	$(SRC:.c=.o)

NAME	=	zappy_server

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -Wall -Wextra $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
