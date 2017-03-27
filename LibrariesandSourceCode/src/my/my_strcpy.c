#include "my.h"

char *my_strcpy(char *a, char *b)
{
    int i = 0;
    if(a == NULL && b == NULL)
    {
        return NULL;
    }
    if(b == NULL)
    {
        return a;
    }
    else if(a == NULL)
    {
        return NULL;
    }
    while(i < my_strlen(b))
    {
        a[i] = b[i];
        i++;
    }
    return a;
}
