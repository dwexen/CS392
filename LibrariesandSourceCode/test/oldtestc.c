#include "my.h"

int main(void)
{
    char* mystr = "Hello";
    my_str("Testing my_strindex with Hello, l Should print llo\n");
    my_str(my_strindex(mystr, 'l'));
    my_char('\n');
    my_str("Sending my_strindex NULL shouldn't blow up\n");
    my_strindex(NULL, NULL);
    
    #if 0
    char* hello = "hello";
    my_char('\n');
    char* h2;
    h2= my_strdup("hello");
    my_char('\n');
    my_str(hello);
    my_char('\n');
    my_str(h2); 
    my_char('\n');
    h2[0] = 'a';
    my_char('\n');
    my_str(hello);
    my_char('\n');
    my_str(h2);
    /*
    char* str = (char*) malloc(sizeof(char) * 20);
    char* str2 = "hello";
    char* str3 = "goodbye";
    */
    my_char('\n');
    my_char('h');
    my_char('\n');
    my_str(my_strindex("abcde", 'c'));
    my_char('\n');

    my_str(my_strrindex("hello", 'l'));
    my_char('\n');

  
   /*
    my_char('\n');
    my_strcpy("hello", "goodbye");
    my_char('\n');
    my_char('\n');
    my_str(my_strcat("hello", "goodbye"));
    my_char('\n');
    */

    char *str = "hello";
    my_char('\n');/*
    my_str(my_strcat(str, "goodbye"));
    my_char('\n');
    */

    my_char('\n');
    my_str(my_strconcat(str, "goodbye"));
    my_char('\n');
    my_str(str);
    my_char('\n');
   /* 
    my_char('\n');
    my_str(my_strcpy(str, "goodbye"));
    my_char('\n');
    */

    my_char('\n');
    my_str(my_strdup(""));
    my_char('\n');


    my_char('\n');
    my_str("Testing my_strnconcat");
    my_char('\n');
    char *str1 = "Hello World";
    my_str(my_strnconcat(str1, "no", 1));
    my_char('\n');
    my_str(str1);
    my_char('\n');
    
    char str2[20] = "hello world";
    my_str(my_strcpy(str2, "oogabooga"));
    my_str("\n");
    my_str(str1);
    my_str("\n");

    my_str(my_strncpy(str2, "oogabooga", 43));
    my_str(str1);
    my_char('\n');

    my_char('\n');
    char *str2vstr = "hello this is a string";
    char **resultvec = my_str2vect(str2vstr);
    my_str(resultvec[0]);
    my_str(resultvec[1]);
    my_str(resultvec[2]);
    my_str(resultvec[3]);
    my_str(resultvec[4]);
    my_char('\n');

    my_char('\n');
    char *vstr1 = my_strdup("hello");
    char *vstr2 = my_strdup("this");
    char *vstr3 = my_strdup("is");
    char *vstr4 = my_strdup("a");
    char *vstr5 = my_strdup("vector");
    char **v2sv = (char**)malloc(sizeof(char*) * (6));
    v2sv[0] = vstr1;
    v2sv[1] = vstr2;
    v2sv[2] = vstr3;
    v2sv[3] = vstr4;
    v2sv[4] = vstr5;
    v2sv[5] = NULL;
    char* resultantstring = my_vect2str(v2sv);
    my_str(resultantstring);
    my_char('\n');
    #endif
     return 0;
};
