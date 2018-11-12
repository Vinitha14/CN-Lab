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
char message[100]="This message is sent using UDP protocol: first message\n";
char client_message[100];
int len;

sockfd=socket(AF_INET,SOCK_DGRAM,0);

struct sockaddr_in server_addr;
server_addr.sin_family = AF_INET;
server_addr.sin_port = htons(port);
server_addr.sin_addr.s_addr = INADDR_ANY;
printf("hello\n");
sendto(sockfd,message,strlen(message),0,(const struct sockaddr *) &server_addr,sizeof(server_addr));

recvfrom(sockfd,client_message,sizeof(client_message),0, (struct sockaddr *) &server_addr,&len);
printf("what is this?\n");
printf("%s\n",client_message);

close(sockfd);

return(0);
}

