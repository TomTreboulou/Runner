##
## EPITECH PROJECT, 2018
## MUL_my_runner_2018
## File description:
## Makefile
##

NAME =	my_runner

SRC =	main.c \
		errormanagement.c \
		background.c \
		declaration.c \
		settings.c \
		game.c \
		draw.c \
		draw2.c \
		window.c \
		move.c \
		draw3.c \
		draw4.c \
		draw5.c \

OBJ =	$(SRC:.c=.o)

CC =	gcc

CFLAGS =	-lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio -g3

RM =	rm -f

RULE =	all

all:	$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)

re: fclean all