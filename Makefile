##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

NAME = my_rpg

#CFLAGS = -W -Wall -Wextra -Werror

CPPFLAGS = -I./include

SRC =	src/main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
