# # MAKEFILE


#  	How you should structure your directory
#
# 	->CS-392
# 		|->include
# 			|-> header files
# 		|->lib
# 			|-> compiled libraries generated from your makefile
# 		|->src
# 			|-> my
# 				|-> Makefile
# 				|-> source files
# 			|-> next assignment
# 				|-> source files
# 		|->test
# 			|->Makefile
# 			|->test.c


# 	When submitting zip/rar/tar the root 392 directory.
# 	Test.c is where you should make a test main using your library

NAME = server
NAME2 = client
 
SRC1 = server.c
OBJ1 = $(SRC1:.c=.o)
 
SRC2 = client.c
OBJ2 = $(SRC2:.c=.o)
 
CFLAGS = -I../../include
LDFLAGS =
 
all: server client
 
server: $(OBJ1)
	gcc -pedantic -Wall -Werror -L../../lib $(OBJ1) -o $(NAME) -lmy
 
client: $(OBJ2)
	gcc -pedantic -Wall -Werror -L../../lib $(OBJ2) -o $(NAME2) -lmy
 
clean:
	rm -f $(OBJ1)
	rm -f $(NAME)
	rm -f $(OBJ2)
	rm -f $(NAME2)
 
re: clean all
