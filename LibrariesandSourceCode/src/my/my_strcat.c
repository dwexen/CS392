#include "my.h"

char *my_strcat(char *a, char *b)
{
    int length = my_strlen(a);
    int i = 0;
    if(a == NULL && b == NULL)
    {
        return NULL;
    }
    else if(a == NULL)
    {
        return NULL;
    }
    else if(b == NULL)
    {
        return a;
    }
    while(b[i] != '\0')
    {
        a[length + i] = b[i];
        i++;
    }
    return a;
}
