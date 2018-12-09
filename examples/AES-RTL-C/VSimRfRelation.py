# sample refinement mapping
import rfmaplib

def nextCycle(*args,**kargs):
    return rfmaplib.nextCycle(*args,**kargs)
def nextNCycle(*args,**kargs):
    return rfmaplib.nextNCycle(*args,**kargs)


#implement control (condition, assignment pair)

aesVarMap =  {
	'cmd'	   : 'cmd',
	'cmdaddr'  : 'cmdaddr',
	'cmddata'  : 'cmddata',
	'aes_state': 'pcstate', 
	'aes_addr' : 'mmport.PlainTextPointer' , 
	'aes_len'  : 'mmport.EncryptLength',
	'aes_ctr'  : {'mmport.EncryptCtr[0]':(31, 0), 'mmport.EncryptCtr[1]':(63,32),
				  'mmport.EncryptCtr[2]':(95,64), 'mmport.EncryptCtr[3]':(127,96) } ,
	'aes_key0' : {'mmport.EncryptKey[0]':(31, 0), 'mmport.EncryptKey[1]':(63,32),
				  'mmport.EncryptKey[2]':(95,64), 'mmport.EncryptKey[3]':(127,96) } ,
	'XRAM'     : ('buffer')
	} 
#computeAesMap = aesVarMap.copy()
computeAesMap = aesVarMap.copy()
computeAesMap['rd_data']  = {'plaintext[0]':(31, 0), 'plaintext[1]':(63,32),
				  			 'plaintext[2]':(95,64), 'plaintext[3]':(127,96) }
computeAesMap['enc_data'] = {'final_result[0]':(31, 0), 'final_result[1]':(63,32),
				  			 'final_result[2]':(95,64), 'final_result[3]':(127,96) }
computeAesMap['uaes_ctr'] = {'AES_ctr[0]':(31, 0), 'AES_ctr[1]':(63,32),
				  			 'AES_ctr[2]':(95,64), 'AES_ctr[3]':(127,96) }
computeAesMap['blk_cnt']  = 'byteCount'
#computeAesMap.extraControl( {'i':'byteCount/16'} )
	
	
def buildRefMap( Vlg, ILA, refFinish,InstSeperator, ControlQueryCollector,regManager = rfmaplib):

    refFinish.setMapping(ILAname = 'XRAM',  FullVlgName = 'simXramAes_top.oc8051_xram1.buff')

    #------------------------------
    # build Instruction finish cond
    #------------------------------
    refFinish.setCondition( 
        synTarget = ILA.is_fsm('aes'),          # synethesize target
        condition = nextCycle( 1 )   # condition
        )

    refFinish.setCondition( 
        synTarget = ILA.is_fsm('aes_compute') ,
        condition = ( Vlg.Sig('aes_state') == 2  ) | ( Vlg.Sig('simXramAes_top.xram_ack') )
        )


    """
    Or you can use:
    refSeparator.setC

    """
