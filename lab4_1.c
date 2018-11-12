#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

#include<sys/types.h>
#include<sys/socket.h>

#include<netinet/in.h>
#include<string.h>

#define port 8080

int main()
{
int sockfd,new_socket;

char server_message[100];
char message[100]="Second message\n";
int len;

sockfd=socket(AF_INET,SOCK_DGRAM,0);

struct sockaddr_in server_addr,client_addr;
server_addr.sin_family = AF_INET;
server_addr.sin_port = htons(8080);
server_addr.sin_addr.s_addr = INADDR_ANY;
	
//int addrlen = sizeof(server_addr);
bind(sockfd,(struct sockaddr *)&server_addr,sizeof(server_addr));
 
recvfrom(sockfd,server_message,sizeof(server_message),0, ( struct sockaddr *) &client_addr,&len);
printf("%s\n",server_message);

printf("Now, send the other message\n");
sendto(sockfd,message, strlen(message),0, (const struct sockaddr *) &client_addr,len);   
return(0);
}
