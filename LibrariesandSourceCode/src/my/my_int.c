#include "my.h"

void my_int(int x)
{
	int min = 1 << ((8 * sizeof(int))-1);
	unsigned int x0;
	int pow;
	unsigned int num;
	if ((x < 0 ) && (x != min))
	{
		my_char('-');
		x0 = -1 * x;
	}
	else if (x == min)
	{
		my_char('-');
		x += 1;
		x = ~(x);
		x0 = (unsigned int) x;
		x0 += 1;
	}
	else
	{
		x0 = (unsigned int) x;
	}
	num = x0;
	pow = 1;
	while (x0 > 9)
	{
		x0 /= 10;
		pow *= 10;
	}
	while (pow >= 1)
	{
		my_char((num/pow) + '0');
		num %= pow;
		pow /= 10;	
	}
}
