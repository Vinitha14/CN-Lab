#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include<string.h>

int main()
{

	char str[100],text[100];
	int listen_fd, comm_fd;

	struct sockaddr_in servaddr;

	listen_fd = socket(AF_INET, SOCK_STREAM, 0);

	bzero( &servaddr, sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htons(INADDR_ANY);
	servaddr.sin_port = htons(22000);

	bind(listen_fd, (struct sockaddr *) &servaddr, sizeof(servaddr));

	listen(listen_fd, 10);

	comm_fd = accept(listen_fd, (struct sockaddr*) NULL, NULL);

	while(1)
	{

		bzero( str, 100);

		bzero( text, 100);

		read(comm_fd,str,100);

		if(strcmp(str,"q\n")==0)     //press q to exit

		break;

		printf("%s",str);
		
		fgets(text,100,stdin); /*stdin = 0 , for standard input */


		write(comm_fd, text, strlen(text)+1);

		if(strcmp(text,"q\n")==0)

		break;

	}
}
