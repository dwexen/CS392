#include "my.h"

char **my_str2vect(char *s)
{
    char **returnvec;
    int strcounter = 0;
    int indivstrlen = 0;
    int i = 0;
    int j;
    int k = 0;
    if(s == NULL)
    {
        return NULL;
    }
    while(i < my_strlen(s))
    {
        while(s[i] == ' ')
        {
            i++;
        }
        if(i < (my_strlen(s) -1))
        {
            if(s[i+1] == ' ')
            {
                strcounter++;
            }
        }
        else if(i == (my_strlen(s) - 1) && s[i] != ' ')
        {
            strcounter++;
        }
        i++;
    }
    returnvec =  (char**)malloc(sizeof(char*) * (strcounter + 1));
    i = 0;
    for(j = 0; j < strcounter; j++)
    {
        indivstrlen = 0;
        while(s[i] == ' ')
        {
            i++;
        }
        while(s[i] != ' ' && i < my_strlen(s))
        {
            indivstrlen++;
            i++;
        }
        if(indivstrlen > 0)
        {
            returnvec[j] = (char*)malloc(sizeof(char) * (indivstrlen + 1));
        }
    }
    returnvec[strcounter] = NULL;
    i = 0;
    for(j = 0; j < strcounter; j++)
    {
        k = 0;
        while(s[i] == ' ')
        {
            i++;
        }
        while(s[i] != ' ' && i < (my_strlen(s)))
        {
            returnvec[j][k] = s[i];
            k++;
            i++;
        }
        returnvec[j][k] = '\0';
    }
    return returnvec;
}
