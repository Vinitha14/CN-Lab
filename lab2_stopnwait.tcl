set ns [new Simulator]

set nf [open out3.nam w]
$ns namtrace-all $nf
set f [open out3.tr w]
$ns trace-all $f

proc finish {} {
global ns f nf
$ns flush-trace 
close $f 
close $nf
exec nam out3.nam &
exit 0
}

set n0 [$ns node]
set n1 [$ns node]

$ns duplex-link $n0 $n1 1Mb 100ms DropTail

set tcp0 [new Agent/TCP]
$tcp0 set window_ 1
$tcp0 set maxcwnd_ 1 
$ns attach-agent $n0 $tcp0
set sink [new Agent/TCPSink]
$ns attach-agent $n1 $sink
$ns connect $tcp0 $sink

set ftp [new Application/FTP]
$ftp attach-agent $tcp0
$ftp set type_ FTP

$ns at 0.1 "$ftp start"
$ns at 2.0 "$ns detach-agent $n0 $tcp0 ; $ns detach-agent $n1 $sink"
$ns at 2.0 "finish" 

$ns at 0.0 
$ns at 0.1 "$ns trace-annotate \"S0\"" 
$ns at 0.22 "$ns trace-annotate \"R0\"" 
$ns at 0.3 "$ns trace-annotate \"S1\"" 
$ns at 0.42 "$ns trace-annotate \"R1\"" 
$ns at 0.5 "$ns trace-annotate \"S2\"" 
$ns at 0.62 "$ns trace-annotate \"R2\"" 
$ns at 0.7 "$ns trace-annotate \"S3\"" 
$ns at 0.82 "$ns trace-annotate \"R3\"" 
$ns at 0.9 "$ns trace-annotate \"S4\"" 
$ns at 1.02 "$ns trace-annotate \"R4\"" 
$ns at 1.1 "$ns trace-annotate \"S5\"" 
$ns at 1.22 "$ns trace-annotate \"R5\"" 
$ns at 1.3 "$ns trace-annotate \"S6\"" 
$ns at 1.42 "$ns trace-annotate \"R6\"" 
$ns at 1.5 "$ns trace-annotate \"S7\"" 
$ns at 1.62 "$ns trace-annotate \"R7\"" 
$ns at 1.7 "$ns trace-annotate \"S8\"" 
$ns at 1.82 "$ns trace-annotate \"R8\"" 
$ns at 1.9 "$ns trace-annotate \"S9\"" 

$ns run
