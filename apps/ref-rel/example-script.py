import ila

def CreateVerilogVerificationWrapper():
    ref_spec = ila.ReadRefinement("example-Ila.json")
    ref_impl = ila.ReadRefinement("example-Verilog.json")
    rel = ila.ReadRelation("example-mapping.json")

    ila.GenVerilogWrapper(ref_spec, ref_impl, rel)

def IlaEqCheck():
    ref_spec = ila.ReadRefinement("example-Ila.json")
    ref_impl = ila.ReadRefinement("example-Ila2.json")
    rel - ila.ReadRelation("example-mapping2.json")

    res = ila.EqCheck(ref_spec, ref_impl, rel, 10) # max bound 10

"""
Old example:
"""
def GetRefinementOfIla(""" ILA """ m):
    # create a refinement mapping object for the ILA 
    # extract model info for checking
    ref = ila.NewRefinementFromILA(m)

    # get state variables of the model
    st = ref.GetStateVars()

    # specify how to apply the instruction
    ref.apply = m.Instr("start").Decode() 

    # specify when does the instruction complete 
    ref.complete = (st["ready"] == 1)

    # [optional] specify how to flush the state machine (w/ child-ILAs)
    ref.flush = (st["cmd"] == 0)

    # [optional] provide invariants
    inv_valid_cnt = (st["counter"] >= 0 & st["counter"] < 8)
    ref.AddInvariant(inv_valid_cnt)


def GetRefinementOfVerilog(""" directory path """ vmod_path):
    # create a refinement mapping object for the verilog model 
    # extract model info for checking 
    ref = ila.NewRefinementFromVerilog(vmod_path)

    # get state variables of the model
    st = ref.GetStateVars()

    # specify how to apply the instruction
    ref.apply = (st["top.cmd"] == 1 & st["top.in_addr"] == 0xff00)

    # specify when does the instruction complete
    ref.complete = (st["top.ctrl.status"] == 1) # specify by condition
    ref.complete_step_num = 4                   # specify by the step bound
    ref.complete = (st["monitor.done"] == 1)    # user-provided monitor

    # [optional] specify how to flush the state machine (if not one cycle)
    ref.clock = st["top.clk"] # Verilog only (do we need this?)
    ref.flush = (st["top.in_valid"] == 0 & st["top.interrupt"] = 0)

    # [optional] provide invariants
    inv_valid_cnt = (st["top.ctrl.cnt"] >= 0 & st["top.ctrl.cnt"] < 8)
    ref.AddInvariant(inv_valid_cnt)

    return ref

def GetRelation(""" refinements """ ref_ila, ref_vmod):
    # create a relation (state mapping) between two refinement object
    rel = ila.NewRelation(ref_ila, ref_vmod)
    st_i = ref_ila.GetStateVars()
    st_v = ref_vmod.GetStateVars()

    # specify state mapping in terms of constraints
    cnt_eq = (st_i["counter"] == st_v["top.ctrl.cnt"])
    data_eq = (st_i["data"] == ila.concat(st_v["top.data.reg0"], st_v["top.data.reg1"]))
    rel.AddMapping(cnt_eq)
    rel.AddMapping(data_eq)

    return rel

def GenerateVerilogWrapper():
    ref_i = GetRefinementOfIla(spec_ila)
    ref_v = GetRefinementOfVerilog(impl_vmod_path)
    rel = GetRelation(ref_i, ref_v)

    # [optional] simplify by only including the target instruction 
    ref_i.Simplify(spec_ila.Instr("start"))

    ila.GenVerilogWrapper(ref_i, ref_v, rel, out_path)


def EqCheck():
    ref_spec = GetRefinementOfIla(spec_ila)
    ref_impl = GetRefinementOfIla(impl_ila)
    rel = GetRelation(ref_spec, ref_impl)

    # perform BMC up to 10 steps
    ila.EqCheck(ref_spec, ref_impl, rel, 10)

