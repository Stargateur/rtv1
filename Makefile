##
## Makefile for lol in /home/plasko_a/rendu/MUL_2013_wolf3d
## 
## Made by Antoine PLASKOWSKI
## Login   <plasko_a@epitech.net>
## 
## Started on  Fri Jan  3 12:53:41 2014 Antoine PLASKOWSKI
## Last update Sun Mar 16 20:05:12 2014 Antoine Plaskowski
##

CC	=	gcc

RM	=	rm -f

CFLAGS	+=	-Wextra -Wall -O3
CFLAGS	+=	-ansi -pedantic
CFLAGS	+=	-I include/

LDFLAGS	+=	-l X11 -l m

ifeq ($(CC), clang)
CFLAGS	+=	-Weverything
endif

NAME	=	rtv1

SRC	+=	src/main.c
SRC	+=	src/my_rtv1.c
SRC	+=	src/my_load_scene.c
SRC	+=	src/my_light.c
SRC	+=	src/my_found_inter.c
SRC	+=	src/my_found_color.c
SRC	+=	src/my_found_lumi.c

SRC	+=	src/my_x.c
SRC	+=	src/my_put_p_i.c
SRC	+=	src/my_event_expose.c
SRC	+=	src/my_event_resize.c
SRC	+=	src/my_event_key_press.c

SRC	+=	src/my_open.c

SRC	+=	src/my_object.c
SRC	+=	src/my_tool_object.c

SRC	+=	src/my_matrix.c
SRC	+=	src/my_tool_matrix.c
SRC	+=	src/my_rotation.c
SRC	+=	src/my_position.c

SRC	+=	src/my_plan.c
SRC	+=	src/my_cylinder.c
SRC	+=	src/my_sphere.c
SRC	+=	src/my_cone.c

SRC	+=	src/my_tool_tab.c

SRC	+=	src/my_equation_second.c

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
