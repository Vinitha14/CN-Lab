BEGIN {
sent=0;
received=0;
}
{
  if($1=="+")
   {
    sent++;
   }
  else if($1=="r")
   {
     received++;
   }
 
}
END {
 printf " Number of packets sent:%d",sent;
 printf "\n Number of packets received:%d",received;
 printf "\n Packet Delivery Ratio:%.2f\n",(sent/received)*100;

}





#command:
#gawk -f acknow.awk out.tr
