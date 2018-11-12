#include<stdio.h>
#include<stdlib.h>

int main()
 {
 int n,k,a[30],i=0,j=0,count=0,b[30];
 printf("enter the no of packets sending \n");
 scanf("%d",&n);
 printf("enter the packets \n");
 for(i=0;i<n;i++)
 scanf("%d",&a[i]);
 printf("enter the packet to be dropped \n");
 scanf("%d",&k);
  i=0;
 int g;
if(n%k==0)
g=(n/k);
else if(n%k!=0)
g=(n/k)+1;
 while(i<n+g)
 {
  b[i]=a[j];
  i++;
   j++;
  count++;
  if(count==k-1)
    {
    b[i]=a[j];
    i++;
    b[i]=a[j];
    i++;
    j++; 
    count=1;
   }
 }

for(i=0;i<n+g;i++)
  printf("%d ",b[i]);
int l=0;
for(i=0;i<n+g;i++)
 { 
  if(b[i]==b[i+1])
   l++;
 } 
 printf("the no of retransmissions are %d",l);
 return(0);
}
