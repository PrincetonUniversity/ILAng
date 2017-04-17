# iterate properties of control state vars

assume -disable {::init - consistent RAM access}
assume -disable {::arch equal - data}

prove -property {{<embedded>::bound}}
prove -property {{<embedded>::eq - arg_1_TREADY}}
prove -property {{<embedded>::eq - arg_0_TVALID}}
prove -property {{<embedded>::eq - RAM_x}}
prove -property {{<embedded>::eq - RAM_y}} 
prove -property {{<embedded>::eq - RAM_w}}
prove -property {{<embedded>::eq - cur_pix}}

assume -enable {::init - consistent RAM access}
assume -enable {::arch equal - data}
