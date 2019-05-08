#!/usr/bin/expect -f

set timeout 40
set server %server%
set path %path%
set assume %assume%
set propname %properties%

spawn ssh $server
expect "*bash-4.2$ "
send "cd $path\r"

expect "*$ "
send "jg -no_gui\r"

expect "*% "
send "source do.tcl\r"

expect "*% "
send "source $assume \r"

expect "*% "

set index 0
set p [lindex $propname $index]
send "prove -property {<embedded>::wrapper.$p}\r"
expect {
  -re "(.)*proven\r\n\\\[\<embedded\>\\\] % " { 
        incr index
        if {$index == [llength $propname]} {
            send "exit\r"
            expect "*bash-4.2$ "
            send "exit\r"
            close
        }
        set p [lindex $propname $index]
        send "prove -property {<embedded>::wrapper.$p}\r"
        exp_continue
        }
       
  -re "(.)*cex\r\n\\\[\<embedded\>\\\] % " { 
        send "visualize -violation -property <embedded>::wrapper.$p\r"
        expect -re "(.)*cex\r\n\\\[\<embedded\>\\\] % "
        send "visualize -save -vcd cex.vcd -force\r"
        }
}



expect "*% "
send "save -dir $path/db/\r"

expect "*% "
send "exit\r"
expect "*bash-4.2$ "
send "exit\r"
close



