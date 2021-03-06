#ifndef _MY_H_
#define _MY_H_

#ifndef NULL
#define NULL ((void*) 0)
#endif

#include "mylist.h"
#include <stdlib.h>

void my_char(char);
void my_str(char*);
void my_int(int);
void my_num_base(int, char*);
void my_alpha();
void my_digits();
int my_find(char*, char);
int my_rfind(char*, char);
int my_strlen(char*);
int my_revstr(char *);
char *my_strindex(char*, char);
char *my_strrindex(char*, char);
char *my_strcat(char*, char*);
char *my_strdup(char*);
char *my_strcpy(char*, char*);
int my_strcmp(char*, char*);
char *my_strconcat(char*, char*);
char *my_strnconcat(char*, char*, int);
char *my_strncpy(char*, char*, int);
char *my_vect2str(char **x);
char **my_str2vect(char*);
int my_atoi(char*);
int my_strncmp(char*, char*, int);
void my_freevect(char**);
#endif
