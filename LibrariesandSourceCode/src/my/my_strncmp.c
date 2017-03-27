#include "my.h"

int my_strncmp(char*a, char *b, int n)
{
	int i;
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
	for (i = 0; i < n; i++)
	{
		if (*a == '\0' && *b == '\0')
		{
			return 0;
		}
		else if (a[i] != b[i])
		{
			return a[i] - b[i];
		}
	}
	return 0;
}
