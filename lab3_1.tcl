set ns [new Simulator]
set nf [open get1.nam w]
$ns namtrace-all $nf
set nd [open  get1.tr  w]
$ns trace-all $nd

proc finish {} {
global ns nf nd
$ns flush-trace
close $nf
close $nd
exec nam get1.nam &
exit 0
}

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]

#$ns make-lan "$n0 $n1 $n2 $n3" 0.2Mb 40ms LL Queue/DropTail Mac/802_3
set lan0 [$ns newLan "$n0 $n1 $n2 $n3" 0.5Mb 40ms LL Queue/DropTail MAC/802_3 Channel]

set tcp0 [new Agent/TCP]
$ns attach-agent $n0 $tcp0
set sink [new Agent/TCPSink]
$ns attach-agent $n3 $sink
$ns connect $tcp0 $sink

set ftp0 [new Application/FTP]
$ftp0 attach-agent $tcp0

$ns at 0.5 "$ftp0 start"
$ns at 1.5 "$ftp0 stop"
$ns at 2.0 "finish"
$ns run

