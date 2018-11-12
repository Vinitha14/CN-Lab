set ns [new Simulator]

set nf [open out1.nam w]
$ns namtrace-all $nf
set f [open out1.tr w]
$ns trace-all $f

proc finish {} {
global ns f nf
$ns flush-trace 
close $f 
close $nf
exec nam out1.nam &
exit 0
}

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]

$ns duplex-link $n0 $n1 1Mb 10ms DropTail
$ns duplex-link $n0 $n2 1Mb 10ms DropTail
$ns duplex-link $n0 $n3 1Mb 10ms DropTail

set udp0 [new Agent/UDP]
$ns attach-agent $n1 $udp0

set null0 [new Agent/Null]
$ns attach-agent $n3 $null0

set cbr0 [new Application/Traffic/CBR]
$cbr0 attach-agent $udp0
$cbr0 set packetSize_ 500
$cbr0 set interval_ 0.005

set udp1 [new Agent/UDP]
$ns attach-agent $n2 $udp1

set cbr1 [new Application/Traffic/CBR]
$cbr1 attach-agent $udp1
$cbr1 set packetSize_ 500
$cbr1 set interval_ 0.005

$ns connect $udp1 $null0

$ns connect $udp0 $null0

$ns at 0.0 "$cbr0 start"
$ns at 1.0 "$cbr0 stop"
$ns at 1.5 "$cbr1 start"
$ns at 2.0 "$cbr1 stop"

$ns at 2.0 "finish"
$ns run
