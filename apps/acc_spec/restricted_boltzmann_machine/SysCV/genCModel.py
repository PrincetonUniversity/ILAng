import rbm_template
import os

def genCModel(rbm):
    rbm.generateSimToDir("Cmodel/rbm")

def genLoad(rbm):
    dname = 'load'
    os.system('mkdir Cmodel/{0}'.format(dname))

    load = rbm.get_microabstraction('DMAload')
    load.generateSimToDir( "Cmodel/{0}".format(dname) )

    os.system('mkdir Cmodel/{0}_mod'.format(dname))
    os.system('cp -r Cmodel/{0}/ Cmodel/{0}_mod/'.format(dname))
    os.system('cp Cmodel/rbm_mod/common.hpp Cmodel/{0}_mod/'.format(dname))

def genStore(rbm):
    dname = 'store'
    os.system('mkdir Cmodel/{0}'.format(dname))

    store = rbm.get_microabstraction('store')
    store.generateSimToDir( "Cmodel/{0}".format(dname) )

    os.system('mkdir Cmodel/{0}_mod'.format(dname))
    os.system('cp Cmodel/{0}/* Cmodel/{0}_mod/'.format(dname))
    os.system('cp Cmodel/rbm_mod/common.hpp Cmodel/{0}_mod/'.format(dname))


def genCompute(rbm):
    dname = 'compute'
    os.system('mkdir Cmodel/{0}'.format(dname))

    uabs = rbm.get_microabstraction('compute')
    uabs.generateSimToDir( "Cmodel/{0}".format(dname) )

    os.system('mkdir Cmodel/{0}_mod'.format(dname))
    os.system('cp Cmodel/{0}/* Cmodel/{0}_mod/'.format(dname))
    os.system('cp Cmodel/rbm_mod/common.hpp Cmodel/{0}_mod/'.format(dname))

def genTrain(rbm):
    dname = 'train'
    os.system('mkdir Cmodel/{0}'.format(dname))

    uabs  = rbm.get_microabstraction('compute')
    train = uabs.get_microabstraction('train')
    train.generateSimToDir( "Cmodel/{0}".format(dname) )

    os.system('mkdir Cmodel/{0}_mod'.format(dname))
    os.system('cp Cmodel/{0}/* Cmodel/{0}_mod/'.format(dname))
    os.system('cp Cmodel/rbm_mod/common.hpp Cmodel/{0}_mod/'.format(dname))

def genPredict(rbm):
    dname = 'predict'
    os.system('mkdir Cmodel/{0}'.format(dname))

    uabs  = rbm.get_microabstraction('compute')
    predict = uabs.get_microabstraction('predict')
    predict.generateSimToDir( "Cmodel/{0}".format(dname) )

    os.system('mkdir Cmodel/{0}_mod'.format(dname))
    os.system('cp Cmodel/{0}/* Cmodel/{0}_mod/'.format(dname))
    os.system('cp Cmodel/rbm_mod/common.hpp Cmodel/{0}_mod/'.format(dname))

def genPredictMod(rbm):
    dname = 'predict'
    os.system('mkdir Cmodel/{0}'.format(dname))
    uabs  = rbm.get_microabstraction('compute')
    predict = uabs.get_microabstraction('predict')
    
    jstate_next = predict.get_next('jstate')
    per_v_pc_next = predict.get_next('per_v_pc')
    train_upc_next = predict.get_next('predict_upc')
    
    predict.exportOne(jstate_next,'pdb1_j.ila')
    predict.exportOne(per_v_pc_next,'pdb1_v.ila')
    predict.exportOne(train_upc_next,'pdb1_t.ila')
    
    jstate_next = predict.importOne('pdb1_j.ila')
    per_v_pc_next = predict.importOne('pdb1_v.ila')
    train_upc_next = predict.importOne('pdb1_t.ila')
    
    predict.set_next('jstate',   jstate_next)   
    predict.set_next('per_v_pc', per_v_pc_next)
    predict.set_next('predict_upc',train_upc_next)
    
    predict.generateSimToDir( "Cmodel/{0}".format(dname) )



rbm = rbm_template.buildILA()
genPredictMod(rbm)
#genCModel(rbm)
#genLoad(rbm)
#genStore(rbm)
#genCompute(rbm)
#genTrain(rbm)
#genPredict(rbm)
