#include "my.h"

char *my_strconcat(char *a, char *b)
{
    char* stra;
    if(a == NULL && b == NULL)
    {
        return NULL;
    }
    if(a == NULL)
    {
        return b;
    }
    else if(b == NULL)
    {
        return a;
    }
    stra = (char*) malloc(sizeof(char) * (my_strlen(a) + my_strlen(b)));
    stra = my_strcpy(stra, a);
    /*
    strb = my_strdup(b);
    */
    stra = my_strcat(stra, b);
    return stra;
}
