#include "my.h"
#include <stdio.h>

int my_revstr(char *s)
{
	int i = my_strlen(s);
	int j;
	char c;
	if (s == NULL)
	{
		return i;
	}
	for (j = 0; j<(i/2); j++)
	{
		c = s[j];
		s[j] = s[(i-j-1)];
		s[(i-j-1)] = c;
	}
	return i;
}
