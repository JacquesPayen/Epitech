##
## EPITECH PROJECT, 2017
## libmy_malloc
## File description:
## 
##

CC =	gcc

CFLAGS =	-fPIC -Wall -Wextra

SRC =	src/malloc.c	\
	src/free.c	\
	src/mem.c	\
	src/realloc.c

OBJ =	$(SRC:.c=.o)

NAME =	libmy_malloc.so

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(FLAGS) $(OBJ) -shared -o $(NAME)

CC =    gcc

FLAG =  -lcriterion --coverage

SRC1 =  tests/simple.c

OBJ1 =   $(SRC1:.c=.o)

NAME1 =  test

tests_run:	$(NAME1)

$(NAME1):	$(OBJ1)
		$(CC) $(FLAG) $(OBJ1) -o $(NAME1)

clean:
		rm -f $(OBJ) $(OBJ1)

fclean:		clean
		rm -f $(NAME) $(NAME1)

re:	fclean all
