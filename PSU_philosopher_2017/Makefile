##
## EPITECH PROJECT, 2017
## libmy_malloc
## File description:
## 
##

CC =	gcc

CFLAGS =	-Wall -Wextra -pthread

SRC =	src/initialize_philosopher.c	\
	src/main.c	\
	src/manage_philosopher.c

OBJ =	$(SRC:.c=.o)

NAME =	philo

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) -L. $(OBJ) $(CFLAGS) -lriceferee

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:	fclean all
