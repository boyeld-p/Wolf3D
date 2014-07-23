##
## Makefile for wolf3d in /home/brahic_a/rendu/MUL_2013_wolf3d
## 
## Made by brahic
## Login   <brahic_a@epitech.net>
## 
## Started on  Tue Dec 17 10:14:14 2013 brahic
## Last update Wed Jul 23 20:06:14 2014 Aurélien Brahic
##

CC	= gcc -g3
RM	= rm -f

NAME	= wolf3d

SRCS	= 	main.c \
		my_putpix_img.c \
		my_uti.c \
		my_uti2.c \
		my_error.c \

OBJS	= $(SRCS:.c=.o)

CFLAGS	+= -W -Wall -Werror

MINI = -L./ -lmlx -L/usr/lib64/X11 -lXext -lX11

LIB = -lm -L./ -lmy -lmyigraph

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LIB) $(MINI)

clean:
		$(RM) $(OBJS)

fclean: 	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
