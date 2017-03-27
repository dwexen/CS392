#include "my.h"

char *my_strncpy(char *a, char *b, int n)
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
    if(n > my_strlen(b))
    {
        n = my_strlen(b);
    }
    while(i < n)
    {
        a[i] = b[i];
        i++;
    }
    return a;
}

