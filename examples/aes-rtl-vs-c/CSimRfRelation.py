from rfmaplib import VarMap, ILA, CArray



def buildRefMap(Cinfo, refSimSp, PCstate):
	
	pcstate = PCstate( {'@_ILA_aes_top_0':0, 
						'@_ILA_aes_step_1':1,
						'@_ILA_aes_step_2':2,
						'@_ILA_aes_step_3':3,
						'@_ILA_aes_end':0} )
	
	aesVarMap = VarMap( {
		'cmd'	   : 'cmd',
		'cmdaddr'  : 'cmdaddr',
		'cmddata'  : 'cmddata',
		'aes_state': pcstate, 
		'aes_addr' : 'mmport.PlainTextPointer' , 
		'aes_len'  : 'mmport.EncryptLength',
		'aes_ctr'  : {'mmport.EncryptCtr[0]':(31, 0), 'mmport.EncryptCtr[1]':(63,32),
					  'mmport.EncryptCtr[2]':(95,64), 'mmport.EncryptCtr[3]':(127,96) } ,
		'aes_key0' : {'mmport.EncryptKey[0]':(31, 0), 'mmport.EncryptKey[1]':(63,32),
					  'mmport.EncryptKey[2]':(95,64), 'mmport.EncryptKey[3]':(127,96) } ,
		'XRAM'     : CArray('buffer')
		} )
	#computeAesMap = aesVarMap.copy()
	computeAesMap = VarMap({})
	computeAesMap['rd_data']  = {'plaintext[0]':(31, 0), 'plaintext[1]':(63,32),
					  			 'plaintext[2]':(95,64), 'plaintext[3]':(127,96) }
	computeAesMap['enc_data'] = {'final_result[0]':(31, 0), 'final_result[1]':(63,32),
					  			 'final_result[2]':(95,64), 'final_result[3]':(127,96) }
	computeAesMap['uaes_ctr'] = {'AES_ctr[0]':(31, 0), 'AES_ctr[1]':(63,32),
					  			 'AES_ctr[2]':(95,64), 'AES_ctr[3]':(127,96) }
	computeAesMap['blk_cnt']  = 'byteCount'
	#computeAesMap.extraControl( {'i':'byteCount/16'} )
	
	
	refSimSp.setCondition(
		level = 'aes',
		instDecode = ILA.AnyInstruction , # any instruction {}
		CInstSet = Cinfo.Sep(begin = '@_ILA_aes_top_0', end = Cinfo.ANY) , 
		varMap = [ ('@_ILA_aes_top_0',aesVarMap) ]
	) 
	
	refSimSp.setCondition(
		level = 'aes_compute',
		instDecode = {'aes_state':1},
		CInstSet = Cinfo.Sep(begin = '@_ILA_aes_step_1' , end = Cinfo.ANY) , 
		varMap = [ ('@_ILA_aes_top_0',aesVarMap) , ('@_ILA_aes_step_1', computeAesMap) ]
	)
	
	refSimSp.setCondition(
		level = 'aes_compute',
		instDecode = {'aes_state':2},
		CInstSet = Cinfo.Sep(begin = '@_ILA_aes_step_2' , end = Cinfo.ANY) , 
		varMap = [ ('@_ILA_aes_top_0',aesVarMap) , ('@_ILA_aes_step_2', computeAesMap) ]
	)
	
	refSimSp.setCondition(
		level = 'aes_compute',
		instDecode = {'aes_state':3},
		CInstSet = Cinfo.Sep(begin = '@_ILA_aes_step_3' , end = Cinfo.ANY) , 
		varMap = [ ('@_ILA_aes_top_0',aesVarMap) , ('@_ILA_aes_step_3', computeAesMap) ]
	)
	

	
