##
## EPITECH PROJECT, 2025
## makefile
## File description:
## makefile
##

SRC =		randint.c	\
		get_millis.c	\
		check_path.c

LIBNAME	=	libmy.a

OBJ	=	$(SRC:.c=.o)

CPPFLAGS = -fno-builtin -W -Wall -iquote../../include/

all: $(OBJ)
	ar rc $(LIBNAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(LIBNAME)
