#include "my.h"

char *my_strnconcat(char* a, char* b, int n)
{
    char* stra;
    int i;
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
    if(n > my_strlen(b))
    {
        n = my_strlen(b);
    }
    stra = (char*) malloc(sizeof(char) * (n +(my_strlen(a))));
    stra = my_strcpy(stra, a);
    for(i = 0; i < n; i++)
    {
        stra[my_strlen(a) + i] = b[i];
    }
    return stra;
}
