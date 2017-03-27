#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include "my.h"

void quitProg();
void pidReceive0();
void pidReceive1();
void charReceive0();
void charReceive1();

int pid = 0;
int c = 0;

int main(int argc, char *argv[])
{
	int f = 1;
	int i;
	int pid_size = sizeof(pid_t) * 8;
	int myProcessID = getpid();
	my_int(myProcessID);
	my_str("\n");
	signal(SIGINT, quitProg);
	while(1)
	{
		f = 1;
		pid = 0;
		signal(SIGUSR1,pidReceive0);
		signal(SIGUSR2,pidReceive1);
		pause();
		for (i = 0; i < pid_size - 1; i++)
		{
			alarm(5);
			pause();
			alarm(0);	
		}
		pid /= 2;
		//my_str("\n");
		kill(pid,SIGUSR1);
		signal(SIGUSR1,charReceive0);
		signal(SIGUSR2,charReceive1);
		while (f)
		{
			for (i = 0; i < 8; i++)
			{
				alarm(20);
				pause();
				alarm(0);
			}
			c /= 2;
			if (c != '\0')
			{
				my_char(c);
				c = 0;
			}
			else
			{
				my_char('\n');
				c = 0;
				f = 0;
			}
		}
	}
}

void quitProg()
{
	my_str("\nQuitting!\n");
    kill(pid, SIGINT);
	exit(0);
}

void pidReceive0()
{
	pid <<= 1;
}

void pidReceive1()
{
	pid++;
	pid <<= 1;
}

void charReceive0()
{
	c <<= 1;
}

void charReceive1()
{
	c++;
	c <<= 1;
}

