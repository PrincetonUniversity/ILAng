# sample refinement mapping
import rfmaplib

def nextCycle(*args,**kargs):
    return rfmaplib.nextCycle(*args,**kargs)
def nextNCycle(*args,**kargs):
    return rfmaplib.nextNCycle(*args,**kargs)


#implement control (condition, assignment pair)

def buildRefMap( Vlg, ILA, refFinish,InstSeperator, ControlQueryCollector,regManager = rfmaplib.regManRef):

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