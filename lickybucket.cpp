#include<iostream>
#include<stdlib.h>

using namespace std;

struct Queue
{
int rear,front;
int a[100];
}q;

int main()
{
int n;
int x,y;
int c;
c=0;
cout<<"\nEnter the buffer size:";
cin>>n;
q.rear=0;
q.front=0;
while(q.rear<=100)
{
cout<<"\nEnter the number of packets to be enqueued:";
cin>>x;
cout<<"\nEnter the number of packets to be dequeued:";
cin>>y;
int i=1;
int j=1;

while(i<=x)
{
if(c>=n)
{
cout<<"\nOverflow!Packets will be lost!";
break;
}
else
{
cout<<"\nEnter packet value:";
cin>>q.a[q.rear];
q.rear++;
c++;
}
i++;
}

while(j<=y)
{
if(q.rear==0)
{
cout<<"\nUnderflow!";
break;
}
else
{
cout<<"\nPacket dequeued is:"<<q.a[q.front];
q.front++;
c--;
}
j++;
}

cout<<"\nSize of current queue is:"<<q.rear-q.front;
//cout<<"\n"<<c;

}
return 0;
}

