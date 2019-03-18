##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile
##

SRC			=	src/Window.cpp	\
				src/Client.cpp	\
				src/Player.cpp	\
				src/Controller.cpp	\
				src/ControllerHandler.cpp	\
				src/World.cpp		\
				src/Tile.cpp	\
				src/Inventory.cpp	\
				src/main.cpp	\
				src/Box.cpp		\
				src/Team.cpp

OBJ			=	$(SRC:.cpp=.o)

CFLAGS 		=	-I./include -W -Wall -Wextra -Werror

NAME		=	the_eye

all:	$(NAME)

$(NAME): 	$(OBJ)
	g++ $(OBJ) -o $(NAME) -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -pthread

clean:
	rm -f $(OBJ)

fclean: 	clean
	rm -f $(NAME)

re: 	fclean all
