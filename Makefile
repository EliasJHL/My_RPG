##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

NAME = my_rpg

#CFLAGS = -W -Wall -Wextra -Werror

CSFML	=	-lcsfml-system -lcsfml-graphics -lcsfml-window -lcsfml-audio

CPPFLAGS = -I./include

SRCDIR	=	src

SRC	=	$(wildcard $(SRCDIR)/*.c)	\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CSFML)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
