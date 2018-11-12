#include<stdio.h>

 int R[100],i,k,Z[100]={0},n1,D1[100],D2[100],flag,count;
int main()
{

  int D[20],d[10],r[10];//Dividend,divisor ,intermediate exor result and 
  int n,m ;//size

  printf("Enter the size of Dividend\n");
  scanf("%d",&n);

  n1=n;
  
  printf("Enter the size of divisor\n");
  scanf("%d",&m);

printf("Enter the data\n");
  for(i=0;i<n;i++)
   scanf("%1d",&D[i]);

for(i=0;i<n;i++)
  D1[i]=D[i];//Taking a copy of Dividend

printf("Enter the divisor\n");
  for(i=0;i<m;i++)
   scanf("%1d",&d[i]);

printf("The data Entered is :\n");
  for(i=0;i<n;i++)
   printf("%d",D[i]);

printf("\n");
for(i=1;i<=m-1;i++)
   D[n++]=0;

printf("The data after appeneding 0 's  is :\n");
  for(i=0;i<n;i++)
   printf("%d",D[i]);

printf("\n");
CRC(D,d,n,m);

printf("\nEnter the data you are sending\n");
for(i=0;i<n;i++)
  scanf("%1d",&D2[i]);//data to be sent

CRCcheck(D2,d,n,m);
return 0;
}

void CRC(int D[],int d[],int n ,int m)
{
 int i,j=m,p=m;
 //Creating a all zero array to exor for another case
 for(i=0;i<j;i++)
   R[i]=D[i];

 while(j<n)
{
    if(R[0]==1)
     {
      exor(R,d,p);
      R[k++]=D[j];
      p=k;
   printf("\n");
     for(i=0;i<k;i++)
  printf("%d",R[i]);
     }
    else
     {
      exor(R,Z,k);
      R[k++]=D[j];
      p=k;
     }
  j++;
}

if(R[0]==1)
     {
      exor(R,d,p);
      
   printf("\n");
     for(i=0;i<k;i++)
  printf("%d",R[i]);
     }
    else
     {
      exor(R,Z,k);
      
     }

printf("\n");  

printf("Remainder is :");
for(i=0;i<k;i++)
  printf("%d",R[i]);//remainder

for(i=0;i<k;i++)
 {
  printf("yesin\n");
  D1[n1]=R[i];
 printf("%d\n",D[n1]);
  n1++;  
 }

printf("n1:%d\n",n1);
printf("The encoded data is : \n");
for(i=0;i<n1;i++)
  printf("%d",D1[i]);
}

void exor(int A[],int B[],int p)
{
  printf("\nEntered\n");
   k=0;
   static int r[100];
   printf("\nsize : %d\n",p);

for(i=0;i<p;i++)
  printf("%d",B[i]);
printf("\n");
   for(i=1;i<p;i++)
    {
     if(A[i]==B[i])
       {
        r[i-1]=0;
        k++;
       }
     else
      {
        r[i-1]=1;
        k++;
      }  
    }

 for(i=0;i<k;i++)
  {
   printf("%d",r[i]);
   R[i]=r[i];
  }
}

void CRCcheck(int D[],int d[],int n ,int m)
{
 int i,j=m,p=m;
 //Creating a all zero array to exor for another case
 
 for(i=0;i<j;i++)
   R[i]=D2[i];

 while(j<n)
{
    if(R[0]==1)
     {
      exor(R,d,p);
      R[k++]=D[j];
      p=k;
   printf("\n");
     for(i=0;i<k;i++)
  printf("%d",R[i]);
     }
    else
     {
      exor(R,Z,k);
      R[k++]=D[j];
      p=k;
     }
  j++;
}

if(R[0]==1)
     {
      exor(R,d,p);
      
   printf("\n");
     for(i=0;i<k;i++)
  printf("%d",R[i]);
     }
    else
     {
      exor(R,Z,k);
     }

printf("\n");  

printf("Remainder is :");
for(i=0;i<k;i++)
  printf("%d",R[i]);//remainder

for(i=0;i<k;i++)
{
 flag=0;
  if(R[i]==Z[i])
  {
    flag=1;
    count++;
  }
}

if(flag==1 && count==k)
  printf("\nData sent is not corrupted!\n");
else
  printf("\nCorrupted Data is sent!\n");

for(i=0;i<k;i++)
 {
  //printf("yesin\n");
  D1[n1]=R[i];
 //printf("%d\n",D[n1]);
  n1++;  
 }
}
