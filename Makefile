##
## EPITECH PROJECT, 2022
## B-PSU-200-BDX-2-1-mysokoban-alex.aubry
## File description:
## Makefile
##

SRC	=	src/sokoban.c	\
		src/detect.c	\
		src/get_pos.c	\
		src/print.c	\
		src/check_errors.c	\
		src/move.c	\
		src/get_key.c	\
		src/check.c

MAIN	=	main.c

OBJ	=	$(SRC:.c=.o)

MAIN_OBJ	=	$(MAIN:.c=.o)

NAME	=	my_sokoban

LIB	=	libmy.a

CPPFLAGS	=	-I ./include -lncurses

TEST	=	tests/test_check_errors.c

CCFLAGS	=	--coverage -lcriterion

all:	$(NAME)

$(NAME):	$(OBJ) $(MAIN_OBJ)
	make -C lib
	gcc -o $(NAME) $(MAIN_OBJ) $(OBJ) $(LIB) $(CPPFLAGS)

tests_run:	$(OBJ)
	gcc -o unit_tests $(OBJ) $(CPPFLAGS) $(CCFLAGS) $(TEST)
	./unit_tests
	rm -f ./unit_tests

clean:
	rm -f *.o
	rm -f *.gc*
	rm -f src/*.o
	make clean -C lib

fclean:	clean
	rm -f $(NAME)
	make fclean -C lib

re:	fclean all

debug:	CPPFLAGS += -g
debug: 	re

.PHONY: all tests_run clean fclean re debug
