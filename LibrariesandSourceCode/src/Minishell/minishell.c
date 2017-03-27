#include <unistd.h>
#include <errno.h>
#include "my.h"
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	char inputBuffer[1024];
	char* dirName;
	char** command; 
	int bytesRead;
	int processID;
	int status;
	my_str("Welcome!\n");
	while(1)
	{
		dirName = getcwd(dirName, 1024);
		my_str("\nminishell~ ");
		my_str(dirName);
		my_str(" /> ");
		bytesRead = read(0,inputBuffer,1024);
		inputBuffer[bytesRead-1] = '\0';
		command = my_str2vect(inputBuffer);
		if (command != NULL && command[0] != NULL)
		{
			if (!my_strcmp(command[0],"exit"))
			{
				my_str("Bye\n");
                my_freevect(command);
				exit(0);
			}
			else if (!my_strcmp(command[0],"cd"))
			{
				if (chdir(command[1]) == -1)
				{
					my_str("Can't find directory\n");
				}
			}
			else
			{
				processID = fork();
				if (processID > 0)
				{
					wait(&status);

				}
				else
				{
					if (execvp(command[0],command) == -1)
					{
						my_str("Not a valid command\n");
					}
					exit(1);
				}
			}
            my_freevect(command);
		}
	}
}

