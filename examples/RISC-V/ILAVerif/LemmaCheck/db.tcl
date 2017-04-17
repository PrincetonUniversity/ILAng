source do.tcl
source do.tcl
prove -bg -property {<embedded>::RocketFV._assert_84}
prove -stop
set_engine_mode {Ht B AB N AM}
prove -bg -property {<embedded>::RocketFV._assert_84 <embedded>::RocketFV._assert_49 <embedded>::RocketFV._assert_49:precondition1 <embedded>::RocketFV._assert_50 <embedded>::RocketFV._assert_50:precondition1}
provet- stop
provet -stop
prove -stop
prove -bg -property {<embedded>::RocketFV._assert_51 <embedded>::RocketFV._assert_51:precondition1}
prove -bg -property {<embedded>::RocketFV._assert_82 <embedded>::RocketFV._assert_82:precondition1 <embedded>::RocketFV._assert_83 <embedded>::RocketFV._assert_83:precondition1}
prove -stop
visualize -violation -property <embedded>::RocketFV._assert_82 -new_window
elaborate -clear
source do.tcl
prove -bg -property {<embedded>::RocketFV._assert_82}
visualize -violation -property <embedded>::RocketFV._assert_82 -new_window
elaborate -clear
source do.tcl
prove -bg -property {<embedded>::RocketFV._assert_82}
visualize -violation -property <embedded>::RocketFV._assert_82 -new_window
prove -bg -property {<embedded>::RocketFV._assert_83}
prove -stop
save -jdb /n/homeserver2/user2a/hongcez/Verif/pc_debug.jdb -capture_setup -capture_session_data
visualize -save -force -vcd /n/homeserver2/user2a/hongcez/Verif/pc_debug.vcd -window visualize:0
save -jdb /n/homeserver2/user2a/hongcez/Verif/pc_debug.jdb -capture_setup -capture_session_data
