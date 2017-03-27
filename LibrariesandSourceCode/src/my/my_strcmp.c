#include "my.h"

int my_strcmp(char *a, char *b)
{
	if (a == NULL && b == NULL)
	{
		return 0;
	}
	else if (a == NULL)
	{
		return -*b;
	}
	else if (b == NULL)
	{
		return *a;
	}
	while (*a == *b)
	{
		if (*a == '\0' && *b == '\0')
		{
			return 0;
		}
		a++;
		b++;
	}
	return *a - *b;
}
