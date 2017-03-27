#include "my.h"

char *my_vect2str(char **x)
{
    char *returnstr;
    int vecsize = 0;
    int strlength = 0;
    int i;
    int j;
    int k = 0;
    if(x == NULL)
    {
        return NULL;
    }
    while(x[vecsize] != NULL)
    {
        strlength += (my_strlen(x[vecsize]) + 1);
        vecsize++;
    }
    returnstr = (char*)malloc(sizeof(char) * (strlength));
    for(i = 0; i < vecsize; i++)
    {
        for(j = 0; j < my_strlen(x[i]); j++)
        {
            returnstr[k++] = x[i][j];
        }
        if(i != (vecsize - 1))
        {
             returnstr[k++] = ' ';
         }
    }
    return returnstr;
}
