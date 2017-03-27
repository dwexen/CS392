#include "my.h"

void my_alpha()
{
	int i;
	char c;
	for (i = 0, c = 'A'; i < 26; i++)
	{
		my_char(c++);
	}	
}
