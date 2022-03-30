##
## EPITECH PROJECT, 2022
## B-PSU-200-BDX-2-1-mysokoban-alex.aubry
## File description:
## Makefile
##

SRC	=	count.c	\
		alloc_array.c	\
		my_strlen.c	\
		str_with_str.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CPPFLAGS	=	-I ./include -g

all: $(NAME)

$(NAME):	$(OBJ)
	ar rc -o $(NAME) $(OBJ)
	cp $(NAME) ../

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re:	fclean all

.PHONY: all clean fclean re
