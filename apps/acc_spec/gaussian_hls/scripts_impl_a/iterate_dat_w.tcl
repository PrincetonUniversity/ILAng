# iterate properties of data state vars

assume -enable {::init - consistent RAM access}
assume -enable {::arch equal - data}

prove -property {{<embedded>::bound help 0} {<embedded>::bound help 1} {<embedded>::bound help 2} {<embedded>::bound help 3} {<embedded>::bound help 4} {<embedded>::bound help 5} {<embedded>::bound help 6} {<embedded>::bound help 7} {<embedded>::bound help 8} {<embedded>::bound help 9} {<embedded>::bound help 10} {<embedded>::bound help 11} {<embedded>::bound help 12} {<embedded>::bound help 13} {<embedded>::bound help 14} {<embedded>::bound help 15} <embedded>::bound}

prove -property {{<embedded>::eq - cur_pix}}
prove -property {{<embedded>::eq - RAM_0}}
prove -property {{<embedded>::eq - RAM_1}}
prove -property {{<embedded>::eq - RAM_2}}
prove -property {{<embedded>::eq - RAM_3}}
prove -property {{<embedded>::eq - RAM_4}}
prove -property {{<embedded>::eq - RAM_5}}
prove -property {{<embedded>::eq - RAM_6}}
prove -property {{<embedded>::eq - RAM_7}}
prove -property {{<embedded>::eq - stencil_0}}
prove -property {{<embedded>::eq - stencil_1}}
prove -property {{<embedded>::eq - stencil_2}}
prove -property {{<embedded>::eq - stencil_3}}
prove -property {{<embedded>::eq - stencil_4}}
prove -property {{<embedded>::eq - stencil_5}}
prove -property {{<embedded>::eq - stencil_6}}
prove -property {{<embedded>::eq - stencil_7}}
prove -property {{<embedded>::eq - arg_0_TDATA}}
