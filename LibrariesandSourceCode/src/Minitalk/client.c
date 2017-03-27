#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include "my.h"

void receiveAck();
void sigAlarm();

int gl_ack = 0;

int main(int argc, char *argv[])
{
	char ch;
	int bin_helper;
	int i;
	int j;
	int pid_size = sizeof(pid_t) * 8;
	int myPID = getpid();
	int serverPID;
	signal(SIGUSR1,receiveAck);
	signal(SIGALRM,sigAlarm);
	if (argc < 3)
	{
		my_str("\nNot enough arguments. Exiting.\n");
		exit(0);
	}
	my_str("\n");
	serverPID = my_atoi(argv[1]);
	for (i = 1; i <= pid_size; i++)
	{
		bin_helper = (1 << (pid_size - i ));
		if ((myPID & bin_helper) == 0)
		{
			kill(serverPID,SIGUSR1);
		}
		else
		{
			kill(serverPID,SIGUSR2);
		}
		usleep(2000);
	}
	alarm(5);
	if (!gl_ack)
	{
		pause();
	}
	alarm(0);
	ch = argv[2][0];
	j = 0;
	while (ch != '\0')
	{
		for (i = 1; i <= 8; i++)
		{
			bin_helper = (1 << (8 - i));
			if ((ch & bin_helper) == 0)
			{
				kill(serverPID,SIGUSR1);
			}
			else
			{
				kill(serverPID,SIGUSR2);
			}
			usleep(2000);	
		}
		j++;
		ch = argv[2][j];
	}
	for (i = 1; i <= 8; i++)
	{
		bin_helper = (1 << (8 - i));
		if ((ch & bin_helper) == 0)
		{
			kill(serverPID,SIGUSR1);
		}
		else
		{
			kill(serverPID,SIGUSR2);
		}
		usleep(2000);	
	}
}

void receiveAck()
{
	gl_ack = 1;
}

void sigAlarm()
{
	my_str("Connection Failed.\n");
	exit(0);
}
