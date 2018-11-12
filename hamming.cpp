#include<iostream>
#include<cmath>
using namespace std;

int main()
{
int A[7],B[7],i,n=0;
cout<<"The (7,4) representation\n";
cout<<"Enter the given data(4 bits)\n";

//initializing parity bits
for(i=1;i<=7;i++)
A[i]=-1;			//giving the parity bits a default value

for(i=1;i<=7;i++)
{
if(i!=pow(2,n))
cin>>A[i];			//reading the data bits value from user
else
n++;
}

for(i=1;i<=7;i++)
cout<<A[i]<<"  ";

cout<<"Enter whether even or odd parity-0/1\n";
int set;
cin>>set;

if(set==0)			//Even parity
{
A[1]=A[3]^A[5]^A[7];//parity 1
A[2]=A[3]^A[6]^A[7];//parity 2
A[4]=A[5]^A[6]^A[7];//parity 4
}

else				//Odd parity
{
A[1]=!(A[3]^A[5]^A[7]);//parity 1
A[2]=!(A[3]^A[6]^A[7]);//parity 2
A[4]=!(A[5]^A[6]^A[7]);//parity 4
}

for(i=1;i<=7;i++)
cout<<A[i]<<"  ";		//Displaying all 7 bits

cout<<"\nEnter the data with 1-bit error\n";		//For error correction
for(i=1;i<=7;i++)
cin>>B[i];

int E1,E2,E3;
if(set==0)			//Even parity
{
E1=B[1]^B[3]^B[5]^B[7];
E2=B[2]^B[3]^B[6]^B[7];
E3=B[4]^B[5]^B[6]^B[7];
}

else				//Odd parity
{
E1=!(B[1]^B[3]^B[5]^B[7]);
E2=!(B[2]^B[3]^B[6]^B[7]);
E3=!(B[4]^B[5]^B[6]^B[7]);
}

cout<<"error bit\n"<<E3<<E2<<E1;
int n1=E3*pow(2,2)+E2*pow(2,1)+E1*pow(2,0);		//Finding the position of error bit
cout<<endl<<"in decimal: "<<n1;

B[n1]=!B[n1];			//Error correction is done

cout<<"\nafter correction\n";
for(i=1;i<=7;i++)
cout<<B[i]<<"  ";		//Correct data is displayed after correction

return(0);
}
