import ila


ACTION_WRITE = ila.const(1,8)
ACTION_CLEAR = ila.const(0,8)


GOOD_IMAGE = ila.const(1,8)
BAD_IMAGE  = ila.const(2,8)
ImgAddr    = ila.const(3,8)

#------------- DRIVER -------------------------------

Driver = ila.Abstraction('Driver')
DriverPC        = Driver.reg('DriverPC', 8)

ResetCMDAddress = Driver.reg('ResetCMDAddress', 8)
SMImageAddr     = Driver.reg('SMImageAddr', 8)
LoadFWAddress   = Driver.reg('LoadFWAddress', 8)
ProcIntBitAddress = Driver.reg('ProcIntBitAddress', 8)

non_det_func = Driver.fun('_non_det_',1,[])
non_det      = ila.appfun(non_det_func) == ila.const(0,1)


Driver.set_init('DriverPC', ila.const(0,8) )

SendResetDevice = Driver.inst('SendResetDevice', DriverPC == 0 ) # MMIO
SendResetDevice.set_next('ResetCMDAddress' , ACTION_WRITE )
SendResetDevice.set_next('DriverPC', DriverPC + 1 )

WriteSMImage = Driver.inst('WriteSMImage', DriverPC == 1)
WriteSMImage.set_next('SMImageAddr', ila.ite( non_det, GOOD_IMAGE, BAD_IMAGE  ) )
WriteSMImage.set_next('DriverPC', DriverPC + 1 )

SendLoadFw = Driver.inst('SendLoadFw',  DriverPC == 2)
SendLoadFw.set_next('LoadFWAddress',  ACTION_WRITE ) 
SendLoadFw.set_next('DriverPC', DriverPC + 1 )

ReceiveReportSts = Driver.inst('ReceiveReportSts', (DriverPC == 3) & (ProcIntBitAddress == ACTION_WRITE )  )
ReceiveReportSts.set_next('ProcIntBitAddress', ACTION_CLEAR ) 
ReceiveReportSts.set_next('DriverPC', DriverPC + 1 )


#------------- DEV -------------------------------


Device  = ila.Abstraction('Device')
DevIdx1 = Device.reg('DevIdx1', 8)
DevIdx2 = Device.reg('DevIdx2', 8)
DevPC   = Device.reg('DevPC', 8)

LoadFWAddress = Device.reg('LoadFWAddress', 8)
SMImageAddr   = Device.reg('SMImageAddr', 8)
IMImageAddr   = Device.reg('IMImageAddr', 8)
AuthReqAddress      = Device.reg('AuthReqAddress', 8)
RecvAuthRespAddress = Device.reg('RecvAuthRespAddress', 8)
DeviceStsAddress    = Device.reg('DeviceStsAddress', 8)
ProcIntBitAddress   = Device.reg('ProcIntBitAddress', 8)
ResetCMDAddress     = Device.reg('ResetCMDAddress', 8)
CEStsAddress        = Device.reg('CEStsAddress', 8)


Device.set_init('DevIdx1', ila.const(0,8) )
Device.set_init('DevIdx2', ila.const(0,8) )


ReceiveReset = Device.inst('ReceiveReset', ResetCMDAddress == ACTION_WRITE ) # MMIO
ReceiveReset.set_next('ResetCMDAddress' , ACTION_CLEAR )
ReceiveReset.set_next('DevIdx1', ila.const(0,8) )
ReceiveReset.set_next('DevIdx2', ila.const(0,8) )

ReceiveLoadFw = Device.inst('ReceiveLoadFw', LoadFWAddress == ACTION_WRITE)
ReceiveLoadFw.set_next('LoadFWAddress', ACTION_CLEAR )
ReceiveLoadFw.set_next('DevIdx1', ila.const(1,8) )

CopyFwFromSMtoIM = Device.inst('CopyFwFromSMtoIM', DevIdx1 == 1)
CopyFwFromSMtoIM.set_next('IMImageAddr', SMImageAddr )
CopyFwFromSMtoIM.set_next('DevIdx1', ila.const(2,8) )

SendAuthReq = Device.inst('SendAuthReq', DevIdx1 == 2)
SendAuthReq.set_next('AuthReqAddress', ACTION_WRITE )
SendAuthReq.set_next('DevIdx1', ila.const(3,8) )


# >>>>  CE
# <<<<  CE

ReceiveAuthResp = Device.inst('ReceiveAuthResp', RecvAuthRespAddress == ACTION_WRITE)
ReceiveAuthResp.set_next('RecvAuthRespAddress', ACTION_CLEAR )
ReceiveAuthResp.set_next('DevIdx2', ila.const(4,8) )

ReadCheckSts = Device.inst('ReadCheckSts', DevIdx2 == 4 )
ReadCheckSts.set_next('DeviceStsAddress', CEStsAddress )
ReadCheckSts.set_next('DevIdx2', ila.const(5,8) )

SendReportSts = Device.inst('SendReportSts', DevIdx2 == 5 )
SendReportSts.set_next('ProcIntBitAddress',  ACTION_WRITE )
SendReportSts.set_next('DevIdx2', ila.const(6,8) )

JumpToIM = Device.inst('JumpToIM', DevIdx2 == 6 )
JumpToIM.set_next('DevPC', ila.ite(DeviceStsAddress == GOOD_IMAGE, ImgAddr, ila.const(0,8)) )
JumpToIM.set_next('DevIdx2', ila.const(7,8) )


#------------- CE -------------------------------


CE  = ila.Abstraction('CE')
CEIdx = CE.reg('CEIdx', 8)

CE.set_init('CEIdx', ila.const(0,8) )

AuthReqAddress      = CE.reg('AuthReqAddress', 8)
CEStsAddress        = CE.reg('CEStsAddress', 8)
RecvAuthRespAddress = CE.reg('RecvAuthRespAddress', 8)
IMImageAddr         = CE.reg('IMImageAddr', 8)

ReceiveAuthReq = CE.inst('ReceiveAuthReq', AuthReqAddress == ACTION_WRITE)
ReceiveAuthReq.set_next('AuthReqAddress',  ACTION_CLEAR )
ReceiveAuthReq.set_next('CEIdx', ila.const(1,8) )

VerifyFwSignatureInIM = CE.inst('VerifyFwSignatureInIM', CEIdx == 1)
VerifyFwSignatureInIM.set_next('CEStsAddress', IMImageAddr )
VerifyFwSignatureInIM.set_next('CEIdx', ila.const(2,8)  )

SendAuthRespSts = CE.inst('SendAuthRespSts', CEIdx == 2)
SendAuthRespSts.set_next('RecvAuthRespAddress' , ACTION_WRITE )
SendAuthRespSts.set_next('CEIdx', ila.const(3,8)  )


# ----------------- DUMMY -----------------------------
# Dummy global state for init

dummy = ila.Abstraction("dummy")

dummy.reg('ResetCMDAddress', 8)
dummy.reg('SMImageAddr', 8)
dummy.reg('IMImageAddr', 8)
dummy.reg('LoadFWAddress', 8)
dummy.reg('ProcIntBitAddress', 8)
dummy.reg('AuthReqAddress', 8)
dummy.reg('RecvAuthRespAddress', 8)
dummy.reg('DeviceStsAddress', 8)
dummy.reg('CEStsAddress', 8)

dummy.set_init('ResetCMDAddress', ila.const(0,8))
dummy.set_init('SMImageAddr', ila.const(0,8))
dummy.set_init('IMImageAddr', ila.const(0,8))
dummy.set_init('LoadFWAddress', ila.const(0,8))
dummy.set_init('ProcIntBitAddress', ila.const(0,8))
dummy.set_init('AuthReqAddress', ila.const(0,8))
dummy.set_init('RecvAuthRespAddress', ila.const(0,8))
dummy.set_init('DeviceStsAddress', ila.const(0,8))
dummy.set_init('CEStsAddress', ila.const(0,8))

# ------------------------------------------------------


SC = ila.MCM_SC()

ProcInst = ['SendResetDevice', 'WriteSMImage', 'SendLoadFw', 'ReceiveReportSts' ]
DevInst =  ['ReceiveReset', 'ReceiveLoadFw', 'CopyFwFromSMtoIM', 'SendAuthReq', 'ReceiveAuthResp', 'ReadCheckSts', 'SendReportSts', 'JumpToIM' ]
CEInst =   ['ReceiveAuthReq', 'VerifyFwSignatureInIM', 'SendAuthRespSts']

unroller = ila.newMcmUnroller(
    nTh     = [1,1,1] ,
    entity  = [Driver, Device, CE] , 
    program = [ ProcInst, DevInst, CEInst ] , 
    dummyInit = dummy,
    mm      = SC )

ila.enablelog("mcmUnroller.print")
ila.enablelog("mcmUnroller.icheck")
ila.enablelog("mcmUnroller.check")
ila.setloglevel(3,"")

unroller.unroll()
unroller.addPropertyOnEnding( (DevPC == ImgAddr) & ( IMImageAddr == BAD_IMAGE ) )
unroller.finalizePiFun()
print unroller.pushInstConstraintAndCheck()
unroller.connectByAnd()
print unroller.check()
#unroller.printModel()
