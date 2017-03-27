#include "my.h"

char *my_strrindex(char* a, char b)
{
    int i = 0;
    int ans = -1;
    if(a == NULL)
    {
        return NULL;
    }
    while(a[i] != '\0')
    {
        if (a[i] == b)
        {
            ans = i;
        }
        i++;
    }
    if(ans == -1)
    {
        return NULL;
    }

    return a + ans;
}
