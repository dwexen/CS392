#include "my.h"

char *my_strdup(char* x)
{
    char* str = (char*)malloc(sizeof(char) * (my_strlen(x) + 1));
    int i = 0;
    if(x == NULL)
    {
        return NULL;
    }
    for(i = 0; i < my_strlen(x) + 1; i++)
    {
        str[i] = x[i];
    }
    return str;
}
