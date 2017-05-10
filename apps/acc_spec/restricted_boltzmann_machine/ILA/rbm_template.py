import ila
from math import log
from fixpoint import fixpointTemp, fixpoint, fpconst, fpconvert

# Parameters & Defines

LEARN_RATE = 0.5
FP01_D = fixpointTemp(64,1)
FP05_D = fixpointTemp(32,3)
FPsum3 = fixpointTemp(64,64)
FPpow  = fixpointTemp(32,32)
FPsum  = fixpointTemp(16,15,True)
FPedge = fixpointTemp(8,7,True)
FPconst= fixpointTemp(16,4,True)
FPu16  = fixpointTemp(16,16)


def buildILA():
    #---------------------------
    # define universal constant
    #---------------------------
    K = 5
    NUM_MOVIE_MAX  = 100
    NUM_HIDDEN_MAX = 100
    NUM_VISIBLE_MAX= NUM_MOVIE_MAX * K
    DATAMEM_ADDR_WIDTH = int(log(NUM_VISIBLE_MAX+1)/log(2)) + 1  # 9 # it is definitely not dividable, but need to check
    HIDDEN_UNIT_WIDTH  = int( log(NUM_HIDDEN_MAX+1)/log(2)) + 1  # 7 # it is definitely not dividable, but need to check
    VISIBLE_UNIT_WIDTH = int(log(NUM_VISIBLE_MAX+1)/log(2)) + 1  # 9
    EDGEMEM_ADDR_WIDTH = int(log( (NUM_VISIBLE_MAX+1)*(NUM_HIDDEN_MAX+1) ) / log(2)) + 1 # 16
    POS_ADDR_WIDTH = EDGEMEM_ADDR_WIDTH
    NEG_ADDR_WIDTH = EDGEMEM_ADDR_WIDTH
    PREDICT_RESULT_WIDTH = int(log(NUM_MOVIE_MAX)/log(2))+1  # 7
    KWIDTH = int( log(K)/log(2) ) + 1 # 3


    #---------------------------
    # Model
    #---------------------------

    rbm = ila.Abstraction('RBM')

    conf_done            = rbm.inp('conf_done'            ,  1)
    conf_num_hidden      = rbm.inp('conf_num_hidden'      , 32)
    conf_num_visible     = rbm.inp('conf_num_visible'     , 32)
    conf_num_users       = rbm.inp('conf_num_users'       , 32)
    conf_num_loops       = rbm.inp('conf_num_loops'       , 32)
    conf_num_testusers   = rbm.inp('conf_num_testusers'   , 32)
    conf_num_movies      = rbm.inp('conf_num_movies'      , 32)

    rst     = rbm.inp('rst',  1)

    init_done       = rbm.reg('init_done'       ,  1)
    done            = rbm.reg('done'            ,  1)
    num_hidden      = rbm.reg('num_hidden'      , 16)
    num_visible     = rbm.reg('num_visible'     , 16)
    num_users       = rbm.reg('num_users'       , 16)
    num_loops       = rbm.reg('num_loops'       , 16)
    num_testusers   = rbm.reg('num_testusers'   , 16)
    num_movies      = rbm.reg('num_movies'      , 16)

    # DMA output
    rd_index  = rbm.reg('rd_index',  32)
    rd_length = rbm.reg('rd_length', 32)
    rd_request= rbm.reg('rd_request', 1)
    rd_grant  = rbm.inp('rd_grant',   1)
    data_in   = rbm.inp('data_in',   32)
    # rd_cnt    = rbm.reg('rd_cnt', 16)  # i ureg  #585

    # DMA input
    wr_grant   = rbm.inp('wr_grant',   1)
    wr_request = rbm.reg('wr_request', 1)
    wr_index   = rbm.reg('wr_index',  32)
    wr_length  = rbm.reg('wr_length', 32)
    data_out   = rbm.reg('data_out',  32)
    # wr_cnt = rbm.reg('wr_cnt', 16) : u reg

    data = rbm.mem('data', DATAMEM_ADDR_WIDTH , 8 )
    rbm.mem('predict_result', PREDICT_RESULT_WIDTH, 8 )


    #-------------------------------------
    #  Decoding Expressions
    #-------------------------------------
    rstInst        = rst == 1
    confDoneInst   = (rst == 0) & (init_done == 0) & (conf_done == 1)
    rdGrantInst    = (rd_request == 1) & (rd_grant == 1)
    wrGrantInst    = (wr_request == 1) & (wr_grant == 1)
    decodeExpr     = [rstInst, confDoneInst, rdGrantInst, wrGrantInst]

    #-------------------------------------
    #  AUX Functions
    #-------------------------------------
    def const(v,w):
        return rbm.const(v,w)
    b0 = const(0,1)
    b1 = const(1,1)
    h0_8  = const(0, 8)
    h1_8  = const(1, 8)
    h0_4  = const(0, 4)
    h1_4  = const(1, 4)
    h2_4  = const(2, 4)
    h3_4  = const(3, 4)
    h4_4  = const(4, 4)
    h0_16 = const(0,16)
    h1_16 = const(1,16)
    h0_32 = const(0,32)
    h0_64 = const(0,64)

    #-------------------------------------
    #  Init conditions
    #-------------------------------------

    rbm.set_init('init_done'    , b0 )
    rbm.set_init('done'         , b0 )
    rbm.set_init('num_hidden'   , h0_16)
    rbm.set_init('num_visible'  , h0_16)
    rbm.set_init('num_users'    , h0_16)
    rbm.set_init('num_loops'    , h0_16)
    rbm.set_init('num_testusers', h0_16)
    rbm.set_init('num_movies'   , h0_16)

    #-------------------------------------
    #  Config
    #-------------------------------------

    # this means, once configured, unless reset, it cannot be reconfigured
    init_done_nxt     = ila.ite(rstInst, b0,    ila.ite(confDoneInst, b1                        , init_done) )
    num_hidden_nxt    = ila.ite(rstInst, h0_16, ila.ite(confDoneInst, conf_num_hidden   [15:0]  , num_hidden ) )
    num_visible_nxt   = ila.ite(rstInst, h0_16, ila.ite(confDoneInst, conf_num_visible  [15:0]  , num_visible ) )
    num_users_nxt     = ila.ite(rstInst, h0_16, ila.ite(confDoneInst, conf_num_users    [15:0]  , num_users ) )
    num_loops_nxt     = ila.ite(rstInst, h0_16, ila.ite(confDoneInst, conf_num_loops    [15:0]  , num_loops ) )
    num_testusers_nxt = ila.ite(rstInst, h0_16, ila.ite(confDoneInst, conf_num_testusers[15:0]  , num_testusers ) )
    num_movies_nxt    = ila.ite(rstInst, h0_16, ila.ite(confDoneInst, conf_num_movies   [15:0]  , num_movies ) )

    rbm.set_next('init_done',   init_done_nxt)
    rbm.set_next('num_hidden',  num_hidden_nxt)
    rbm.set_next('num_visible', num_visible_nxt)
    rbm.set_next('num_users',   num_users_nxt)
    rbm.set_next('num_loops',   num_loops_nxt)
    rbm.set_next('num_testusers', num_testusers_nxt)
    rbm.set_next('num_movies',  num_movies_nxt)

    # INST-level w/r complete
    rbm_rd_complete = rbm.reg('rd_complete',1)
    rbm_wr_complete = rbm.reg('wr_complete',1)
    rbm.set_init('rd_complete', b0); rbm.set_init('wr_complete', b0)

    #------------------------------------
    #  Compute UABS
    #------------------------------------

    uabs = rbm.add_microabstraction('compute', (init_done == 1) & (done == 0) )
    index          = uabs.reg('index' ,     16)
    loop_count     = uabs.reg('loop_count', 16)
    pc             = uabs.reg('upc',         4)
    edges_mem      = uabs.mem('edges', EDGEMEM_ADDR_WIDTH ,8)

    nlp = uabs.getreg('num_loops')
    nm  = ila.zero_extend(uabs.getreg('num_movies'), 32)
    nu  = uabs.getreg('num_users')
    ntu = uabs.getreg('num_testusers')
    out_rd_request  = uabs.getreg('rd_request')
    out_rd_complete = uabs.getreg('rd_complete')
    out_rd_length   = uabs.getreg('rd_length')
    out_rd_index    = uabs.getreg('rd_index')

    train_input_done   = uabs.reg('train_input_done',   1)
    predict_input_done = uabs.reg('predict_input_done', 1)

    uabs.set_init('upc', const(0,4) )
    uabs.set_init('index', h0_16 )
    uabs.set_init('loop_count', h0_16 )
    uabs.set_init('train_input_done',   b0)
    uabs.set_init('predict_input_done', b0)
    uabs.set_init('rd_complete', b0)

    ###  computation micro_instructions

    StartRead = (pc == 0) 
    WaitReadComplete = (pc == 1) & (out_rd_complete == 0)
    DecideTrainOrPredict = (pc == 1) & (out_rd_complete == 1)
    StartTrain   = (pc == 2) & (train_input_done == 1) 
    StartPredict = (pc == 2) & (predict_input_done == 1)
    Finish       = (pc == 3)

    StartReadState = const(0,4); WaitReadCompleteState = const(1,4); StartTrainOrPredict = const(2,4); FinishState = const(3,4)
      

    decodeExpr = [StartRead, WaitReadComplete, DecideTrainOrPredict, StartTrain, StartPredict, Finish]

    out_rd_request_nxt  = ila.ite(StartRead, b1, out_rd_request )
    out_rd_length_nxt   = ila.ite(StartRead, 5*nm,  out_rd_length)
    out_rd_index_nxt    = ila.ite(StartRead, ila.zero_extend(index, 32), out_rd_index )
    out_rd_complete_nxt = ila.ite(StartRead, b0, ila.ite(DecideTrainOrPredict, b0, out_rd_complete))

    train_input_done_nxt   = ila.ite(DecideTrainOrPredict, ila.ite(loop_count < nlp, b1, b0) , train_input_done )
    predict_input_done_nxt = ila.ite(DecideTrainOrPredict, ila.ite(loop_count== nlp, b1, b0) , predict_input_done )

    pc_nxt = ila.ite(StartRead, WaitReadCompleteState, 
             ila.ite(WaitReadComplete, pc,
             ila.ite(DecideTrainOrPredict, StartTrainOrPredict,
             ila.ite(StartTrain, StartTrainOrPredict,   # StartReadState, # actually should be updated by u2inst 
             ila.ite(StartPredict, StartTrainOrPredict, # StartReadState, # actually should be updated by u2inst 
             ila.ite(Finish, FinishState ,
                pc # should never happen!
                ))))))

    # should be updated by u2inst
    index_nxt_dummy =   ila.ite(StartTrain | StartPredict, 
                        ila.ite( (index == nu - 1)  & (loop_count != nlp), h0_16,
                        ila.ite( (index == ntu - 1) & (loop_count == nlp), index, # And it is not correct
                        index + 1 ) ), 
                        index )
    # not in use
    loop_count_nxt_dummy =  ila.ite(StartTrain | StartPredict,
                            ila.ite( (index == nu - 1)  & (loop_count != nlp) , loop_count + 1, loop_count), loop_count )

    uabs.set_next('rd_request', out_rd_request_nxt)
    uabs.set_next('rd_length' , out_rd_length_nxt )
    uabs.set_next('rd_index'  , out_rd_index_nxt  )
    uabs.set_next('rd_complete', out_rd_complete_nxt )
    uabs.set_next('train_input_done'  , train_input_done_nxt  )
    uabs.set_next('predict_input_done', predict_input_done_nxt)
    uabs.set_next('upc', pc_nxt)
    uabs.set_next('index', index) ; uabs.set_next('loop_count', loop_count)
    # this has to be updated by micro_inst
    # read_request is turned off by loaduabs
    # predict_input_done, train_input_done is turned off by uabs_train/predict

    #------------------------------------
    #  Load UABS
    #------------------------------------
    # RBM interface
    # high-level interface
    rd_granted     = rbm.reg('rd_granted', 1)  # this is only used for maintaining the validity of load UABS, no other should use
    data_nxt       = ila.ite( rdGrantInst , ila.store( data, const(0, DATAMEM_ADDR_WIDTH) , data_in[7:0] ) , data ) # data # 
    rd_granted_nxt = ila.ite( rdGrantInst , b1, rd_granted )
    rbm.set_next('rd_granted', rd_granted_nxt)
    rbm.set_next('data', data_nxt)

    # one change is to move these into lower abstraction
    DMAload = rbm.add_microabstraction('DMAload', (rd_granted == 1) ) # this is sub-instruction
    w_cnt = DMAload.reg('i', 16)

    dma_rd_request = DMAload.getreg('rd_request')
    dma_rd_length  = DMAload.getreg('rd_length')
    dma_rd_index   = DMAload.getreg('rd_index')


    state_update_data = DMAload.getmem('data')
    state_update_rd_request = dma_rd_request
    self_update_rd_granted = DMAload.getreg('rd_granted')

    more_read_in = w_cnt < dma_rd_length[15:0]
    last_cycle   = w_cnt== dma_rd_length[15:0]
    DMAload.set_init('i', h1_16 ) # h0_16 )
    DMAload.set_next('i', ila.ite(more_read_in, w_cnt + 1, w_cnt) )
    DMAload.set_next('rd_request', b0 )  # reset to 0 immediately
    DMAload.set_next('rd_granted', ila.ite(more_read_in, self_update_rd_granted , b0) )
    DMAload.set_next('rd_complete', ila.ite(more_read_in, b0, b1))
    DMAload.set_next('data', ila.ite(more_read_in, ila.store(state_update_data,  w_cnt[DATAMEM_ADDR_WIDTH-1:0] , data_in[7:0] ), 
                             ila.ite(last_cycle,   ila.store(state_update_data,  dma_rd_length[DATAMEM_ADDR_WIDTH-1:0],  h1_8 ),
                             state_update_data ) ) )

    #------------------------------------
    #  Train UUABS
    #------------------------------------

    TrainUabs = uabs.add_microabstraction('train', train_input_done == 1)

    sigmoid_func = TrainUabs.fun('sigmoid', 64, [16]) # DATA_sum_, 01_D
    rand_func    = TrainUabs.fun('rand', 64, [])      # generate random number
    to_int_exp   = TrainUabs.fun('to_int_exp', 32 , [16] )  # 
    divide_func  = TrainUabs.fun('divide', 64 , [32, 64] )  # dp:32_32 / sum_of_pow2 64_64 = 64_1

    hidden_unit  = TrainUabs.mem('hidden_unit',  HIDDEN_UNIT_WIDTH,  1)
    visible_unit = TrainUabs.mem('visible_unit', VISIBLE_UNIT_WIDTH, 1)
    visibleEnergy= TrainUabs.mem('visibleEnergies', KWIDTH , 16)
    pow2         = TrainUabs.mem('pow2', KWIDTH ,32)
    pos          = TrainUabs.mem('pos', POS_ADDR_WIDTH, 1 )
    #neg          = TrainUabs.mem('neg', NEG_ADDR_WIDTH, 1 ) # not needed

    train_sum    = TrainUabs.reg('train_sum', 16)
    train_max    = TrainUabs.reg('train_max', 16)
    sumOfpow2    = TrainUabs.reg('sumOfpow2', 64)

    jstate       = TrainUabs.reg('jstate', 16)
    inner_loop_pc= TrainUabs.reg('per_v_pc', 4)


    train_pc    = TrainUabs.reg('train_upc', 4)  # Re-evaluate
    v_cnt       = TrainUabs.reg('train_v_cnt', 16)
    h_cnt       = TrainUabs.reg('train_h_cnt', 16)

    train_input = TrainUabs.getmem('data')
    edges_input = TrainUabs.getmem('edges')
    nv          = TrainUabs.getreg('num_visible')
    nh          = TrainUabs.getreg('num_hidden')
    nu          = TrainUabs.getreg('num_users')
    ntu         = TrainUabs.getreg('num_testusers')
    nlp         = TrainUabs.getreg('num_loops')


    SumEdge = train_pc == 0; SumEdgeState = const(0,4)
    SumHidden = train_pc == 1; SumHiddenState = const(1,4)
    StorePos = train_pc == 3; StorePosState = const(3,4)
    EdgeUpdate = train_pc == 2; EdgeUpdateState = const(2,4)


    TrainUabs.decode_exprs = [SumEdge, SumHidden, EdgeUpdate ]    

    #Begin
    v_cnt_init = const(0, 16)
    h_cnt_init = const(0, 16)
    pc_init    = const(0, 4)

    #SumEdge: s0
    edge_load_addr     = (NUM_HIDDEN_MAX+1) * v_cnt + h_cnt       
    train_sum_s0_nxt   = ila.ite(v_cnt == 0, const(0,16), train_sum ) + ila.ite( ila.load(train_input, v_cnt[DATAMEM_ADDR_WIDTH-1:0]) == 1 , fpconvert(ila.load(edges_input,edge_load_addr ), FPedge, FPsum) , const(0,16) )
    v_cnt_s0_nxt       = ila.ite(v_cnt == nv , h0_16 , v_cnt + 1 )
    h_cnt_s0_nxt       = ila.ite( ( v_cnt == nv ) ,  ila.ite(h_cnt == nh - 1 , h0_16 , h_cnt + 1  )  , h_cnt )
    #                                                    Here ^^^ is for transiting to next state
    hidden_update_s0_0 = ila.ite( ila.appfun(rand_func) <  ila.appfun( sigmoid_func , train_sum_s0_nxt ) , b1 , b0)
    hidden_update_s0_1 = ila.ite( v_cnt == nv , ila.store(hidden_unit, h_cnt[HIDDEN_UNIT_WIDTH-1:0] , hidden_update_s0_0 ) , hidden_unit )
    hidden_update_s0_2 = ila.ite( ( v_cnt == nv ) & (h_cnt == nh - 1 ) , ila.store(hidden_update_s0_1, nh[HIDDEN_UNIT_WIDTH-1:0], b1 ) , hidden_update_s0_1 )
    train_pc_s0_nxt = ila.ite( ( v_cnt == nv ) & (h_cnt == nh - 1 ) , SumHiddenState , SumEdgeState )
    # Just like init
    jstate_s0_nxt = h0_16
    inner_loop_pc_s0_nxt = h0_4

    # add prefix : 
    # train_sum_nxt = ila.ite(SumEdge, train_sum_s0_nxt, ila.ite(SumHidden, ... ) )

    # SumHiddenK0-K4 : s1-s5

    # pc:1 per_v_pc : 0     1       2       3      

    LastH = h_cnt == nh
    LastJ = jstate == K-1
    LastV = (v_cnt + K == nv) | (v_cnt + K >= NUM_VISIBLE_MAX)
    SumHiddenL0 = SumHidden & (inner_loop_pc == 0)
    SumHiddenL1 = SumHidden & (inner_loop_pc == 1)
    SumHiddenL2 = SumHidden & (inner_loop_pc == 2)
    SumHiddenL3 = SumHidden & (inner_loop_pc == 3)

    h_cnt_s1_s5_L0_nxt  = ila.ite( LastH , h0_16, h_cnt + 1)
    jstate_s1_s5_L0_nxt = ila.ite( LastH, ila.ite( LastJ, h0_16, jstate + 1 ) , jstate )
    inner_loop_pc_s1_s5_L0_nxt = ila.ite( LastJ & LastH , h1_4 , inner_loop_pc )

    jstate_s1_s5_L1_nxt = ila.ite( LastJ, h0_16, jstate + 1 )
    inner_loop_pc_s1_s5_L1_nxt = ila.ite( LastJ, h2_4, inner_loop_pc )

    jstate_s1_s5_L2_nxt = jstate_s1_s5_L1_nxt
    inner_loop_pc_s1_s5_L2_nxt = ila.ite( LastJ, h3_4, inner_loop_pc )

    jstate_s1_s5_L3_nxt = jstate_s1_s5_L2_nxt
    inner_loop_pc_s1_s5_L3_nxt = ila.ite( LastJ, 
                                 ila.ite( LastV , h0_4, h0_4  ), # will choose to go back or not
                                 inner_loop_pc )

    def nextCondition(l0,l1,l2,l3,default):
        return ila.ite(SumHiddenL0, l0, ila.ite(SumHiddenL1, l1, ila.ite(SumHiddenL2, l2, ila.ite(SumHiddenL3, l3,default ))))

    h_cnt_s1_s5_nxt = nextCondition(h_cnt_s1_s5_L0_nxt,h_cnt,h_cnt,h_cnt, h_cnt ) 
    v_cnt_s1_s5_nxt = ila.ite(SumHiddenL3 & LastJ, ila.ite( LastV, h0_16 , v_cnt + K ), v_cnt )
    jstate_s1_s5_nxt = nextCondition(jstate_s1_s5_L0_nxt,jstate_s1_s5_L1_nxt,jstate_s1_s5_L2_nxt,jstate_s1_s5_L3_nxt, jstate ) 
    inner_loop_pc_s1_s5_nxt = nextCondition(inner_loop_pc_s1_s5_L0_nxt,inner_loop_pc_s1_s5_L1_nxt,inner_loop_pc_s1_s5_L2_nxt,inner_loop_pc_s1_s5_L3_nxt, inner_loop_pc ) 
    train_pc_s1_s5_nxt = ila.ite(SumHiddenL3 & LastJ & LastV, StorePosState, SumHiddenState )
    

    # L0
    train_sum_s1_s5_L0_nxt = ila.ite( h_cnt == 0 , h0_16 , train_sum ) +ila.ite( ila.load(hidden_unit, h_cnt[HIDDEN_UNIT_WIDTH-1:0]) == 1 , fpconvert( ila.load(edges_input, edge_load_addr ), FPedge, FPsum ), h0_16 )
    _train_max_origin_L0    = ila.ite( jstate == 0,  fpconst(-500, FPsum).ast , train_max ) # make sure the first time we are comparing with init sum
    train_max_s1_s5_L0_nxt = ila.ite( LastH , ila.ite( ila.sgt( train_sum_s1_s5_L0_nxt , _train_max_origin_L0 ) , train_sum_s1_s5_L0_nxt , _train_max_origin_L0) , train_max )
    visibleEnergy_s1_s5_L0_nxt = ila.ite( LastH ,ila.store( visibleEnergy, jstate[KWIDTH-1:0], train_sum_s1_s5_L0_nxt )  , visibleEnergy )
    # L1
    # sum3: 64_64  ->   dp: 32_32
    _31_sum = fpconst(31, FPsum).ast
    train_max_s1_s5_L1_nxt = ila.ite(jstate == 0, train_max - _31_sum, train_max)
    _st_val_L1 = ila.load(visibleEnergy, jstate[KWIDTH-1:0]) - train_max_s1_s5_L1_nxt
    visibleEnergy_s1_s5_L1_nxt = ila.store( visibleEnergy, jstate[KWIDTH-1:0], _st_val_L1  )
    # L2
    _pow2_new_val = ila.appfun(to_int_exp, ila.load(visibleEnergy, jstate[KWIDTH-1:0]) )
    _pow2_new_convert = fpconvert( _pow2_new_val, FPpow, FPsum3 )
    sumOfpow2_s1_s5_L2_nxt = ila.ite( jstate == 0, h0_64, sumOfpow2 ) + _pow2_new_convert
    pow2_s1_s5_L2_nxt = ila.store( pow2, jstate[KWIDTH-1:0], _pow2_new_val )
    # L3
    _probs = ila.appfun( divide_func, [ila.load(pow2, jstate[KWIDTH-1:0]), sumOfpow2] )
    _RAND  = ila.appfun( rand_func )
    _visible_unit_new_val = ila.ite( _probs > _RAND, b1, b0 )
    _vu_idx = v_cnt + jstate 
    _visible_unit_s1_s5_L3_1 = ila.store( visible_unit, _vu_idx[VISIBLE_UNIT_WIDTH-1:0], _visible_unit_new_val )
    visible_unit_s1_s5_L3_nxt = ila.ite( LastJ & LastV, ila.store(_visible_unit_s1_s5_L3_1, nv[VISIBLE_UNIT_WIDTH-1:0], b1 ), _visible_unit_s1_s5_L3_1 )  
    # when exit visible unit should be made to store 1 at nv

    train_sum_s1_s5_nxt     = nextCondition(train_sum_s1_s5_L0_nxt, train_sum, train_sum, train_sum, train_sum )
    train_max_s1_s5_nxt     = nextCondition(train_max_s1_s5_L0_nxt, train_max_s1_s5_L1_nxt, train_max, train_max, train_max )
    visible_unit_s1_s5_nxt  = nextCondition(visible_unit, visible_unit, visible_unit, visible_unit_s1_s5_L3_nxt, visible_unit )
    visibleEnergy_s1_s5_nxt = nextCondition(visibleEnergy_s1_s5_L0_nxt, visibleEnergy_s1_s5_L1_nxt, visibleEnergy, visibleEnergy, visibleEnergy)
    sumOfpow2_s1_s5_nxt     = nextCondition(sumOfpow2, sumOfpow2, sumOfpow2_s1_s5_L2_nxt, sumOfpow2, sumOfpow2 )
    pow2_s1_s5_nxt          = nextCondition(pow2, pow2, pow2_s1_s5_L2_nxt, pow2, pow2)

    # before s6: store pos

    h_cnt_sp_nxt = ila.ite( h_cnt == nh , h0_16 , h_cnt + 1 )
    v_cnt_sp_nxt = ila.ite( h_cnt == nh , ila.ite( v_cnt == nv , h0_16 , v_cnt + 1 ) , v_cnt )
    _data_load   = ila.load(train_input, v_cnt[VISIBLE_UNIT_WIDTH-1:0])
    _pos_sp_cond = ( _data_load != 2 ) 
    _pos_sp_val  = ila.ite( _data_load != 0, b1, b0 ) & ila.load(hidden_unit, h_cnt[HIDDEN_UNIT_WIDTH-1:0])
    _pos_st_addr = (NUM_HIDDEN_MAX+1) * v_cnt + h_cnt    
    pos_sp_nxt   = ila.store(pos, _pos_st_addr, _pos_sp_val )
    train_pc_sp_nxt = ila.ite( (h_cnt == nh) & (v_cnt == nv), EdgeUpdateState , StorePosState) 

    # update edge : s6

    h_cnt_s6_nxt = ila.ite( h_cnt == nh , h0_16 , h_cnt + 1 )
    v_cnt_s6_nxt = ila.ite( h_cnt == nh , ila.ite( v_cnt == nv , v_cnt , v_cnt + 1 ) , v_cnt )

    _pos_ld_addr = (NUM_HIDDEN_MAX+1) * v_cnt + h_cnt    
    train_pos = ila.load(pos,_pos_ld_addr) != 0
    train_neg = ( ila.load(hidden_unit, h_cnt[HIDDEN_UNIT_WIDTH-1:0]) != 0 ) & ( ila.load(visible_unit, v_cnt[VISIBLE_UNIT_WIDTH-1:0]) != 0 )
    edge_original = ila.load(edges_mem, (NUM_HIDDEN_MAX+1) * v_cnt + h_cnt )
    edge_new =  ila.ite( (train_pos)&(~train_neg), edge_original + fpconst(LEARN_RATE, FPedge).ast , 
                ila.ite( (~train_pos)&(train_neg), edge_original - fpconst(LEARN_RATE, FPedge).ast ,
                edge_original ) )
    edge_s6_nxt = ila.store( edges_mem, (NUM_HIDDEN_MAX+1) * v_cnt + h_cnt , edge_new )
    train_pc_s6_nxt = ila.ite( (h_cnt == nh) & (v_cnt == nv), EdgeUpdateState , EdgeUpdateState) 
    # no need to jump back itself, because the flag: train_input_done is turned back to zero
    # don't forget to set back signals in Uabs ()

    train_done  = TrainUabs.getreg('train_input_done')
    train_uabs_index = TrainUabs.getreg('index')
    train_uabs_loop_count = TrainUabs.getreg('loop_count')
    train_uabs_upc = TrainUabs.getreg('upc')

    # add prefix s6 !!!
    s6_complete = (h_cnt == nh) & (v_cnt == nv )
    index_nxt_s6_nxt  = ila.ite( s6_complete, 
                        ila.ite( (train_uabs_index == nu - 1)  & (train_uabs_loop_count != nlp), 
                        h0_16,
                        train_uabs_index + 1 ) , 
                        train_uabs_index )

    # assert (train_uabs_index == ntu - 1) & (train_uabs_loop_count == nlp) should never happen

    loop_count_s6_nxt = ila.ite( s6_complete & (train_uabs_index == nu - 1)  & (train_uabs_loop_count != nlp) , train_uabs_loop_count + 1, train_uabs_loop_count )
    upc_s6_nxt = ila.ite( s6_complete, StartReadState, train_uabs_upc )
    train_input_done_s6_nxt_nxt = ila.ite( s6_complete , b0 , train_done )

    # data -> hidden_unit -> visible_unit -> edge
    # data -> edge

    # add 
    def TrainNext(e1,e2,e3, default):
        return ila.ite(SumEdge, e1, ila.ite(SumHidden, e2, ila.ite(EdgeUpdate, e3, default)))
    def TrainNextSP(e1,e2,e3,e4,default):
        return ila.ite(SumEdge, e1, ila.ite(SumHidden, e2, ila.ite(StorePos, e3, ila.ite(EdgeUpdate, e4, default))))
    def TrainChoice5(name, e1,e2, e3, default):
        return ila.choice(name, e1,e2,e3, default)
    def TrainChoice4(name, e1,e2, default):
        return ila.choice(name, e1,e2, default)
    def TrainChoice3(name, e1, default):
        return ila.choice(name, e1, default)

    TrainUabs.set_init('train_upc',   pc_init)
    TrainUabs.set_init('train_v_cnt', v_cnt_init)
    TrainUabs.set_init('train_h_cnt', h_cnt_init)

    TrainUabs.set_next('jstate',        TrainNext(jstate_s0_nxt, jstate_s1_s5_nxt, jstate, jstate))
    TrainUabs.set_next('train_sum',     TrainNext(train_sum_s0_nxt, train_sum_s1_s5_nxt, train_sum, train_sum) )
    TrainUabs.set_next('train_v_cnt',   TrainNextSP(v_cnt_s0_nxt, v_cnt_s1_s5_nxt, v_cnt_sp_nxt, v_cnt_s6_nxt, v_cnt) )
    TrainUabs.set_next('train_h_cnt',   TrainNextSP(h_cnt_s0_nxt, h_cnt_s1_s5_nxt, h_cnt_sp_nxt, h_cnt_s6_nxt, h_cnt) )
    TrainUabs.set_next('train_upc',     TrainNextSP(train_pc_s0_nxt, train_pc_s1_s5_nxt, train_pc_sp_nxt, train_pc_s6_nxt, train_pc) )

    TrainUabs.set_next('train_max',     TrainNext(train_max, train_max_s1_s5_nxt, train_max, train_max) )
    TrainUabs.set_next('hidden_unit',   TrainNext(hidden_update_s0_2, hidden_unit, hidden_unit, hidden_unit) )  
    TrainUabs.set_next('visible_unit',  TrainNext(visible_unit, visible_unit_s1_s5_nxt, visible_unit, visible_unit))
    TrainUabs.set_next('edges',         TrainNext(edges_mem, edges_mem, edge_s6_nxt, edges_mem))
    TrainUabs.set_next('index',         TrainNext(train_uabs_index,train_uabs_index, index_nxt_s6_nxt,train_uabs_index) )
    TrainUabs.set_next('loop_count',    TrainNext(train_uabs_loop_count,train_uabs_loop_count, loop_count_s6_nxt,train_uabs_loop_count) )
    TrainUabs.set_next('upc',           TrainNext(train_uabs_upc,train_uabs_upc, upc_s6_nxt,train_uabs_upc) )
    TrainUabs.set_next('train_input_done', TrainNext(train_done,train_done, train_input_done_s6_nxt_nxt, train_done) )
    # newly added
    TrainUabs.set_next('visibleEnergies', TrainNext(visibleEnergy, visibleEnergy_s1_s5_nxt, visibleEnergy, visibleEnergy) )
    TrainUabs.set_next('sumOfpow2',       TrainNext(sumOfpow2, sumOfpow2_s1_s5_nxt, sumOfpow2, sumOfpow2) )
    TrainUabs.set_next('pow2',            TrainNext(pow2,pow2_s1_s5_nxt, pow2, pow2) )
    TrainUabs.set_next('pos',           ila.ite(StorePos , pos_sp_nxt ,pos) )
    TrainUabs.set_next('per_v_pc',      TrainNext( inner_loop_pc_s0_nxt , inner_loop_pc_s1_s5_nxt, inner_loop_pc, inner_loop_pc) )


    #------------------------------------
    #  Predict UUABS
    #------------------------------------
    # data -> predict_result


    PredictUabs = uabs.add_microabstraction('predict', predict_input_done == 1)
    
    sigmoid_func = PredictUabs.fun('sigmoid', 64, [16]) # DATA_sum_, 01_D
    rand_func    = PredictUabs.fun('rand', 64, [])      # generate random number
    to_int_exp   = PredictUabs.fun('to_int_exp', 32 , [16] )  # 
    round_func   = PredictUabs.fun('round', 8, [32]) # 05_D -> u8
    divide_func  = PredictUabs.fun('divide', 64 , [32, 64] )  # dp:32_32 / sum_of_pow2 64_64 = 64_1

    hidden_unit    = PredictUabs.mem('hidden_unit',  HIDDEN_UNIT_WIDTH,  1)
    visibleEnergy  = PredictUabs.mem('visibleEnergies', KWIDTH , 16)
    predict_result = PredictUabs.getmem('predict_result')
    predict_sum    = PredictUabs.reg('predict_sum', 16)
    predict_max    = PredictUabs.reg('predict_max', 16)
    sumOfpow2      = PredictUabs.reg('sumOfpow2', 64)
    pow2           = PredictUabs.mem('pow2', KWIDTH ,32)

    predict_vector = PredictUabs.mem('predict_vector', VISIBLE_UNIT_WIDTH, 1)
    inner_loop_pc= PredictUabs.reg('per_v_pc', 4)

    count        = PredictUabs.reg('count', 8)
    jstate       = PredictUabs.reg('jstate', 16)
    expectation  = PredictUabs.reg('expectation', 32)
    prediction   = PredictUabs.reg('prediction', 8)


    predict_pc  = PredictUabs.reg('predict_upc', 4)  # Re-evaluate
    v_cnt       = PredictUabs.reg('predict_v_cnt', 16)
    h_cnt       = PredictUabs.reg('predict_h_cnt', 16)

    predict_input = PredictUabs.getmem('data')
    edges_input = PredictUabs.getmem('edges')
    nv          = PredictUabs.getreg('num_visible')
    nh          = PredictUabs.getreg('num_hidden')
    nu          = PredictUabs.getreg('num_users')
    ntu         = PredictUabs.getreg('num_testusers')
    nlp         = PredictUabs.getreg('num_loops')


    SumEdge = predict_pc == 0; SumEdgeState = const(0,4)
    SumHidden = predict_pc == 1; SumHiddenState = const(1,4)
    GenResult = predict_pc == 3; GenResultState = const(3,4)
    WaitForWrite = predict_pc == 2; WaitForWriteState = const(2,4)

    PredictUabs.decode_exprs = [SumEdge, SumHidden,  WaitForWrite ]    

    #Begin
    v_cnt_init = const(0, 16)
    h_cnt_init = const(0, 16)
    pc_init    = const(0, 4)

    #SumEdge: s0
    edge_load_addr     = (NUM_HIDDEN_MAX+1) * v_cnt + h_cnt             
    predict_sum_s0_nxt   = ila.ite(v_cnt == 0, const(0,16), predict_sum ) + ila.ite( ila.load(predict_input, v_cnt[DATAMEM_ADDR_WIDTH-1:0]) == 1, fpconvert(ila.load(edges_input,edge_load_addr ), FPedge, FPsum) , const(0,16) )
    v_cnt_s0_nxt       = ila.ite(v_cnt == nv , h0_16 , v_cnt + 1 )
    h_cnt_s0_nxt       = ila.ite( ( v_cnt == nv ) ,  ila.ite(h_cnt == nh - 1 , h0_16 , h_cnt + 1  )  , h_cnt )
    #                                                     Here ^^^ is for transiting to next state

    hidden_update_s0_0 = ila.ite( fpconst(0.5, FP01_D).ast <  ila.appfun( sigmoid_func , predict_sum_s0_nxt ) , b1 , b0)
    hidden_update_s0_1 = ila.ite( v_cnt == nv , ila.store(hidden_unit, h_cnt[HIDDEN_UNIT_WIDTH-1:0] , hidden_update_s0_0 ), hidden_unit )
    hidden_update_s0_2 = ila.ite( ( v_cnt == nv ) & (h_cnt == nh - 1 ) , ila.store(hidden_update_s0_1, nh[HIDDEN_UNIT_WIDTH-1:0], b1 ) , hidden_update_s0_1 )
    hidden_update_s0_next = hidden_update_s0_2
    predict_pc_s0_nxt  = ila.ite( ( v_cnt == nv ) & (h_cnt == nh - 1 ) , SumHiddenState , SumEdgeState )

    jstate_s0_nxt = h0_16
    count_s0_nxt   = ila.const(0,8)
    inner_loop_pc_s0_nxt = h0_4
    # add prefix : 
    # predict_sum_nxt = ila.ite(SumEdge, predict_sum_s0_nxt, ila.ite(SumHidden, ... ) )

    #-----------------------------
    # SumHiddensK0-K4 : s1-s5
    # 
    #-----------------------------

    LastH = h_cnt == nh
    LastJ = jstate == K-1
    LastV = (v_cnt + K == nv) | (v_cnt + K >= NUM_VISIBLE_MAX)
    SumHiddenL0 = SumHidden & (inner_loop_pc == 0)
    SumHiddenL1 = SumHidden & (inner_loop_pc == 1)
    SumHiddenL2 = SumHidden & (inner_loop_pc == 2)
    SumHiddenL3 = SumHidden & (inner_loop_pc == 3)
    SumHiddenL4 = SumHidden & (inner_loop_pc == 4)

    h_cnt_s1_s5_L0_nxt  = ila.ite( LastH , h0_16, h_cnt + 1)
    jstate_s1_s5_L0_nxt = ila.ite( LastH , ila.ite( LastJ, h0_16, jstate + 1 ) , jstate )
    inner_loop_pc_s1_s5_L0_nxt = ila.ite( LastJ & LastH , h1_4 , inner_loop_pc )

    jstate_s1_s5_L1_nxt = ila.ite( LastJ, h0_16, jstate + 1 )
    inner_loop_pc_s1_s5_L1_nxt = ila.ite( LastJ, h2_4, inner_loop_pc )

    jstate_s1_s5_L2_nxt = jstate_s1_s5_L1_nxt
    inner_loop_pc_s1_s5_L2_nxt = ila.ite( LastJ, h3_4, inner_loop_pc )

    jstate_s1_s5_L3_nxt = jstate_s1_s5_L2_nxt
    inner_loop_pc_s1_s5_L3_nxt = ila.ite( LastJ, h4_4, inner_loop_pc )

    jstate_s1_s5_L4_nxt = jstate_s1_s5_L3_nxt
    inner_loop_pc_s1_s5_L4_nxt = ila.ite( LastJ, 
                                 ila.ite( LastV , h0_4, h0_4  ), # will choose to go back or not
                                 inner_loop_pc )
    def nextCondition(l0,l1,l2,l3,l4,default):
        return ila.ite(SumHiddenL0, l0, ila.ite(SumHiddenL1, l1, ila.ite(SumHiddenL2, l2, ila.ite(SumHiddenL3, l3,ila.ite(SumHiddenL4, l4, default )))))
    
    h_cnt_s1_s5_nxt = nextCondition(h_cnt_s1_s5_L0_nxt,h_cnt,h_cnt,h_cnt, h_cnt, h_cnt ) 
    v_cnt_s1_s5_nxt = ila.ite(SumHiddenL4 & LastJ, ila.ite( LastV, h0_16 , v_cnt + K ), v_cnt )
    jstate_s1_s5_nxt = nextCondition(   jstate_s1_s5_L0_nxt,
                                        jstate_s1_s5_L1_nxt,
                                        jstate_s1_s5_L2_nxt,
                                        jstate_s1_s5_L3_nxt, 
                                        jstate_s1_s5_L4_nxt, 
                                        jstate ) 

    inner_loop_pc_s1_s5_nxt = nextCondition(inner_loop_pc_s1_s5_L0_nxt,
                            inner_loop_pc_s1_s5_L1_nxt, inner_loop_pc_s1_s5_L2_nxt,
                            inner_loop_pc_s1_s5_L3_nxt, inner_loop_pc_s1_s5_L4_nxt, inner_loop_pc ) 

    predict_pc_s1_s5_nxt = ila.ite(SumHiddenL4 & LastJ & LastV, GenResultState, SumHiddenState )

    # L0
    predict_sum_s1_s5_L0_nxt  = ila.ite( h_cnt == 0 , h0_16 , predict_sum ) +ila.ite( ila.load(hidden_unit, h_cnt[HIDDEN_UNIT_WIDTH-1:0]) == 1 , fpconvert( ila.load(edges_input, edge_load_addr ), FPedge, FPsum ), h0_16 )
    _predict_max_origin_L0    = ila.ite( jstate == 0,  fpconst(-500, FPsum).ast , predict_max ) # make sure the first time we are comparing with init sum
    predict_max_s1_s5_L0_nxt  = ila.ite( LastH , ila.ite( ila.sgt( predict_sum_s1_s5_L0_nxt , _predict_max_origin_L0 ) , predict_sum_s1_s5_L0_nxt , _predict_max_origin_L0) , predict_max )
    visibleEnergy_s1_s5_L0_nxt= ila.ite( LastH , ila.store( visibleEnergy, jstate[KWIDTH-1:0], predict_sum_s1_s5_L0_nxt ) , visibleEnergy )
    # L1
    # sum3: 64_64  ->   dp: 32_32
    _31_sum = fpconst(31, FPsum).ast
    predict_max_s1_s5_L1_nxt = ila.ite(jstate == 0, predict_max - _31_sum, predict_max)
    _st_val_L1 = ila.load(visibleEnergy, jstate[KWIDTH-1:0]) - predict_max_s1_s5_L1_nxt
    visibleEnergy_s1_s5_L1_nxt = ila.store( visibleEnergy, jstate[KWIDTH-1:0], _st_val_L1  )
    # L2
    _pow2_new_val = ila.appfun(to_int_exp, ila.load(visibleEnergy, jstate[KWIDTH-1:0]) )
    _pow2_new_convert = fpconvert( _pow2_new_val, FPpow, FPsum3 )
    sumOfpow2_s1_s5_L2_nxt = ila.ite( jstate == 0, h0_64, sumOfpow2 ) + _pow2_new_convert
    pow2_s1_s5_L2_nxt = ila.store( pow2, jstate[KWIDTH-1:0], _pow2_new_val )
    # L3
    _probs = ila.appfun( divide_func, [ila.load(pow2, jstate[KWIDTH-1:0]), sumOfpow2] )
    _mul   = fixpoint(_probs, FP01_D) * fixpoint(jstate, FPu16)
    expectation_s1_s5_L3_nxt = ila.ite(  jstate == 0, h0_32, expectation ) + _mul.toFormat(FP05_D)
    # L4
    _prediction = ila.zero_extend(ila.appfun(round_func, [expectation] ), 16)
    _pv_val = ila.ite( jstate == _prediction , b1, b0 )
    _pv_idx = v_cnt + jstate
    _first_store = ila.store(predict_vector, _pv_idx[VISIBLE_UNIT_WIDTH-1:0], _pv_val)
    predict_vector_s1_s5_L4_nxt = ila.ite( SumHiddenL4 & LastV & LastJ, ila.store(_first_store, nv[VISIBLE_UNIT_WIDTH-1:0], b1), _first_store) 


    predict_sum_s1_s5_nxt     = nextCondition(predict_sum_s1_s5_L0_nxt, predict_sum, predict_sum, predict_sum, predict_sum, predict_sum )
    predict_max_s1_s5_nxt     = nextCondition(predict_max_s1_s5_L0_nxt, predict_max_s1_s5_L1_nxt, predict_max, predict_max, predict_max,  predict_max )
    visibleEnergy_s1_s5_nxt = nextCondition(visibleEnergy_s1_s5_L0_nxt, visibleEnergy_s1_s5_L1_nxt, visibleEnergy, visibleEnergy,visibleEnergy,  visibleEnergy)
    sumOfpow2_s1_s5_nxt     = nextCondition(sumOfpow2, sumOfpow2, sumOfpow2_s1_s5_L2_nxt, sumOfpow2, sumOfpow2, sumOfpow2 )
    pow2_s1_s5_nxt          = nextCondition(pow2, pow2, pow2_s1_s5_L2_nxt, pow2, pow2, pow2)
    expectation_s1_s5_nxt   = ila.ite(SumHiddenL3, expectation_s1_s5_L3_nxt, expectation)
    predict_vector_s1_s5_nxt= ila.ite(SumHiddenL4, predict_vector_s1_s5_L4_nxt, predict_vector)
    count_s1_s5_nxt         = ila.ite(SumHiddenL4 & LastV & LastJ , h0_8, count )

    # before s6: store pos
    LastV = (v_cnt + K == nv) | (v_cnt + K >= NUM_VISIBLE_MAX)
    LastJ = jstate == K-1
    v_cnt_sp_nxt = ila.ite(LastV, v_cnt + K, v_cnt + K)
    jstate_sp_nxt = ila.ite( LastJ, h0_16, jstate + 1 ) 

    _prediction_old = ila.ite(jstate == 0, h0_8, prediction)
    _pv_idx = v_cnt + jstate
    _predict_result_sp_val = ila.load(predict_vector, _pv_idx[VISIBLE_UNIT_WIDTH-1:0] )

    prediction_sp_nxt = ila.ite( _predict_result_sp_val == 1, (jstate + 1)[7:0], _prediction_old )
    count_sp_nxt = ila.ite(LastJ, count + 1 , count)
    predict_result_sp_nxt = ila.ite(LastJ, ila.store(predict_result, count[PREDICT_RESULT_WIDTH-1:0], prediction), predict_result)
    predict_pc_sp_nxt = ila.ite(LastV & LastJ, WaitForWriteState, GenResultState)

    wr_complete = PredictUabs.getreg('wr_complete')
    wr_req      = PredictUabs.getreg('wr_request')
    wr_len      = PredictUabs.getreg('wr_length')
    wr_idx      = PredictUabs.getreg('wr_index')
    cur_idx     = PredictUabs.getreg('index') # 32

    exitLoop = LastV & LastJ
    wr_request_sp_nxt = ila.ite( exitLoop , b1, wr_req) 
    wr_index_sp_nxt   = ila.ite( exitLoop , ila.zero_extend(nm, 32) * ila.zero_extend(cur_idx,32), wr_idx )
    wr_length_sp_nxt  = ila.ite( exitLoop , ila.zero_extend(nm, 32), wr_len) 
    wr_complete_sp_nxt= ila.ite( exitLoop , b0, wr_complete)
    # s6: 

    #---------------------
    # update edge : s6
    #---------------------

    FinishOneRound = ( wr_req == 0 ) & ( wr_complete == 1 )

    predict_pc_s6_nxt = ila.ite( FinishOneRound , WaitForWriteState , WaitForWriteState )
    # its value does not matter because it will be terminated by predict_input_done
    # don't forget to set back signals in Uabs ()

    predict_done  = PredictUabs.getreg('predict_input_done')
    predict_uabs_index = PredictUabs.getreg('index')
    predict_uabs_loop_count = PredictUabs.getreg('loop_count')
    predict_uabs_upc = PredictUabs.getreg('upc')
    all_done = PredictUabs.getreg('done')

    # add prefix s6 !!!
    index_nxt_s6_nxt = ila.ite( FinishOneRound , 
                       ila.ite( (predict_uabs_index == ntu - 1) & (predict_uabs_loop_count == nlp), 
                       predict_uabs_index,
                       predict_uabs_index + 1 ),
                       predict_uabs_index ) 

    wr_complete_s6_nxt = ila.ite( FinishOneRound , b0 , wr_complete )
    # assert (predict_uabs_index == nu - 1)  & (predict_uabs_loop_count != nlp) should never happen

    #loop_count_s6_nxt = ila.ite( (predict_uabs_index == nu - 1)  & (predict_uabs_loop_count != nlp) , predict_uabs_loop_count + 1, predict_uabs_loop_count )

    upc_s6_nxt = ila.ite( FinishOneRound, ila.ite( (predict_uabs_index == ntu - 1) & (predict_uabs_loop_count == nlp) , FinishState ,StartReadState) , predict_uabs_upc )
    predict_input_done_s6_nxt_nxt = ila.ite( FinishOneRound , b0 , predict_done )

    all_done_s6_nxt = ila.ite( FinishOneRound &  (predict_uabs_index == ntu - 1) & (predict_uabs_loop_count == nlp), b1, b0 )
    # data -> hidden_unit -> visible_unit -> edge
    # data -> edge

    # add

    # add 
    def predictNext(e1,e2,e3, default):
        return ila.ite(SumEdge, e1, ila.ite(SumHidden, e2, ila.ite(WaitForWrite, e3, default)))
    def predictNextSp(e1,e2,e3,e4,default):
        return ila.ite(SumEdge, e1, ila.ite(SumHidden, e2, ila.ite( GenResult, e3 ,ila.ite(WaitForWrite, e4, default))))
    def ite(inst,e,default):
        return ila.ite(inst,e,default)

    PredictUabs.set_init('predict_upc', pc_init)
    PredictUabs.set_init('predict_v_cnt', v_cnt_init)
    PredictUabs.set_init('predict_h_cnt', h_cnt_init)

    PredictUabs.set_next('jstate', predictNextSp(jstate_s0_nxt, jstate_s1_s5_nxt, jstate_sp_nxt ,jstate, jstate))
    PredictUabs.set_next('predict_sum', predictNext(predict_sum_s0_nxt, predict_sum_s1_s5_nxt, predict_sum, predict_sum) )
    PredictUabs.set_next('predict_v_cnt', predictNextSp(v_cnt_s0_nxt, v_cnt_s1_s5_nxt, v_cnt_sp_nxt ,v_cnt, v_cnt) )
    PredictUabs.set_next('predict_h_cnt', predictNext(h_cnt_s0_nxt, h_cnt_s1_s5_nxt, h_cnt, h_cnt) )
    PredictUabs.set_next('predict_upc', predictNextSp(predict_pc_s0_nxt, predict_pc_s1_s5_nxt, predict_pc_sp_nxt ,predict_pc_s6_nxt, predict_pc) )
    PredictUabs.set_next('predict_max', predictNext(predict_max, predict_max_s1_s5_nxt, predict_max, predict_max) )
    PredictUabs.set_next('hidden_unit', predictNext(hidden_update_s0_2, hidden_unit, hidden_unit, hidden_unit) ) 
    PredictUabs.set_next('count', predictNextSp(count_s0_nxt, count_s1_s5_nxt, count_sp_nxt, count, count) )
    PredictUabs.set_next('per_v_pc', predictNext(inner_loop_pc_s0_nxt, inner_loop_pc_s1_s5_nxt, inner_loop_pc, inner_loop_pc ) )
 
    PredictUabs.set_next('index', predictNext(predict_uabs_index,predict_uabs_index, index_nxt_s6_nxt,predict_uabs_index) )
    PredictUabs.set_next('upc', predictNext(predict_uabs_upc,predict_uabs_upc, upc_s6_nxt,predict_uabs_upc) )
    PredictUabs.set_next('predict_input_done', predictNext(predict_done,predict_done, predict_input_done_s6_nxt_nxt, predict_done) )
    PredictUabs.set_next('done', predictNext(all_done, all_done, all_done_s6_nxt, all_done) )

    PredictUabs.set_next('wr_request', predictNextSp(wr_req, wr_req ,wr_request_sp_nxt , wr_req, wr_req) )
    PredictUabs.set_next('wr_length',  predictNextSp(wr_len, wr_len ,wr_length_sp_nxt, wr_len, wr_len ) )
    PredictUabs.set_next('wr_index',   predictNextSp(wr_idx, wr_idx ,wr_index_sp_nxt, wr_idx, wr_idx ) )
    PredictUabs.set_next('wr_complete', predictNextSp(wr_complete, wr_complete, wr_complete_sp_nxt, wr_complete_s6_nxt, wr_complete) )
    # newly added
    PredictUabs.set_next('visibleEnergies', predictNext(visibleEnergy, visibleEnergy_s1_s5_nxt, visibleEnergy, visibleEnergy) )
    PredictUabs.set_next('sumOfpow2',       predictNext(sumOfpow2, sumOfpow2_s1_s5_nxt, sumOfpow2, sumOfpow2) )
    PredictUabs.set_next('pow2',            predictNext(pow2,pow2_s1_s5_nxt, pow2, pow2) )
    PredictUabs.set_next('expectation',     predictNext(expectation,expectation_s1_s5_nxt, expectation, expectation) )
    PredictUabs.set_next('predict_vector',  predictNext(predict_vector,predict_vector_s1_s5_nxt,predict_vector,predict_vector) )
    PredictUabs.set_next('prediction',      ite(GenResult,prediction_sp_nxt,prediction) )
    PredictUabs.set_next('predict_result',  ite(GenResult,predict_result_sp_nxt,predict_result) )



    #------------------------------------
    #  Store UABS
    #------------------------------------
    # store is triggered by inst as uabs?

    # wr_grant == 1 is an instruction
    wr_granted = rbm.reg('wr_granted', 1)
    rbm.set_next('wr_granted', ila.ite((wr_request & wr_grant) == 1, b1, wr_granted ) )
    data_out_1st_set = ila.zero_extend(ila.load(predict_result, const(0,PREDICT_RESULT_WIDTH) ) , 32)
    rbm.set_next('data_out', ila.ite((wr_request & wr_grant) == 1,  data_out_1st_set, data_out))
    # This is a hard decision, 
    # as we set_next, the reaction as we defined will be appear in the next cycle

    StoreUabs = rbm.add_microabstraction('store', wr_granted == 1)
    store_idx = StoreUabs.reg('i', 16)
    nm = StoreUabs.getreg('num_movies')
    wr_granted = StoreUabs.getreg('wr_granted')
    wr_request = StoreUabs.getreg('wr_request')
    wr_complete = StoreUabs.getreg('wr_complete')
    predict_result = StoreUabs.getmem('predict_result')

    StoreUabs.set_init('i', h1_16)
    StoreUabs.set_next('i', ila.ite(store_idx < nm , store_idx + 1 , store_idx ) )
    StoreUabs.set_next('wr_granted', ila.ite( store_idx < nm , wr_granted , b0 ) )
    StoreUabs.set_next('wr_request', ila.ite( store_idx == 0 , b0 , wr_request) )
    StoreUabs.set_next('wr_complete', ila.ite( store_idx < nm , wr_complete , b1) )
    data_out = StoreUabs.getreg('data_out')
    # possibly one cycle earlier
    StoreUabs.set_next('data_out', ila.zero_extend(ila.load(predict_result, store_idx[PREDICT_RESULT_WIDTH-1:0]) , 32) )


    #---------------------------
    # Add no next 
    #
    def keepNC(Abs,name):
        Abs.set_next(name, Abs.getreg(name))
    def keepMemNC(Abs,name):
        Abs.set_next(name, Abs.getmem(name))
    keepNC(rbm,'done')
    keepNC(rbm,'wr_request')
    keepNC(rbm,'wr_index')
    keepNC(rbm,'wr_length')
    keepNC(rbm,'rd_index')
    keepNC(rbm,'rd_length')
    keepNC(rbm,'rd_request')

    keepMemNC(uabs,'edges')

    keepNC(rbm,'rd_complete')
    keepNC(rbm,'wr_complete')

    return rbm

if __name__ == '__main__':
    rbm = buildILA()
