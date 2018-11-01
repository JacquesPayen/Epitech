##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

NAME	=	plazza

NAMEUI	=	lol

SRC	=	./src/main.cpp	\
		./src/argument.cpp	\
		./src/command.cpp	\
		./src/communication.cpp	\
		./src/get_information.cpp	\
		./src/instruction.cpp	\
		./src/instruction2.cpp	\
		./src/search.cpp	\
		./src/slave.cpp	\
		./src/ThreadCenter.cpp		\
		./src/gestioncmd.cpp	\
		./src/socket.cpp

SRCUI	=	./src/graphic/main.cpp	\
		./src/argument.cpp	\
		./src/command.cpp	\
		./src/communication.cpp	\
		./src/get_information.cpp	\
		./src/instruction.cpp	\
		./src/instruction2.cpp	\
		./src/search.cpp	\
		./src/slave.cpp	\
		./src/graphic/ThreadCenter.cpp	\
		./src/graphic/gestioncmd.cpp	\
		./src/graphic/graphic.cpp	\
		./src/socket.cpp

OBJ	=	$(SRC:.cpp=.o)

OBJUI	=	$(SRCUI:.cpp=.o)

CFLAGS	=	-Wall -Wextra -pthread

CXXFLAGSUI	=	-Wall -Wextra -pthread -lncurses

CXXFLAGS	=	-std=c++11

all:	$(NAME)

ui:	$(NAMEUI)

$(NAME):	$(OBJ) 
	g++ -o $(NAME) -L. $(OBJ) $(CFLAGS)

$(NAMEUI):	$(OBJUI) 
	g++ -o $(NAME) -L. $(OBJUI) $(CXXFLAGSUI)

clean:
	rm -f $(OBJ) $(OBJUI)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
