#include <unistd.h>
#include <errno.h>
#include "my.h"
#include <sys/wait.h> 

int main(int argc, char *argv[])
{
  char *inputBuffer = (char*)malloc(sizeof(char) * 100);
  char *buf = (char*)malloc(sizeof(char) * 100);
  char *buf2 = (char*)malloc(sizeof(char) * 100);
  int processID1;
  int processID2;
  int myPipe1 [2];
  int myPipe2 [2];
  int status1;
  int status2;
  int iBuffLen;

  if (argc < 2) {
    my_str("No command line argument given\n");
    return 1;
  }
  inputBuffer = my_vect2str(&argv[1]);
  iBuffLen = my_strlen(inputBuffer);
  inputBuffer[100] = '\0';
  if (pipe(myPipe1))
  {
    my_str("Pipe failed");
    return 1;
  }

  processID1 = fork();
  if (processID1 > 0)
  {
    write(myPipe1[1], inputBuffer, iBuffLen);
    close(myPipe1[1]);
    my_str(inputBuffer);
    my_str("\n");
    wait(&status1);
  }
  else if(processID1 == 0)
  {
    if(pipe(myPipe2))
    {
        my_str("pipe2 failed");
        return 1;
    }
    processID2 = fork();
    if (processID2 > 0)
    {
        read(myPipe1[0], buf, iBuffLen);
        close(myPipe1[0]);
        write(myPipe2[1], buf, iBuffLen);
        close(myPipe2[1]);
        my_str(buf);
        my_str("\n");
        wait(&status2);
    }
    else if(processID2 == 0)
    {
      read(myPipe2[0], buf2, iBuffLen);
      close(myPipe2[0]);
      my_str(buf2);
      my_str("\n");
    }
    else
    {
        my_str("fork failed\n");
    }
  }
  else
  {
      my_str("fork failed\n");
  }
  free(inputBuffer);
  free(buf);
  free(buf2);
  return 0;

}


