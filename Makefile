##
## Makefile for lol in /home/plasko_a/rendu/MUL_2013_wolf3d
## 
## Made by Antoine PLASKOWSKI
## Login   <plasko_a@epitech.net>
## 
## Started on  Fri Jan  3 12:53:41 2014 Antoine PLASKOWSKI
## Last update Fri Feb 28 11:00:20 2014 Antoine Plaskowski
##

CC	=	clang

RM	=	rm -f

CFLAGS	+=	-Wextra -Wall -O3 -g
CFLAGS	+=	-ansi -pedantic
CFLAGS	+=	-I include/

LDFLAGS	+=	-l X11 -l m

NAME	=	rtv1

SRC	+=	src/main.c
SRC	+=	src/my_parsing.c

SRC	+=	src/my_x.c
SRC	+=	src/my_put_pixel_to_img.c

SRC	+=	src/my_open.c

SRC	+=	src/my_object.c
SRC	+=	src/my_tool_object.c

SRC	+=	src/my_matrix.c
SRC	+=	src/my_tool_matrix.c

SRC	+=	src/my_tool_tab.c

SRC	+=	src/my_str_to_wordtab.c
SRC	+=	src/my_malloc.c
SRC	+=	src/my_putchar.c
SRC	+=	src/my_putstr.c
SRC	+=	src/my_putnbr.c
SRC	+=	src/my_putnbr_base.c
SRC	+=	src/my_getnbr.c
SRC	+=	src/my_getnbr_base.c
SRC	+=	src/my_strcpy.c
SRC	+=	src/my_strlen.c
SRC	+=	src/my_strcmp.c
SRC	+=	src/my_strncmp.c
SRC	+=	src/my_strdup.c
SRC	+=	src/my_char_in_str.c
SRC	+=	src/my_get_next_line.c

OBJ	=	$(SRC:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
