proc = ila.Abstraction('processor')

flag = proc.reg('flag', 1)
......
proc.fetch_exprs = ila.concat( [INSTA, INSTB] )

instA_decode = ( ( INSTA[5:0] == opcode1 ) )
instB_decode = ( ( INSTB[5:0] == opcode2 ) & (flag == 1) )
proc.decode_exprs = [ instA_decode, instB_decode ]
......

proc.set_init('flag', b0)
proc.set_next('flag', 
	ila.ite( instA_decode, b1, 
	ila.ite( instB_decode, b0, 
			 flag))
