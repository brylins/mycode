#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <thread>
#include <iostream>
#include <signal.h>


#define N 1000

typedef struct sockaddr SA;
bool flagOne = false;
char bufferOne[N];

bool flagTwo = false;
char bufferTwo[N];

int func(int port, int threadId)
{
   int ret = 0;
   int listenfd, connfd;
   struct sockaddr_in server_addr;
   struct sigaction sa;
   sa.sa_handler = SIG_IGN;
   sigaction(SIGPIPE, &sa, 0);
   
   if((listenfd = socket(PF_INET, SOCK_STREAM, 0)) < 0)
   {
      fprintf(stderr, "fail to socket : %s\n", strerror(errno));
      exit(-1);
   }

   memset(&server_addr, 0, sizeof(server_addr));
   server_addr.sin_family = PF_INET;
   server_addr.sin_port = htons(port);
   server_addr.sin_addr.s_addr = INADDR_ANY;   
   
   if(bind(listenfd, (SA *)&server_addr, sizeof(server_addr)) < 0)
   {
       perror("fail to bind");
       exit(-1);
   }

    listen(listenfd, 5);
    if((connfd = accept(listenfd, NULL, NULL)) < 0)
    {
        perror("fail to accept");
        //break;
    }

    while (1)
    {

	if(1 == threadId)
	{
		ret = recv(connfd, bufferOne, N, 0);
		if(ret)
		{
		    printf("recvd from client\n");
		    flagOne = true;
		    printf("%s\n", bufferOne);
		}

                if(flagTwo)
                {
		    flagTwo = false;
	            send(connfd, "54321", 6, 0);
	            printf("sent to client:54321\n"); 
                }

	}
	else 
	{
	        ret = recv(connfd, bufferTwo, N, 0);
		if(ret)
		{
		    printf("recvd from client222222222\n");
		    flagTwo = true;
		    printf("%s\n", bufferTwo);
		}
		send(connfd, "54321", 6, 0);
		printf("sent to client:54321\n"); 
		//close(connfd);

	}
    }
   //close(connfd);
   return 0;
}

void output(int i)
{
    while(1)
    {
       std::cout << i << std::endl;
	sleep(1);
    }

}

int generatingdata(int num)
{
	flagTwo = true;
	sleep(3);

}

int main()
{
    

    std::thread threadOne(func, 50000, 1);
    threadOne.detach(); 
    std::thread threadTwo(generatingdata, 0);
    threadTwo.detach(); 
    
        
    getchar();
    return 0;
}
