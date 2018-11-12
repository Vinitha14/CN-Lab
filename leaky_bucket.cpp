#include<iostream>
using namespace std;

#define Qsize 10
int q[Qsize];
int front=-1,rear=-1;

void enqueue(int x)
{
	if(front==-1 && rear==-1)
	{
		q[++front]=x;
		rear=0;
	}

	else
	{
		q[++rear]=x;
		//rear++;
	}

}

void dequeue()
{
int x;
	if(front==0 && rear==0)
	{
		x=q[front];
		front=-1;
		rear=-1;
	}

	else if(front==-1 && rear==-1)
		cout<<"No data to dequeue\n";
	
	else
	{
	x=q[front];
	front++;
	}
	
}

void display()
{
int i;
for(i=front;i<=rear;i++)
cout<<q[i]<<"  ";
cout<<endl;
}

int get_count()
{
int count,i;
for(i=front;i<=rear;i++)
count++;
return count;
}

int main()
{
int choice,EQrate,DQrate,i,x,count;
cout<<"fix the DQrate\n";
cin>>DQrate;
	do
	{
		cout<<"\n1.incoming data\t2.outgoing data\n";
		cin>>choice;
		switch(choice)
		{
			case 1: cout<<"enter the EQrate: ";
					cin>>EQrate;
					count=get_count();
					if(Qsize-count<EQrate)
					cout<<"Congestion Problem\n";
					else
					{
					for(i=1;i<=EQrate;i++)
					{
						cout<<"\nData: ";
						cin>>x;
						enqueue(x);
					}
					display();
					}
					break;
			case 2: for(i=1;i<=DQrate;i++)
					dequeue();
					display();
					break;
		}

	}while(choice!=0);

return(0);
}


