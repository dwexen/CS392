#include "my.h"

int my_atoi(char* a)
{
	int ans = 0;
	int len = my_strlen(a);
	int i = 0;
	int neg = 0;
	if (len == 0 || len == -1)
	{
		return 0;
	}
	while (a[i] < 48  || a[i] > 57)
	{
		if (a[i]=='-')
		{
			neg++;
		}
		if (a[i]=='\0')
		{
			return ans;
		}
		i++;
	}
	while (a[i] >= 48 && a[i] <= 57)
	{
		ans = (10 * ans) + (a[i] - 48);
		i++;
	}
	for (i = 0; i<neg; i++)
	{
		ans *= -1;
	}
	return ans;
}
