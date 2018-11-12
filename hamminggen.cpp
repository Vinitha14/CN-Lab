#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

using namespace std;
int a,b,c[30],d,r=0,d1;
int data[100],original[100];
void paritycheck();
int main()
{
    //Max bits here i kept is 30

    cout<<" Enter the No of Data Bits you want to Enter : ";
    cin>>a;
 
    while (a+r+1>pow(2,r))
    {        r++;    }
    cout<<"No of data bits to be added "<<r<<" : Total Bits :"<<a+r<<endl;
 
    cout<<" Enter the Data Bits One by One :"<<endl;
 
    for (int i=1;i<=a;++i)
        cin>>c[i];
  
    cout<<endl<<" Data bits entered : ";
 
    for (int i=1;i<=a;++i)
        cout<<c[i]<<" ";
  
    cout<<endl;
 
    
    d=0;
    d1=1;
 
    for (int i=1;i<=a+r;++i)
    {        if ((i)==pow(2,d))
        {            data[i]=0;
            ++d;
        }
        else
        {            data[i]=c[d1];
            ++d1;
        }
    }
 
    cout<<" Data Bits are Encoded with Piraty bits(0): ";
 
    for (int i=1;i<=a+r;++i)
        cout<<data[i]<<" ";
  

 paritycheck();



   
    
return 0;
}




void  paritycheck( )
{

d1=0;    
 int min,max=0,piraty,s,j;
 
    /*Parity Bit Calculation */
    for (int i=1;i<=a+r;i=pow(2,d1))
    {        ++d1;  
            piraty=0;
              j=i;
       // s=i;
        min=1;
        max=i;
        for ( j;j<=a+r;) 
        { for ( s=j;max>=min && s<=a+r;++min,++s)
            {   if (data[s]==1)
                    piraty++;
            }
            j=s+i;
            min=1;
        }
        if (piraty%2==0) // Even Parity
        {            data[i]=0;        }
        else {            data[i]=1;        }
    }
 
    cout<<endl<<" Hamming codeword bits for even piraty are : ";
 
    for (int i=1;i<=a+r;++i)
        cout<<data[i]<<" ";
    
    for (int i=1;i<=a+r;++i)
        original[i]=data[i];
    cout<<endl;
}
