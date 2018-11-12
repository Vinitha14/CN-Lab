set ns [new Simulator]

set nf [open out2.nam w]
$ns namtrace-all $nf
set f [open out2.tr w]
$ns trace-all $f

proc finish {} {
global ns f nf
$ns flush-trace 
close $f 
close $nf
exec nam out2.nam &
exit 0
}

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]

$ns duplex-link $n0 $n1 1Mb 10ms DropTail
$ns duplex-link $n0 $n2 1Mb 10ms DropTail
$ns duplex-link $n0 $n3 1Mb 10ms DropTail

#Give node position (for NAM)
$ns duplex-link-op $n0 $n2 orient right-down
$ns duplex-link-op $n0 $n3 orient right-up
$ns duplex-link-op $n0 $n1 orient right


set tcp0 [new Agent/TCP]
$ns attach-agent $n1 $tcp0
set sink [new Agent/TCPSink]
$ns attach-agent $n3 $sink
$ns connect $tcp0 $sink

set ftp [new Application/FTP]
$ftp attach-agent $tcp0
$ftp set type_ FTP

set tcp1 [new Agent/TCP]
$ns attach-agent $n2 $tcp1
set sink [new Agent/TCPSink]
$ns attach-agent $n3 $sink
$ns connect $tcp1 $sink

set ftp1 [new Application/FTP]
$ftp1 attach-agent $tcp1
$ftp1 set type_ FTP

$ns at 0.0 "$ftp start"
$ns at 1.0 "$ftp stop"
$ns at 1.5 "$ftp1 start"
$ns at 2.0 "$ftp1 stop"
$ns at 2.0 "finish"
$ns run
