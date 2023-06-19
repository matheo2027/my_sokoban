##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC =	lib/my/my_putchar.c \
		lib/my/my_put_nbr.c \
		lib/my/my_putstr.c	\
		lib/my/my_strlen.c	\
		lib/my/mini_printf.c	\
		src/main.c	\
		src/rules_h.c	\
		src/check_if_key.c	\
		src/check_if_loose.c	\
		src/find_player.c	\
		src/check_if_map_corect.c	\
		src/read_map.c	\
		src/move_box.c	\
		src/movement.c	\
		src/play_sokoban.c	\
		src/check_if_win.c	\
		src/check_the_zone.c

OBJ = $(SRC:.c=.o)

NAME = my_sokoban

CFLAGS = -W -Wall -Wextra

all : $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -Iinclude -lncurses

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean	all

.PHONY: all clean fclean re
