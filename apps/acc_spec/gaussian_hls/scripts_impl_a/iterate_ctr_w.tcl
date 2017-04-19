# iterate properties of control state vars

assume -disable {::init - consistent RAM access}
assume -disable {::arch equal - data}

prove -property {{<embedded>::bound help 0} {<embedded>::bound help 1} {<embedded>::bound help 2} {<embedded>::bound help 3} {<embedded>::bound help 4} {<embedded>::bound help 5} {<embedded>::bound help 6} {<embedded>::bound help 7} {<embedded>::bound help 8} {<embedded>::bound help 9} {<embedded>::bound help 10} {<embedded>::bound help 11} {<embedded>::bound help 12} {<embedded>::bound help 13} {<embedded>::bound help 14} {<embedded>::bound help 15} <embedded>::bound}

prove -property {{<embedded>::eq - arg_1_TREADY}}
prove -property {{<embedded>::eq - arg_0_TVALID}}
prove -property {{<embedded>::eq - RAM_x}}
prove -property {{<embedded>::eq - RAM_y}} 
prove -property {{<embedded>::eq - RAM_w}}

