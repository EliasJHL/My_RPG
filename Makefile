##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

NAME = my_rpg

#CFLAGS = -W -Wall -Wextra -Werror

CODINGSTYLE	=	coding-style-reports.log

CSFML	=	-lcsfml-system -lcsfml-graphics -lcsfml-window -lcsfml-audio -lm

CPPFLAGS = -I./include

SRCDIR	=	src

SRC	=	$(wildcard $(SRCDIR)/*.c)	\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CSFML)
	@echo "\033[32m= = = = =  COMPILATION COMPLETED  = = = = =\033[0m"

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) *~
	@$(RM) $(CODINGSTYLE)
	@echo "\033[31m= = = = = =   CLEAR COMPLETED   = = = = = =\033[0m"

re: fclean all
