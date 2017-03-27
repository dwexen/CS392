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

NAME = pipes

SRC = $(NAME.c) 

#MUST BE VERBOSE
OBJ = $(SRC:.c=.o)


LDFLAGS += -L../../lib 
LDLIBS += -lmy
CFLAGS += -g -I../../include -pedantic -Wall -Werror

all: $(NAME)

clean:
	-$(RM) *.o
	-$(RM) *~
	-$(RM) \#*

fclean: clean

re: fclean all
