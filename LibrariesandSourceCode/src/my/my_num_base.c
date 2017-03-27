#include "my.h"

void my_num_base(int x, char* s)
{
	int i = 0;
	int min;
	unsigned int x0;
	unsigned int num;
	int pow;
	int k;
	int k1;
	if (s == NULL)
	{
		return;
	}
	while(s[i] != '\0')
	{
		i++;
	}
	if (i == 0)
	{
		return;
	}
	if (i == 1)
	{
		if (x >= 1)
		{	
			for (k = 0; k<x; k++)
			{
				my_char(s[0]);
			}
			return;
		}
		else if (x < 0)
		{
			my_char('-');
			x *= -1;
			for (k1 = 0; k1<x; k1++)
			{
				my_char(s[0]);
			}
			return;
		}
		else
		{
			return;
		}
	}
	min = 1 << ((8 * sizeof(int))-1);
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
	while (x0 > (i-1))
	{
		x0 /= i;
		pow *= i;
	}
	while (pow >= 1)
	{
		my_char(s[(num/pow)]);
		num %= pow;
		pow /= i;	
	}
}
