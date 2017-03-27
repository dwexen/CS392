#include "my.h"

char *my_strindex(char* a, char b)
{
    int i = 0;
    if(a == NULL)
    {
        return NULL;
    }
    while(a[i] != '\0')
    {
        if (a[i] == b)
        {
            return a + i;
        }
        i++;
    }
    return NULL;
}
