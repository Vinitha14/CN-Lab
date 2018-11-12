#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main()
{
	int set=1,c=0,i, index;
	string beg="DTESTX";
	string end="DTEETX";
	string a[100],b[100],temp;

	while(set!=0)
	{
		index=0;
		cout<<"\nEnter 1 to enter frame, 0 to end\n";
		cin>>set;

		if(set==1)
		{
			cout<<"Enter the frame (# for end of frame)\n";
			i=-1;
			do
			{	
				i++;
				cin>>b[i];
				if(b[i]==beg || b[i]==end)
				{
					temp=b[i];
					b[i++]="ESC";
					b[i]=temp;
				}

			}while(b[i]!="#");
	
			index=i;
			a[c++]=beg;
			for(int j=0;j<index;j++)
			{
				a[c++]=b[j];
			}
			a[c++]=end;

		}		

	}

	cout<<"Final output is :\n";
	cout<<endl;
	for(int j=0;j<c;j++)
		cout<<a[j]<<"  ";
	return(0);
}




