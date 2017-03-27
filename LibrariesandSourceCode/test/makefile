NAME = testmy

SRC = testmy.c
OBJ = $(SRC:.c=.o)

CFLAGS = -I../include -pedantic -Wall -g
LDFLAGS = C99 

all: $(OBJ)
	cc -L../lib $(OBJ) -o $(NAME) -lmylist -lmy 

clean:
	rm -f $(OBJ)
	rm -f $(NAME)
