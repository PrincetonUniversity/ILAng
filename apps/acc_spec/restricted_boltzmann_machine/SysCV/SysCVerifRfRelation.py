from SysCrfmaplib import VarMap, ILA, CArray, Bool, u8, u16, u32, SysCSignal, SysCFixedType, SysCUFixedType


# for top

def buildRefMap(Cinfo,refVerifSp,PCstate):
    return buildRefMapPredict(Cinfo,refVerifSp,PCstate)


TopVarMap = VarMap( {
    # input ports
    'rst'               : ('rst', SysCSignal(Bool) ),
    'rd_grant'          : ('rd_grant', SysCSignal(Bool) ),
    'wr_grant'          : ('wr_grant', SysCSignal(Bool) ),
    'data_in'           : ('data_in', SysCSignal(u32) ),

    'conf_done'         : ('conf_done', SysCSignal(Bool) ),
    'conf_num_hidden'   : ('conf_num_hidden', SysCSignal(u32) ),
    'conf_num_visible'  : ('conf_num_visible' , SysCSignal(u32) ),
    'conf_num_users'    : ('conf_num_users' , SysCSignal(u32) ),
    'conf_num_loops'    : ('conf_num_loops' , SysCSignal(u32) ),
    'conf_num_testusers': ('conf_num_testusers' , SysCSignal(u32) ),
    'conf_num_movies'   : ('conf_num_movies' , SysCSignal(u32) ),
    # internal states
    'num_visible':  ('num_visible', SysCSignal(u16)  ), #: 32768,)
    'num_testusers':('num_testusers', SysCSignal(u16) ),
    'num_hidden':   ('num_hidden',  SysCSignal(u16)  ),
    'num_loops':    ('num_loops',   SysCSignal(u16)  ),
    'num_movies':   ('num_movies',  SysCSignal(u16)  ),
    'num_users':    ('num_users',   SysCSignal(Bool) ),
    'init_done':    ('init_done',   SysCSignal(Bool) ), # 1

    'data':          CArray('data[0]', u8 ),
    'predict_result':CArray('predict_result[0]', u8 ),
    'data_out':     ('data_out',    SysCSignal(u32) ),
    'done':         ('done',        SysCSignal(Bool)),
    'init_done':    ('init_done',   SysCSignal(Bool)),
    #'rd_complete':  ('rd_complete',),
    #'rd_granted':('rd_granted',),
    'rd_index':     ('rd_index',    SysCSignal(u32) ),
    'rd_length':    ('rd_length',   SysCSignal(u32) ),
    'rd_request':   ('rd_request',  SysCSignal(Bool)),
    #'wr_complete':('wr_complete',),
    #'wr_granted':('wr_granted',),
    'wr_index':     ('wr_index',    SysCSignal(u32) ),
    'wr_length':    ('wr_length',   SysCSignal(u32) ),
    'wr_request':   ('wr_request',  SysCSignal(Bool)),
    })

def buildRefMapLoad(Cinfo, refVerifSp, PCstate):
    Load_map = TopVarMap.copy()
    Load_map.append( {
        'i'             : ( 'i' , u16 ),
        'rd_complete'   : PCstate( 'rd_complete' , {'@rd_complete0' : 0 , '@rd_complete1' : 1 })
        })
    refVerifSp.setCondition(
        name       = 'DMAload.load',
        instDecode = { 'rst' : 0, 'init_done' : 1, 'conf_done' : 1, 'GM.rd_request':1, 'GM.rd_granted':1, 'GM.rd_complete':0 },  # these are Cnames
        funcCall   = [ 'IMPL.load()', 'IMPL.load()' ],
        pcMap      = [ Cinfo.Sep(begin = '@load@START@0', end = '@load@END@0' ),
                       Cinfo.Sep(begin = '@load@START@1', end = '@load@END@1' )  ] , 
        varMap     = [ ('@load@START@0', Load_map),
                       ('@load@START@1', Load_map)   ]
        )


def buildRefMapStore(Cinfo, refVerifSp, PCstate):
    Store_map = TopVarMap.copy()
    Store_map.append( {
        'i'             : ( 'i' , u16 ),
        'wr_complete'   : PCstate( 'wr_complete' , {'@wr_complete0' : 0 , '@wr_complete1' : 1 })
        })
    refVerifSp.setCondition(
        name       = 'store.store',
        instDecode = { 'rst' : 0, 'init_done' : 1, 'conf_done' : 1, 'GM.wr_request':1, 'GM.wr_granted':1, 'GM.wr_complete':0 },  # these are Cnames
        funcCall   = [ 'IMPL.store()' ],
        pcMap      = [ Cinfo.Sep(begin = '@store@START', end = '@store@END' ) ] , 
        varMap     = [ ('@store@START', Store_map) ]
        )

def buildRefMapCompute(Cinfo, refVerifSp, PCstate):
    Control_map = TopVarMap.copy()
    Control_map.append( {
        'index'     : ('index', u16),
        'loop_count': ('loop_count', u16),
        'upc'       : PCstate('upc',  { '@upc@0' : 0, '@upc@1' : 1, '@upc@2' : 2, '@upc@3' : 3} ),
        'edges'     : CArray('edges', SysCFixedType(8,7)),
        'train_input_done'   : ('train_input_done',   SysCSignal(Bool) ),
        'predict_input_done' : ('predict_input_done', SysCSignal(Bool) ),
        'rd_complete'        : PCstate( 'rd_complete' , {'@rd_complete0' : 0 , '@rd_complete1' : 1 } )
        })

    refVerifSp.setCondition(
        name       = 'compute.StartRead', # I0
        instDecode = { 'rst' : 0, 'init_done' : 1, 'done' : 0 },  # these are Cnames
        funcCall   = [ 'IMPL.load()' ],
        pcMap      = [ Cinfo.Sep(begin = '@compute.StartRead@START', end = '@compute.StartRead@END' ) ] , 
        varMap     = [ ('@compute.StartRead@START', Control_map) ]
        )

    refVerifSp.setCondition(
        name       = 'compute.WaitReadComplete',  # I1
        instDecode = { 'rst' : 0, 'init_done' : 1, 'done' : 0 },  # these are Cnames
        funcCall   = [ 'IMPL.load()' ],
        pcMap      = [ Cinfo.Sep(begin = '@compute.WaitReadComplete@START', end = '@compute.WaitReadComplete@END' ) ] , 
        varMap     = [ ('@compute.WaitReadComplete@START', Control_map) ]
        )

    refVerifSp.setCondition(
        name       = 'compute.StartTrainOrPredict',  # I2
        instDecode = { 'rst' : 0, 'init_done' : 1, 'done' : 0 , 'GM.upc': 1 },   # these are Cnames
        funcCall   = [ 'IMPL.load()' ],
        pcMap      = [ Cinfo.Sep(begin = '@compute.StartTrainOrPredict@START', end = '@compute.StartTrainOrPredict@END' ) ] , 
        varMap     = [ ('@compute.StartTrainOrPredict@START', Control_map) ]
        )

    refVerifSp.setCondition(
        name       = 'compute.Finish',  # I3
        instDecode = { 'rst' : 0, 'init_done' : 1, 'done' : 0 , 'GM.upc': 3},   # these are Cnames
        funcCall   = [ 'IMPL.load()' ],
        pcMap      = [ Cinfo.Sep(begin = '@compute.Finish@START', end = '@compute.Finish@END' ) ] , 
        varMap     = [ ('@compute.Finish@START', Control_map) ]
        )


def buildRefMapTrain(Cinfo, refVerifSp, PCstate):
    
    LocalSync_map = VarMap({
        'num_visible':  ('num_visible', SysCSignal(u16)  ), #: 32768,)
        'num_testusers':('num_testusers', SysCSignal(u16) ),
        'num_hidden':   ('num_hidden',  SysCSignal(u16)  ),
        'num_loops':    ('num_loops',   SysCSignal(u16)  ),
        'num_movies':   ('num_movies',  SysCSignal(u16)  ),
        'num_users':    ('num_users',   SysCSignal(Bool) )
        })
    Train_map_fun1 = TopVarMap.copy()
    Train_map_fun1.append({
        'edges'             : CArray('edges', SysCFixedType(8,7)), #2d no compare
        'train_input_done'  : ('train_input_done',   SysCSignal(Bool) ),  
        'hidden_unit'       : CArray('hidden_unit', Bool), # 1d
        'visible_unit'      : CArray('visible_unit', Bool), # 1d
        'visibleEnergies'   : CArray('visibleEnergies', SysCFixedType(16,15)), # 1d no compare
        'pos'               : CArray('pos', Bool),
        'per_v_pc'          : PCstate('per_v_pc', {'@vpc0':0,'@vpc1':1,'@vpc2':2,'@vpc3':3}),
        'train_upc'         : PCstate('train_upc', {'@trainUpc0':0,'@trainUpc1':1, '@trainUpc2':2, '@trainUpc3':3}),
        'upc'               : PCstate('upc',  { '@upc@0' : 0, '@upc@1' : 1, '@upc@2' : 2, '@upc@3' : 3} ),
        'train_v_cnt'       : ('v', u16),
        'train_h_cnt'       : ('h', u16)
        })
    refVerifSp.setCondition(
        name       = 'train.i0', # I0
        instDecode = { 'rst' : 0, 'init_done' : 1, 'done' : 0, 'upc': 2, 'GM.upc': 2, 'train_input_done' : 1, 'predict_input_done':0, 
            'GM.per_v_pc':0, 'GM.train_upc':0 },  # these are Cnames
        funcCall   = [ 'IMPL.train_rbm()' ],
        pcMap      = [ Cinfo.Sep(begin = '@train.i0@START', end = '@train.i0@END' ) ] , 
        varMap     = [ ('@train.i0@START', Train_map_fun1) ]
        )


    Train_map_fun2 = Train_map_fun1.copy()
    Train_map_fun2.append({
        'train_sum'         : ('sum', SysCFixedType(16,15) ),
        'train_max'         : ('max', SysCFixedType(16,15) ),
        'sumOfpow2'         : ('sumOfpow2', SysCUFixedType(64,64) ),
        'pow2'              : CArray('pow2', SysCUFixedType(32,32) ), # 1d no compare
        'jstate'            : ('j', u16)
        })

    refVerifSp.setCondition(
        name       = 'train.i1', # I1
        instDecode = { 'rst' : 0, 'init_done' : 1, 'done' : 0, 'upc': 2, 'GM.upc': 2, 'train_input_done' : 1, 'predict_input_done':0, 
            'GM.per_v_pc':0, 'GM.train_upc':1 },  # these are Cnames
        funcCall   = [ 'IMPL.train_rbm()' ],
        pcMap      = [ Cinfo.Sep(begin = '@train.i1@START', end = '@train.i1@END' ) ] , 
        varMap     = [ ('@train.i0@START', Train_map_fun2) ]
        )

    refVerifSp.setCondition(
        name       = 'train.i2', # I2
        instDecode = { 'rst' : 0, 'init_done' : 1, 'done' : 0, 'upc': 2, 'GM.upc': 2, 'train_input_done' : 1, 'predict_input_done':0, 
            'GM.per_v_pc':1, 'GM.train_upc':1 },  # these are Cnames
        funcCall   = [ 'IMPL.train_rbm()' ],
        pcMap      = [ Cinfo.Sep(begin = '@train.i2@START', end = '@train.i2@END' ) ] , 
        varMap     = [ ('@train.i2@START', Train_map_fun2) ]
        )

    refVerifSp.setCondition(
        name       = 'train.i3', # I3
        instDecode = { 'rst' : 0, 'init_done' : 1, 'done' : 0, 'upc': 2, 'GM.upc': 2, 'train_input_done' : 1, 'predict_input_done':0, 
            'GM.per_v_pc':2, 'GM.train_upc':1 },  # these are Cnames
        funcCall   = [ 'IMPL.train_rbm()' ],
        pcMap      = [ Cinfo.Sep(begin = '@train.i3@START', end = '@train.i3@END' ) ] , 
        varMap     = [ ('@train.i3@START', Train_map_fun2) ]
        )
    refVerifSp.setCondition(
        name       = 'train.i4', # I4
        instDecode = { 'rst' : 0, 'init_done' : 1, 'done' : 0, 'upc': 2, 'GM.upc': 2, 'train_input_done' : 1, 'predict_input_done':0, 
            'GM.per_v_pc':3, 'GM.train_upc':1 },  # these are Cnames
        funcCall   = [ 'IMPL.train_rbm()' ],
        pcMap      = [ Cinfo.Sep(begin = '@train.i4@START', end = '@train.i4@END' ) ] , 
        varMap     = [ ('@train.i4@START', Train_map_fun2) ]
        )

    Train_map_fun3 = TopVarMap.copy()
    Train_map_fun3.append({
        'train_input_done'  : ('train_input_done',   SysCSignal(Bool) ),  
        'hidden_unit'       : CArray('hidden_unit', Bool), # 1d
        'pos'               : CArray('pos', Bool),
        'train_upc'         : PCstate('train_upc', {'@trainUpc0':0,'@trainUpc1':1, '@trainUpc2':2, '@trainUpc3':3}),
        'upc'               : PCstate('upc',  { '@upc@0' : 0, '@upc@1' : 1, '@upc@2' : 2, '@upc@3' : 3} ),
        'train_v_cnt'       : ('v', u16),
        'train_h_cnt'       : ('h', u16)
        })

    refVerifSp.setCondition(
        name       = 'train.i5', # I5
        instDecode = { 'rst' : 0, 'init_done' : 1, 'done' : 0, 'upc': 2, 'GM.upc': 2, 'train_input_done' : 1, 'predict_input_done':0, 
            'GM.per_v_pc':0, 'GM.train_upc':3 },  # these are Cnames
        funcCall   = [ 'IMPL.train_rbm()' ],
        pcMap      = [ Cinfo.Sep(begin = '@train.i5@START', end = '@train.i5@END' ) ] , 
        varMap     = [ ('@train.i5@START', Train_map_fun3) ]
        )


def buildRefMapPredict(Cinfo, refVerifSp, PCstate):
    LocalSync_map = VarMap({
        'num_visible':  ('num_visible', SysCSignal(u16)  ), #: 32768,)
        'num_testusers':('num_testusers', SysCSignal(u16) ),
        'num_hidden':   ('num_hidden',  SysCSignal(u16)  ),
        'num_loops':    ('num_loops',   SysCSignal(u16)  ),
        'num_movies':   ('num_movies',  SysCSignal(u16)  ),
        'num_users':    ('num_users',   SysCSignal(Bool) )
        })
    Predict_map_fun1 = TopVarMap.copy()
    Predict_map_fun1.append({
        'edges'               : CArray('edges', SysCFixedType(8,7)), #2d no compare
        'predict_input_done'  : ('predict_input_done',   SysCSignal(Bool) ),  
        'hidden_unit'         : CArray('hidden_unit', Bool), # 1d
        'visible_unit'        : CArray('visible_unit', Bool), # 1d
        'visibleEnergies'     : CArray('visibleEnergies', SysCFixedType(16,15)), # 1d no compare
        'pos'                 : CArray('pos', Bool),
        'per_v_pc'            : PCstate('per_v_pc', {'@vpc0':0,'@vpc1':1,'@vpc2':2,'@vpc3':3, '@vpc4':4}),
        'predict_upc'         : PCstate('predict_upc', {'@predictUpc0':0,'@predictUpc1':1, '@predictUpc2':2, '@predictUpc3':3}),
        'upc'                 : PCstate('upc',  { '@upc@0' : 0, '@upc@1' : 1, '@upc@2' : 2, '@upc@3' : 3} ),
        'predict_v_cnt'       : ('v', u16),
        'predict_h_cnt'       : ('h', u16)
        })
    refVerifSp.setCondition(
        name       = 'predict.i0', # I0
        instDecode = { 'rst' : 0, 'init_done' : 1, 'done' : 0, 'upc': 2, 'GM.upc': 2, 'predict_input_done' : 1, 'train_input_done':0, 
            'GM.per_v_pc':0, 'GM.predict_upc':0 },  # these are Cnames
        funcCall   = [ 'IMPL.predict_rbm()' ],
        pcMap      = [ Cinfo.Sep(begin = '@predict.i0@START', end = '@predict.i0@END' ) ] , 
        varMap     = [ ('@predict.i0@START', Predict_map_fun1) ]
        )


    Predict_map_fun2 = Predict_map_fun1.copy()
    Predict_map_fun2.append({
        'predict_sum'         : ('sum', SysCFixedType(16,15) ),
        'predict_max'         : ('max', SysCFixedType(16,15) ),
        'sumOfpow2'           : ('sumOfpow2', SysCUFixedType(64,64) ),
        'pow2'                : CArray('pow2', SysCUFixedType(32,32) ), # 1d no compare
        'jstate'              : ('j', u16)
        })

    refVerifSp.setCondition(
        name       = 'predict.i1', # I1
        instDecode = { 'rst' : 0, 'init_done' : 1, 'done' : 0, 'upc': 2, 'GM.upc': 2, 'predict_input_done' : 1, 'train_input_done':0, 
            'GM.per_v_pc':0, 'GM.predict_upc':1 },  # these are Cnames
        funcCall   = [ 'IMPL.predict_rbm()' ],
        pcMap      = [ Cinfo.Sep(begin = '@predict.i1@START', end = '@predict.i1@END' ) ] , 
        varMap     = [ ('@predict.i0@START', Predict_map_fun2) ]
        )

    refVerifSp.setCondition(
        name       = 'predict.i2', # I2
        instDecode = { 'rst' : 0, 'init_done' : 1, 'done' : 0, 'upc': 2, 'GM.upc': 2, 'predict_input_done' : 1, 'train_input_done':0, 
            'GM.per_v_pc':1, 'GM.predict_upc':1 },  # these are Cnames
        funcCall   = [ 'IMPL.predict_rbm()' ],
        pcMap      = [ Cinfo.Sep(begin = '@predict.i2@START', end = '@predict.i2@END' ) ] , 
        varMap     = [ ('@predict.i2@START', Predict_map_fun2) ]
        )

    refVerifSp.setCondition(
        name       = 'predict.i3', # I3
        instDecode = { 'rst' : 0, 'init_done' : 1, 'done' : 0, 'upc': 2, 'GM.upc': 2, 'predict_input_done' : 1, 'train_input_done':0, 
            'GM.per_v_pc':2, 'GM.predict_upc':1 },  # these are Cnames
        funcCall   = [ 'IMPL.predict_rbm()' ],
        pcMap      = [ Cinfo.Sep(begin = '@predict.i3@START', end = '@predict.i3@END' ) ] , 
        varMap     = [ ('@predict.i3@START', Predict_map_fun2) ]
        )
    refVerifSp.setCondition(
        name       = 'predict.i4', # I4
        instDecode = { 'rst' : 0, 'init_done' : 1, 'done' : 0, 'upc': 2, 'GM.upc': 2, 'predict_input_done' : 1, 'train_input_done':0, 
            'GM.per_v_pc':3, 'GM.predict_upc':1 },  # these are Cnames
        funcCall   = [ 'IMPL.predict_rbm()' ],
        pcMap      = [ Cinfo.Sep(begin = '@predict.i4@START', end = '@predict.i4@END' ) ] , 
        varMap     = [ ('@predict.i4@START', Predict_map_fun2) ]
        )

    Predict_map_fun3 = TopVarMap.copy()
    Predict_map_fun3.append({
        'predict_input_done'  : ('predict_input_done',   SysCSignal(Bool) ),  
        'hidden_unit'         : CArray('hidden_unit', Bool), # 1d
        'pos'                 : CArray('pos', Bool),
        'predict_upc'         : PCstate('predict_upc', {'@predictUpc0':0,'@predictUpc1':1, '@predictUpc2':2, '@predictUpc3':3}),
        'upc'                 : PCstate('upc',  { '@upc@0' : 0, '@upc@1' : 1, '@upc@2' : 2, '@upc@3' : 3} ),
        'predict_v_cnt'       : ('v', u16),
        'predict_h_cnt'       : ('h', u16)
        })

    refVerifSp.setCondition(
        name       = 'predict.i5', # I5
        instDecode = { 'rst' : 0, 'init_done' : 1, 'done' : 0, 'upc': 2, 'GM.upc': 2, 'predict_input_done' : 1, 'predict_input_done':0, 
            'GM.per_v_pc':0, 'GM.predict_upc':3 },  # these are Cnames
        funcCall   = [ 'IMPL.predict_rbm()' ],
        pcMap      = [ Cinfo.Sep(begin = '@predict.i5@START', end = '@predict.i5@END' ) ] , 
        varMap     = [ ('@predict.i5@START', Predict_map_fun3) ]
        )


def buildRefMapTop(Cinfo, refVerifSp, PCstate):
    # all labels: @_global, 
    # pcstate = PCstate( varname, {"label": value} )
    # @_ctl_conf
    RBM_map = TopVarMap
    

    refVerifSp.setCondition(
        name       = 'RBM.confDoneInst',
        instDecode = { 'rst' : 0, 'init_done' : 0, 'conf_done' : 1 },  # these are Cnames
        funcCall   = [ 'IMPL.config()' ],
        pcMap      = [ Cinfo.Sep(begin = '@confDoneInst@START', end = '@confDoneInst@END' ) ] , 
        varMap     = [ ('@confDoneInst@START', RBM_map)  ]
        )

    refVerifSp.setCondition(
        name       = 'RBM.rdGrantInst',
        instDecode = { 'rd_request' : 1, 'rd_grant' : 1 , 'GM.rd_request':1},  # This needs to be assumed, additional control maybe
        funcCall   = [ 'IMPL.load()', 'IMPL.load()'],
        pcMap      = [ Cinfo.Sep(begin = '@rdGrantInst@START@0', end = '@rdGrantInst@END@0'),
                       Cinfo.Sep(begin = '@rdGrantInst@START@1', end = '@rdGrantInst@END@1') ],
        varMap     = [ ('@rdGrantInst@START@0', RBM_map),  ('@rdGrantInst@START@1', RBM_map) ]
        )

    refVerifSp.setCondition(
        name       = 'RBM.wrGrantInst',
        instDecode = { 'wr_request' : 1, 'wr_grant' : 1 , 'GM.wr_request':1}, 
        funcCall   = [ 'IMPL.store()' ],
        pcMap      = [ Cinfo.Sep(begin = '@wrGrantInst@START', end = '@wrGrantInst@END') ],
        varMap     = [ ('@wrGrantInst@START', RBM_map) ]
        )

