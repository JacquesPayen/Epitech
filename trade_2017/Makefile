##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## 
##

CFLAGS	=	-lcriterion

SRC	=	src/main.cpp	\
		src/arg.cpp	\
		src/calcul.cpp	\
		src/get_indexe.cpp	\
		src/output.cpp	\
		src/stats.cpp

SRCT	=	tests/main.cpp	\
		tests/test.cpp	\
		src/arg.cpp	\
		src/calcul.cpp	\
		src/get_indexe.cpp	\
		src/output.cpp	\
		src/stats.cpp

OBJ	=	$(SRC:.cpp=.o)

OBJT	=	$(SRCT:.cpp=.o)

NAME	=	trade

NAMET	=	test

all:	$(NAME)

tests_run:	$(NAMET)

$(NAME):	$(OBJ)
	g++ $(OBJ) -o $(NAME) -Wall -Wextra -Werror


$(NAMET):	$(OBJT)
	g++ $(CFLAGS) $(OBJT) -o $(NAMET) -Wall -Wextra -Werror

clean:
	rm -f $(OBJ) $(OBJT)

fclean:	clean
	rm -f $(NAME) $(NAMET)

re:	fclean all
