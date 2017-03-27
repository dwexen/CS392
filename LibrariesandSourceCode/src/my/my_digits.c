#include "my.h"

void my_digits()
{
	int i;
	char c;
	for (i = 0, c = '0'; i < 10; i++)
	{
		my_char(c++);
	}	
}
