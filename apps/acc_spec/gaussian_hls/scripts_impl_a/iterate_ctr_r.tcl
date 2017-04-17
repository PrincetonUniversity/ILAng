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
prove -property {{<embedded>::eq - RAM_0 unchanged}}
prove -property {{<embedded>::eq - RAM_1 unchanged}}
prove -property {{<embedded>::eq - RAM_2 unchanged}}
prove -property {{<embedded>::eq - RAM_3 unchanged}}
prove -property {{<embedded>::eq - RAM_4 unchanged}}
prove -property {{<embedded>::eq - RAM_5 unchanged}}
prove -property {{<embedded>::eq - RAM_6 unchanged}}
prove -property {{<embedded>::eq - RAM_7 unchanged}}

assume -enable {::init - consistent RAM access}
assume -enable {::arch equal - data}
