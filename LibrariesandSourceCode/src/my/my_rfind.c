#include "my.h"

int my_rfind(char* s, char c)
{
	int i = 0;
	int ans = -1;
	if (s == NULL)
	{
		return -1;
	}
	while(s[i]!= '\0')
	{
		if (s[i]==c)
		{
			ans = i;
		}
		i++;
	}
	return ans;
}
