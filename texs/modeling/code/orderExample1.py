proc = ila.Abstraction('processor')
......
proc.fetch_exprs = ila.concat( [INSTA, INSTB] )

instA_decode = ( INSTA[5:0] == opcode1 )
instB_decode = ( INSTB[5:0] == opcode2 )
proc.decode_exprs = [ instA_decode, instB_decode ]
......
