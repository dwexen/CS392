#include "my.h"
#include <unistd.h>

void my_char(char c)
{
	write(1, &c, 1);
}
