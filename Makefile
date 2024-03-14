##
## EPITECH PROJECT, 2022
## my_ls
## File description:
## Makefile
##

SRC	=	$(wildcard sokobandir/*.c)

SRC2 =	$(wildcard bonus/*.c)

OBJ	=	$(SRC:sokobandir/.c=.o)

OBJ2 =	$(SRC2:bonus/.c=.o)

COPIES	=	*~

NAME	=	my_sokoban

NAME2	=	my_bonus_soko

MAKE	=	make

CFLAG	=	-L./lib/my -lmy -lncurses -g

all:	sokoban

.PHONY: bonus

bonus:	$(OBJ2)
	cd ./lib/my/ && $(MAKE)
	gcc -c $(SRC2)
	rm -f bonus/'*.o'
	gcc $(OBJ2) -o $(NAME2) $(CFLAG)

sokoban:	$(OBJ)
	cd ./lib/my/ && $(MAKE)
	gcc -c $(SRC)
	rm -f sokobandir/'*.o'
	gcc $(OBJ) -o $(NAME) $(CFLAG)

clean:
	rm -f $(COPIES)
	rm -f *.o
	rm -f sokobandir/*.o
	rm -f bonus/*.o

fclean:	clean
	rm -f $(NAME)
	rm -f $(NAME2)
	rm -f $(LIB)
	cd lib/my && rm -f "libmy.a"

re:     fclean all
