#include<stdio.h>
#include<stdlib.h>

int main()
 {
 int n,k,a[30],i=0,j=0,count=0,b[30],w;
 printf("enter the no of packets sending \n");
 scanf("%d",&n);
 printf("enter the packets \n");
 for(i=0;i<n;i++)
 scanf("%d",&a[i]);
 printf("enter the packet to be dropped \n");
 scanf("%d",&k);
  printf("enter the window size \n");
  scanf("%d",&w);
 i=0;
int c;	//counting the number of retransmissions
c=0;

 while(i<n)
  {
  int l=0;
 
  if(count==k-1)
  {
   c++;
   count=0;
   for(l;l<w&&(i+l)<n;l++)
     {
      b[j]=a[i+l];
      j++;
      if(l!=0)
       count++;
      }
  }
else 
   {
  b[j]=a[i+l];
    i++;
    j++;
   count++;
   }
 }
for(int p=0;p<j;p++)
 printf("%d ",b[p]);
printf("\nNumber of windows retransmitted is %d: ",c);
return(0);
}
