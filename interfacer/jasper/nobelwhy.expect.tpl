#!/usr/bin/expect -f

set timeout 40
set server %server%
set path %path%
set p %prop%

spawn ssh $server
expect "*bash-4.2$ "
send "cd $path\r"

expect "*$ "
send "jg -no_gui -fpv why.tcl > why.result\r"

expect "*bash-4.2$ "
send "exit\r"
close



