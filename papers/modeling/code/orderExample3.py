Acc = ila.Abstraction('accelerator')
......
validCondition = uAccFinish == 1

uAcc   = Acc.micro_abstraction('uAcc', validCondition)
uState = uAcc.reg('uState', 2)

Start   = uState == 0 ; sStart = ila.const(0, 2) 
Wait    = uState == 1 ; sWait  = ila.const(1, 2) 
End     = uState == 2 ; sEnd   = ila.const(2, 2) 

uAcc.decode_exprs = [Start, Wait, End]

uAcc.set_next('uState', 
	ila.ite(Start, sWait, 
	ila.ite(Wait & CondWaitFor, sEnd,
	ila.ite(Wait &~CondWaitFor, sWait,
	uState))))
	
uAcc.set_next('uAccFinish', ila.ite(End, b1, b0))
