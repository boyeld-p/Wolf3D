##
## Makefile for makefile in /home/Spam/rendu/Piscine-C-Jour_11
##
## Made by Brahic
## Login   <Spam@epitech.net>
##
## Started on  Mon Oct 21 14:46:42 2013 Brahic
## Last update Tue Dec 17 09:49:32 2013 brahic
##

CC = 		gcc -g
RM = 		rm -f

INC = 		./

NAME = 		libmy.a

NAME2 =		libmyigraph.a

LHEAD = 	./

HEAD =		my.h

SRCS =		my_printf.c \
		my_printf_fonc.c \
		my_printf_fonc2.c \
		my_printf_fonc3.c \
		my_putchar.c \
		my_nbr_len.c \
		my_put_nbr.c \
		my_putnbr_base.c \
		my_putnb_base_un.c \
		my_putnb_un.c \
		my_strlen.c \
		my_putstr.c \
		my_dir.c \
		my_dir2.c \
		my_getnbr.c \
		my_strcpy.c \
		my_strdup.c \
		get_next_line.c \
		my_str_to_wordtab.c \

SRCS2 = 	void_igraph.c \

OBJ = 		$(SRCS:.c=.o)

OBJ2 =		$(SRCS2:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ) $(OBJ2)
		$(CC) -c -W -Wall -Werror $(SRCS)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)
		$(CC) -c -W -Wall -Werror $(SRCS2)
		ar rc $(NAME2) $(OBJ2)
		ranlib $(NAME2)
		cp $(NAME) ../
		cp $(NAME2) ../
		cp my.h ../
		cp my_igraph.h ../

local:
		$(GCC) -c $(SRCS)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

clean:
		$(RM) $(OBJ)
		$(RM) $(OBJ2)

fclean: 	clean
		$(RM) $(NAME)
		$(RM) $(NAME2)
		$(RM) $(INC)$(NAME2)
		$(RM) $(INC)$(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re
