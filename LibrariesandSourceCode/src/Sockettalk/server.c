#include "mylist.h"
#include "my.h"
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAXMSG  512
struct clientList {
    int fd;
    char* username;
};

void mybzero(s1, n)
	void *s1;
	unsigned n;
{
	register char *t = s1;

	while (n != 0) 
	{
		*t++ = 0;
		n--;
	}
}


int main(int argc , char *argv[])
{
  int sock,k;
  fd_set active_fd_set, read_fd_set;
  int i, portno;
  struct sockaddr_in serv_addr, clientname;
  struct s_node* users = (struct s_node*)malloc(sizeof(struct s_node));
  socklen_t size;
  char *buffer;
  char* fullmsg;
  char* myuser;
  int nbytes;
  if(argc < 2)
  {
	my_str("give me a port number too");
	exit(0);
  }
  else
  {
	portno = my_atoi(argv[1]);
  }
  /* Create the socket and set it up to accept connections. */
  sock = socket(AF_INET, SOCK_STREAM, 0);
  mybzero((char*) &serv_addr, sizeof(serv_addr));
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

   if (bind(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
	{
		my_str("Error! problem with binding");
		exit(1);
	}
    if (listen (sock, 1) < 0)
    {
      my_str("listen");
      exit (0);
    }
  /* Initialize the set of active sockets. */
  FD_ZERO (&active_fd_set);
  FD_SET (sock, &active_fd_set);

  while (1)
    {
        //my_str("top of while loop");
      /* Block until input arrives on one or more active sockets. */
      read_fd_set = active_fd_set;
      if (select (FD_SETSIZE, &read_fd_set, NULL, NULL, NULL) < 0)
        {
          my_str("select");
          exit (0);
        }

    
      if (FD_ISSET (sock, &read_fd_set))
          {
                /* Connection request on original socket. */
                my_str("new connection");
                int new;
                size = sizeof (clientname);
                new = accept(sock, (struct sockaddr *) &clientname, &size);
                if (new < 0)
                  {
                    my_str("accept");
                    exit (0);
                  }
                buffer = (char*)malloc(sizeof(char) * MAXMSG);
                mybzero(buffer,MAXMSG);
                nbytes = read(new, buffer, MAXMSG - 1);
                if(nbytes < 0)
                {
                    my_str("Did not read username");
                }
                else
                {
                    buffer[nbytes] = '\0';
                    struct clientList* client = (struct clientList*)malloc(sizeof(struct clientList));
                    client->fd = new;
                    client->username = my_strdup(buffer);
                    add_elem(client, &users);
                    my_str("got username: ");
                    my_str(buffer);
                    my_str("\n");
                    free(buffer);
                }
                FD_SET (new, &active_fd_set);
            }
        for(i = 0; i < count_s_nodes(users); ++i)
        {
            if(FD_ISSET (((struct clientList*)elem_at(users,i))->fd, &read_fd_set))
              {
		        my_str("Got into else\n");
                /* Data arriving on an already-connected socket. */
                buffer = (char*)malloc(sizeof(char) * MAXMSG);
                fullmsg = (char*)malloc(sizeof(char) * MAXMSG);
                myuser = (char*)malloc(sizeof(char) * MAXMSG);
                mybzero(buffer,MAXMSG);
                mybzero(myuser,MAXMSG);
			    nbytes = read (i, buffer, MAXMSG - 1);
			    if (nbytes < 0)
			    {
			      /* Read error. */
			      my_str("read");
			      close(i);
			      FD_CLR(i, &active_fd_set);
			    }
                }
			    else if (my_strcmp(buffer,"/exit") == 0)
			    {/* End-of-file. */
			         my_str("got here");
			        close(i);
			        FD_CLR(i, &active_fd_set);
			        free(buffer);
			    }
			    else
			    {
			      /* Data read. */
                  buffer[nbytes] = '\0';
			      my_str("Server: got message: ");
			      my_str(buffer);
			      my_str("\n");
                  my_int(i);
                  struct clientList *myuser = (struct clientList*)elem_at(users, i);
                  my_str("declared myuser\n");
                 // my_str(myuser->username);
                  my_str("\n");
                  fullmsg = my_strconcat(myuser->username, ": ");
                  fullmsg = my_strconcat(fullmsg, buffer);
                  write(i,fullmsg,my_strlen(fullmsg) + 1);
                  /*for(k = 0; k < FD_SETSIZE; k++)
                  {
                      if(FD_ISSET (k, &active_fd_set))
                      {
                          my_int(k);
                          my_str("past ifFDISSET\n");
                          my_int(my_strlen(buffer));
                          my_str("\n");
                          my_str(buffer);
                          my_str("\n");
                         if((write(k, buffer, my_strlen(buffer))) < 0)
                          {
                              my_str("error writing to client");
                          }
                      }
                  }*/
                }
              }
          }
       // my_str("bottom of while");
    }
  //my_str("jailbreak");

