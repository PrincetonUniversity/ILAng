/// \file Source for Verilog Verification Targets Generation (single target)
///
// --- Hongce Zhang

#include <ilang/ila/expr_fuse.h>
#include <ilang/util/container_shortcut.h>
#include <ilang/util/fs.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>
#include <ilang/vtarget-out/vtarget_gen_impl.h>

#include <cmath>
#include <fstream>
#include <iostream>

namespace ilang {

// ------------------------------ CONFIGURATIONS
// --------------------------------- //

#define MAX_CYCLE_CTR 127
#define VLG_TRUE "`true"
#define VLG_FALSE "`false"
#define ONLY_INITIAL_INV true
#define IntToStr(x) (std::to_string(x))

// ------------------------------ VlgSglTgtGen ---------------------------------
// //

VlgSglTgtGen::VlgSglTgtGen(
    const std::string&
        output_path, // will be a sub directory of the output_path of its parent
    const InstrPtr& instr_ptr, // which could be an empty pointer, and it will
                               // be used to verify invariants
    const InstrLvlAbsPtr& ila_ptr, const VerilogGenerator::VlgGenConfig& config,
    nlohmann::json& _rf_vmap, nlohmann::json& _rf_cond,
    VerilogInfo* _vlg_info_ptr, const std::string& vlg_mod_inst_name,
    const std::string& ila_mod_inst_name, const std::string& wrapper_name,
    const std::vector<std::string>& implementation_srcs,
    const std::vector<std::string>& implementation_include_path,
    const vtg_config_t & vtg_config,
    backend_selector backend)
    : _output_path(output_path), _instr_ptr(instr_ptr), _host(ila_ptr),
      _vlg_mod_inst_name(vlg_mod_inst_name),
      _ila_mod_inst_name(ila_mod_inst_name),
      // default option on wrapper
      vlg_wrapper(VerilogGenerator::VlgGenConfig(
                      config, // use default configuration
                      true,   // except overwriting these: external memory
                      VerilogGeneratorBase::VlgGenConfig::funcOption::
                          External, // function
                      false),       // no start signal
                  wrapper_name),
      // use given, except for core options
      vlg_ila(VerilogGeneratorBase::VlgGenConfig(
          config, true,
          VerilogGeneratorBase::VlgGenConfig::funcOption::External, true)),
      // interface mapping directive
      _idr(instr_ptr == nullptr ? true
                                : false), // if nullptr, verify inv., reset it
      // state mapping directive
      _sdr(), // currently no
      // verilog info
      vlg_info_ptr(_vlg_info_ptr),
      // variable extractor
      _vext(
          [this](const std::string& n) -> bool { return TryFindIlaState(n); },
          [this](const std::string& n) -> bool { return TryFindIlaInput(n); },
          [this](const std::string& n) -> bool { return TryFindVlgState(n); }),
      // ref to refmaps
      rf_vmap(_rf_vmap), rf_cond(_rf_cond), empty_json(nullptr),
      target_type(instr_ptr == nullptr
                      ? target_type_t::INVARIANTS
                      : target_type_t::INSTRUCTIONS), // whether it is
                                                      // invariant/instructions
      has_flush(false), ready_type(ready_type_t::NA), mapping_counter(0),
      property_counter(0), top_mod_name(wrapper_name),
      vlg_design_files(implementation_srcs),
      vlg_include_files_path(implementation_include_path), 
      _vtg_config(vtg_config),
      _backend(backend),
      _bad_state(false) {
  ILA_NOT_NULL(_host);

  if (target_type == target_type_t::INSTRUCTIONS) {

    vlg_ila.ExportTopLevelInstr(instr_ptr);
    if (vlg_ila.decodeNames.size() != 1) {
      ILA_ERROR << "Implementation bug btw. vlg gen and vtarget-gen";
      _bad_state = true;
    }

    auto& instr = get_current_instruction_rf();
    if (instr.is_null()) {
      ILA_ERROR << "No refinement relation is defined for current instruction:"
                << instr_ptr->name().str();
      _bad_state = true;
    }
    // check for fields in
    if (not IN("instruction", instr) or not instr["instruction"].is_string()) {
      ILA_ERROR << "RF: instruction field must be a string for "
                << instr_ptr->name().str();
      _bad_state = true;
    }

    if (IN("flush constraint", instr) and
        not instr["flush constraint"].is_array()) {
      ILA_ERROR
          << "RF: 'flush constraint' filed must be an array of string for "
          << instr_ptr->name().str();
      _bad_state = true;
    }

    if (IN("pre-flush end", instr) and not instr["pre-flush end"].is_array()) {
      ILA_ERROR << "RF: 'pre-flush end' filed must be an array of string for "
                << instr_ptr->name().str();
      _bad_state = true;
    }

    if (IN("post-flush end", instr) and
        not instr["post-flush end"].is_array()) {
      ILA_ERROR << "RF: 'post-flush end' filed must be an array of string for "
                << instr_ptr->name().str();
      _bad_state = true;
    }

    if (IN("flush constraint", instr) and
        instr["flush constraint"].size() != 0) {
      if (IN("pre-flush end", instr) and instr["pre-flush end"].size() != 0 and
          IN("post-flush end", instr) and instr["post-flush end"].size() != 0)
        has_flush = true; // requiring three items
      else {
        ILA_ERROR
            << "When using flushing, 'pre-flush end' and 'post-flush end' "
            << "must be specify";
        _bad_state = true;
      }
    }

    if (IN("ready signal", instr) and
        instr["ready signal"].size() !=
            0) // whether a none-empty string or array...
      ready_type = (ready_type_t)(ready_type | ready_type_t::READY_SIGNAL);
    if (IN("ready bound", instr) and instr["ready bound"].is_number_integer())
      ready_type = (ready_type_t)(ready_type | ready_type_t::READY_BOUND);
    if (ready_type == ready_type_t::NA) {
      ILA_ERROR << "refinement relation for:" << instr_ptr->name().str()
                << " has to specify a ready condition";
      _bad_state = true;
    }
  }
} // END of constructor

void VlgSglTgtGen::ConstructWrapper_add_ila_input() {
  // add ila input
  size_t ila_input_num = _host->input_num();
  for (size_t input_idx = 0; input_idx < ila_input_num; input_idx++) {
    const auto& input_ = _host->input(input_idx);
    const auto& name_ = input_->name().str();
    auto width_ = get_width(input_);

    vlg_wrapper.add_wire("__ILA_I_" + name_, width_, true);
    vlg_wrapper.add_input("__ILA_I_" + name_, width_);
  }
  // remember to add ila_outputs (reg)
  size_t ila_state_num = _host->state_num();
  for (size_t state_idx = 0; state_idx < ila_state_num; ++state_idx) {
    const auto& state_ = _host->state(state_idx);
    const auto& name_ = state_->name().str();
    if (state_->sort()->is_mem())
      continue; // please ignore memory, they should not be connected this way
    auto width_ = get_width(state_);

    vlg_wrapper.add_wire("__ILA_SO_" + name_, width_, true);
    vlg_wrapper.add_output("__ILA_SO_" + name_, width_);
    // remember to connect in the instantiation step
  }
} // ConstructWrapper_add_ila_input

std::string VlgSglTgtGen::ConstructWrapper_get_ila_module_inst() {
  if (target_type == target_type_t::INVARIANTS)
    return "";

  ILA_ASSERT(vlg_ila.decodeNames.size() == 1)
      << "Implementation bug: decode condition.";
  vlg_wrapper.add_wire(vlg_ila.validName, 1, true);
  vlg_wrapper.add_wire(vlg_ila.decodeNames[0], 1, true);

  // TODO: check whether all ports have been dealt with
  // TODO: check whether there are any extra ports we create
  std::set<std::string> port_connected; // store the name of ila port
  std::set<std::string> port_of_ila;    // store the name of ila port also

  // .. record function
  auto retStr = vlg_ila.moduleName + " " + _ila_mod_inst_name + " (\n";

  std::set<std::string> func_port_skip_set;
  for (auto&& func_app : vlg_ila.ila_func_app) {
    func_port_skip_set.insert(func_app.result.first);
    port_connected.insert(func_app.result.first);
    /// new reg : put in when __START__
    unsigned func_no = func_cnt[func_app.func_name]++;

    std::string func_reg_w =
        func_app.func_name + "_" + IntToStr(func_no) + "_result_wire";
    std::string func_reg =
        func_app.func_name + "_" + IntToStr(func_no) + "_result_reg";
    vlg_wrapper.add_reg(func_reg, func_app.result.second);
    vlg_wrapper.add_wire(func_reg_w, func_app.result.second, true);
    add_reg_cassign_assumption("__START__", func_reg, func_reg_w,
                               "func_result");
    // vlg_wrapper.add_always_stmt( "if( __START__ ) " + func_reg + " <= " +
    // func_reg_w + ";" );

    retStr += "   ." + func_app.result.first + "(" + func_reg_w + "),\n";

    unsigned argNo = 0;
    for (auto&& arg : func_app.args) {
      func_port_skip_set.insert(arg.first);
      port_connected.insert(arg.first);

      std::string func_arg_w = func_app.func_name + "_" + IntToStr(func_no) +
                               "_arg" + IntToStr(argNo) + "_wire";
      std::string func_arg = func_app.func_name + "_" + IntToStr(func_no) +
                             "_arg" + IntToStr(argNo) + "_reg";
      vlg_wrapper.add_reg(func_arg, arg.second);
      vlg_wrapper.add_wire(func_arg_w, arg.second, true);
      add_reg_cassign_assumption("__START__", func_arg, func_arg_w, "func_arg");
      // vlg_wrapper.add_always_stmt( "if( __START__ ) " + func_arg + " <= " +
      // func_arg_w + ";" );

      retStr += "   ." + arg.first + "(" + func_arg_w + "),\n";
      argNo++;
    }
  }

  // handle input
  for (auto&& w : vlg_ila.inputs) {
    if (IN(w.first, func_port_skip_set))
      continue;
    // w.first will be connected
    port_connected.insert(w.first);
    // deal w. clock and reset and start
    if (w.first == vlg_ila.clkName) // .clk(clk)
      retStr += "   ." + vlg_ila.clkName + "(" + vlg_wrapper.clkName + "),\n";
    else if (w.first ==
             vlg_ila.rstName) // .rst(rst) -- this does not need to be changed
      retStr += "   ." + vlg_ila.rstName + "(" + vlg_wrapper.rstName +
                "),\n";                    // no init anyway!
    else if (w.first == vlg_ila.startName) {  // .__START__(__START__)
      retStr +=
          "   ." + vlg_ila.startName + "(" + "__START__" + "),\n";
    }
    else {
      ILA_ERROR_IF( not IN ("__ILA_I_" + w.first , vlg_wrapper.wires) ) << "__ILA_I_" + w.first << " has not been defined yet";
      retStr += "   ." + w.first + "(__ILA_I_" + w.first + "),\n";
    }
  }

  // TODO:: FUnction here !
  // handle output
  for (auto&& w : vlg_ila.outputs) {
    if (IN(w.first, func_port_skip_set))
      continue;
    // w.first will be connected
    port_connected.insert(w.first);
    // deal w. valid and decode
    if (w.first == vlg_ila.decodeNames[0])
      retStr += "   ." + vlg_ila.decodeNames[0] + "(" + vlg_ila.decodeNames[0] +
                "),\n";
    else if (w.first == vlg_ila.validName)
      retStr += "   ." + vlg_ila.validName + "(" + vlg_ila.validName + "),\n";
    else {
      //ILA_ERROR_IF( not IN ("__ILA_I_" + w.first , vlg_wrapper.wires) ) << "__ILA_I_" + w.first << " has not been defined yet";
      ILA_ERROR << "Does not know how to connect:"<< w.first <<", ignored.";
      //std::cout<< w.first<<std::endl;
      retStr += "   ." + w.first + "(),\n"; // __ILA_I_" + w.first + "
    }
  }

  // handle memory io - use internal storage for this purpose
  for (auto&& ila_name_rport_pair : vlg_ila.ila_rports) {
    const auto& ila_name = ila_name_rport_pair.first;
    const auto& rports = ila_name_rport_pair.second;
    const auto adw = GetMemInfo(ila_name);
    auto aw = adw.first;
    auto dw = adw.second; // address/data width
    ILA_ASSERT(aw > 0 and dw > 0)
        << "Implementation bug: unable to find mem:" << ila_name;

    for (auto&& rport : rports) {
      auto no = rport.first;    // is the num
      auto port = rport.second; // is the port
      auto rdw = "__IMEM_" + ila_name + "_" + IntToStr(no) + "_rdata";
      auto raw = "__IMEM_" + ila_name + "_" + IntToStr(no) + "_raddr";
      // auto rew = "__IMEM_" + ila_name + "_" + IntToStr(no) + "_ren"; no need,
      // r_en is the start signal

      vlg_wrapper.add_wire(rdw, dw, true);
      vlg_wrapper.add_wire(raw, aw, true);

      retStr += "   ." + port.rdata + "(" + rdw + "),\n";
      retStr += "   ." + port.raddr + "(" + raw + "),\n";

      // port.rdata/raddr will be connected
      port_connected.insert(port.rdata);
      port_connected.insert(port.raddr);

    } // for rport
  }   // for ila_rports

  for (auto&& ila_name_wport_pair : vlg_ila.ila_wports) {

    const auto& ila_name = ila_name_wport_pair.first;
    const auto& wports = ila_name_wport_pair.second;
    const auto adw = GetMemInfo(ila_name);
    auto aw = adw.first;
    auto dw = adw.second; // address/data width
    ILA_ASSERT(aw > 0 and dw > 0)
        << "Implementation bug: unable to find mem:" << ila_name;

    for (auto&& wport : wports) {
      auto no = wport.first;    // is the num
      auto port = wport.second; // is the port
      auto wdw = "__IMEM_" + ila_name + "_" + IntToStr(no) + "_wdata";
      auto waw = "__IMEM_" + ila_name + "_" + IntToStr(no) + "_waddr";
      auto wew = "__IMEM_" + ila_name + "_" + IntToStr(no) + "_wen";

      vlg_wrapper.add_wire(wdw, dw, true);
      vlg_wrapper.add_wire(wdw, aw, true);
      vlg_wrapper.add_wire(wew, 1, true);

      retStr += "   ." + port.wdata + "(" + wdw + "),\n";
      retStr += "   ." + port.waddr + "(" + waw + "),\n";
      retStr += "   ." + port.wen + "(" + wew + "),\n";

      // port.rdata/raddr will be connected
      port_connected.insert(port.wdata);
      port_connected.insert(port.waddr);
      port_connected.insert(port.wen);

    } // for wport
  }   // for ila_wports

  // handle state-output
  std::string sep;
  for (auto&& r : vlg_ila.regs) {
    if( not IN ("__ILA_SO_" + r.first , vlg_wrapper.wires) ) {
      ILA_WARN << "__ILA_SO_" + r.first << " will be ignored";

      retStr += sep + "   ." + r.first + "()"; // __ILA_SO_" + r.first + "
      port_connected.insert(r.first);
      sep = ",\n";
      continue;
    } // else
    retStr += sep + "   ." + r.first + "(__ILA_SO_" + r.first + ")";
    sep = ",\n";
    // reg out will be connected
    port_connected.insert(r.first);
  }
  retStr += "\n);";
  // TODO: check port_conencted and port_ila
  // currently not
  return retStr;
} // ConstructWrapper_get_ila_module_inst()

void VlgSglTgtGen::ConstructWrapper_add_vlg_input_output() {

  auto vlg_inputs = vlg_info_ptr->get_top_module_io();
  auto& io_map = rf_vmap["interface mapping"];
  for (auto&& name_siginfo_pair : vlg_inputs) {
    std::string refstr =
        IN(name_siginfo_pair.first, io_map)
            ? io_map[name_siginfo_pair.first].get<std::string>()
            : "";
    _idr.RegisterInterface(
        name_siginfo_pair.second, refstr,
        // Verifier_compatible_w_ila_input
        [this](const std::string& ila_name,
               const SignalInfoBase& vlg_sig_info) -> bool {
          return TypeMatched(IlaGetInput(ila_name), vlg_sig_info) != 0;
        },
        // no need to worry about the nullptr in IlaGetInput, TypeMatched will
        // be able to handle.
        // Verifier_get_ila_mem_info
        [this](
            const std::string& ila_mem_name) -> std::pair<unsigned, unsigned> {
          return GetMemInfo(ila_mem_name);
        }); // end of function call: RegisterInterface
  }
} // ConstructWrapper_add_vlg_input_output

void VlgSglTgtGen::ConstructWrapper_add_cycle_count_moniter() {
  // find in rf_cond, how many cycles will be needed
  max_bound = 0;

  auto& instr = get_current_instruction_rf();

  if (!instr.is_null() and IN("ready bound", instr) and
      instr["ready bound"].is_number_integer())
    max_bound = instr["ready bound"].get<int>();
  else
    max_bound = MAX_CYCLE_CTR;

  cnt_width = (int)std::ceil(std::log2(max_bound + 10));
  vlg_wrapper.add_reg("__CYCLE_CNT__",
                      cnt_width); // by default it will be an output reg
  vlg_wrapper.add_stmt("always @(posedge clk) begin");
  vlg_wrapper.add_stmt("if (rst) __CYCLE_CNT__ <= 0;");
  vlg_wrapper.add_stmt(
      "else if ( ( __START__ || __STARTED__ ) &&  __CYCLE_CNT__ < " +
      IntToStr(max_bound + 5) + ") __CYCLE_CNT__ <= __CYCLE_CNT__ + 1;");
  vlg_wrapper.add_stmt("end");

  vlg_wrapper.add_reg("__START__", 1);
  vlg_wrapper.add_stmt("always @(posedge clk) begin");
  vlg_wrapper.add_stmt("if (rst) __START__ <= 0;");
  vlg_wrapper.add_stmt("else if (__START__ || __STARTED__) __START__ <= 0;");
  vlg_wrapper.add_stmt("else if (__ISSUE__) __START__ <= 1;");
  vlg_wrapper.add_stmt("end");

  vlg_wrapper.add_reg("__STARTED__", 1);
  vlg_wrapper.add_stmt("always @(posedge clk) begin");
  vlg_wrapper.add_stmt("if (rst) __STARTED__ <= 0;");
  vlg_wrapper.add_stmt(
      "else if (__START__) __STARTED__ <= 1;"); // will never return to zero
  vlg_wrapper.add_stmt("end");

  vlg_wrapper.add_reg("__ENDED__", 1);
  vlg_wrapper.add_stmt("always @(posedge clk) begin");
  vlg_wrapper.add_stmt("if (rst) __ENDED__ <= 0;");
  vlg_wrapper.add_stmt(
      "else if (__IEND__) __ENDED__ <= 1;"); // will never return to zero
  vlg_wrapper.add_stmt("end");

  vlg_wrapper.add_reg("__RESETED__", 1);
  vlg_wrapper.add_stmt("always @(posedge clk) begin");
  vlg_wrapper.add_stmt("if (rst) __RESETED__ <= 1;");
  vlg_wrapper.add_stmt("end");

  // remember to generate
  // __RESETED__
  // __ISSUE__ == start condition (if no flush, issue == true?)
  // __IEND__ == ( end condition ) &&  STARTED
  // __ENDFLUSH__ == (end flush condition ) && ENDED
  // flush : !( __ISSUE__ ? || __START__ || __STARTED__ ) |-> flush
} // ConstructWrapper_add_cycle_count_moniter

void VlgSglTgtGen::ConstructWrapper_generate_header() {
  vlg_wrapper.add_preheader("\n`define true  1\n");
  vlg_wrapper.add_preheader("\n`define false 0\n");
} // ConstructWrapper_generate_header

// for special memory, we don't need to do anything?
void VlgSglTgtGen::ConstructWrapper_add_varmap_assumptions() {
  ILA_ASSERT(target_type == target_type_t::INSTRUCTIONS)
      << "Implementation bug: vmap assumpt should only be used when verifying "
         "instructions.";
  std::set<std::string> ila_state_names;

  for (size_t state_idx = 0; state_idx < _host->state_num(); ++state_idx)
    ila_state_names.insert(_host->state(state_idx)->name().str());

  for (auto& i : (rf_vmap["state mapping"]).items()) {
    auto sname = i.key();
    if (not IN(sname, ila_state_names)) {
      ILA_ERROR << sname
                << " is not a state of the ILA:" << _host->name().str();
      continue;
    }
    if (_vtg_config.OnlyAssumeUpdatedVarsEq and _instr_ptr->update(sname) == nullptr) {
      ILA_INFO << "Skip assume EQ on variable:"<<sname
               << " for instruction:"<<_instr_ptr->name().str();
      continue;
    }

    ila_state_names.erase(sname);
    // __START__ ==> vmap
    ILA_INFO << sname;

    std::string problem_name = "variable_map_assume_";
    if( _vtg_config. PerVariableProblemCosa )
      problem_name += sname;

    add_an_assumption("(~ __START__ )|| (" +
                          GetStateVarMapExpr(sname, i.value()) + ")",
                      problem_name);
  }
  ILA_INFO << "5.2.2";
  // check for unmapped states
  if (not ila_state_names.empty()) {
    ILA_ERROR << "Refinement relation: missing state mapping for the following "
                 "states:";
    for (auto&& sn : ila_state_names)
      ILA_ERROR << "  " << sn;
  }
} // ConstructWrapper_add_varmap_assumptions

// for memory, we need to assert new data match and ?
//
void VlgSglTgtGen::ConstructWrapper_add_varmap_assertions() {
  ILA_ASSERT(target_type == target_type_t::INSTRUCTIONS)
      << "Implementation bug: vmap assts should only be used when verifying "
         "instructions.";
  std::set<std::string> ila_state_names;

  // put the ila_states to the set, so we can know if state mapping
  // refers to some wrong state names
  for (size_t state_idx = 0; state_idx < _host->state_num(); ++state_idx)
    ila_state_names.insert(_host->state(state_idx)->name().str());

  for (auto& i : (rf_vmap["state mapping"]).items()) {
    auto sname = i.key();
    if (not IN(sname, ila_state_names)) {
      ILA_ERROR << sname
                << " is not a state of the ILA:" << _host->name().str();
      continue;
    }
    if (_vtg_config.OnlyCheckInstUpdatedVars and _instr_ptr->update(sname) == nullptr) {
      ILA_INFO << "Skip checking variable:"<<sname<<" for instruction:"<<_instr_ptr->name().str();
      continue;
    }

    ila_state_names.erase(sname);
    // ISSUE ==> vmap
    std::string precondition =
        has_flush ? "(~ __ENDFLUSH__) || " : "(~ __IEND__) || ";

    
    std::string problem_name = "variable_map_assert_";
    if( _vtg_config. PerVariableProblemCosa )
      problem_name += sname;

    add_an_assertion(precondition + "(" + GetStateVarMapExpr(sname, i.value()) +
                         ")",
                     problem_name);
  }
} // ConstructWrapper_add_varmap_assertions

void VlgSglTgtGen::ConstructWrapper_add_inv_assumptions() {
  ILA_ASSERT(target_type == target_type_t::INSTRUCTIONS)
      << "Implementation bug: inv assumpt should only be used when verifying "
         "instructions.";
  if (rf_cond["global invariants"].size() == 0)
    return; // no invariants to add
  if (not rf_cond["global invariants"].is_array()) {
    ILA_ERROR << "'global invariants' field in refinement relation has to be a "
                 "JSON array.";
    return;
  }
  for (auto& cond : rf_cond["global invariants"]) {
    auto new_cond = ReplExpr(cond.get<std::string>(), true);
    std::string precondition;
    if (ONLY_INITIAL_INV)
      precondition = has_flush ? "(~ __RESETED__) || " : "(~ __START__) || ";
    else
      precondition = ""; // always assme no matter what

    add_an_assumption(precondition + "(" + new_cond + ")", "invariant_assume");
  }
} // ConstructWrapper_add_inv_assumptions

//
// should not have the flush condition set -- > because this should only be
// called when target is invariants

void VlgSglTgtGen::ConstructWrapper_add_inv_assertions() {
  ILA_ASSERT(target_type == target_type_t::INVARIANTS)
      << "Implementation bug: should only be used when verifying invariants";
  if (rf_cond["global invariants"].size() == 0)
    return; // no invariants to add
  if (not rf_cond["global invariants"].is_array()) {
    ILA_ERROR << "'global invariants' field in refinement relation has to be a "
                 "JSON array.";
    return;
  }
  for (auto& cond : rf_cond["global invariants"]) {
    auto new_cond = ReplExpr(cond.get<std::string>(), true); // force vlg state
    add_an_assertion("(" + new_cond + ")", "invariant_assert");
  }
}

void VlgSglTgtGen::ConstructWrapper_add_additional_mapping_control() {
  if (IN("mapping control", rf_vmap)) {
    if (not rf_vmap["mapping control"].is_array())
      ILA_ERROR << "mapping control field must be an array of string";
    for (auto&& c : rf_vmap["mapping control"]) {
      if (not c.is_string()) {
        ILA_ERROR << "mapping control field must be an array of string";
        continue;
      }
      add_an_assumption(ReplExpr(c.get<std::string>()),
                        "additional_mapping_control_assume");
    }
  }
} // ConstructWrapper_add_additional_mapping_control

void VlgSglTgtGen::ConstructWrapper_add_condition_signals() {
  // TODO
  // remember to generate
  // __ISSUE__ == start condition (if no flush, issue == true?)
  // __IEND__ == ( end condition ) &&  STARTED
  // __ENDFLUSH__ == (end flush condition ) && ENDED
  // flush : !( __ISSUE__ ? || __START__ || __STARTED__ ) |-> flush

  if (target_type == target_type_t::INVARIANTS)
    return;
  // we don't need additional signals, just make reset drives the design

  // find the instruction
  auto& instr = get_current_instruction_rf();
  ILA_ASSERT(!instr.is_null());

  // __IEND__
  std::string iend_cond = VLG_FALSE;
  if (ready_type & ready_type_t::READY_SIGNAL) {
    if (instr["ready signal"].is_string()) {
      iend_cond += "|| (" +
                   ReplExpr(instr["ready signal"].get<std::string>(), true) +
                   ")"; // force vlg
    } else if (instr["ready signal"].is_array()) {
      for (auto&& cond : instr["ready signal"])
        if (cond.is_string())
          iend_cond += " || (" + ReplExpr(cond.get<std::string>()) + ")";
        else
          ILA_ERROR << "ready signal field of instruction: "
                    << _instr_ptr->name().str()
                    << " has to be string or array or string";
    } else
      ILA_ERROR << "ready signal field of instruction: "
                << _instr_ptr->name().str()
                << " has to be string or array or string";
  }
  if (ready_type & ready_type_t::READY_BOUND) { // can be both applied
    if (instr["ready bound"].is_number_integer()) {
      int bound = instr["ready bound"].get<int>();
      if (bound > 0) {
        // okay now we enforce the bound
        iend_cond += "|| ( __CYCLE_CNT__ == " +
                     ReplExpr(IntToStr(cnt_width) + "'d" + IntToStr(bound)) +
                     ")";
      } else
        ILA_ERROR << "ready bound field of instruction: "
                  << _instr_ptr->name().str() << " has to a positive integer";
    } else
      ILA_ERROR << "ready bound field of instruction: "
                << _instr_ptr->name().str() << " has to a positive integer";
  } // end of ready bound/condition
  vlg_wrapper.add_wire("__IEND__", 1, true);
  add_wire_assign_assumption("__IEND__", "(" + iend_cond + ") && __STARTED__",
                             "IEND");
  // handle start decode
  ILA_ERROR_IF ( IN("start decode", instr ) ) << "'start decode' is replaced by start condition!";
  if( IN("start condition", instr) ) {
    handle_start_condition(instr["start condition"]);
  } else {
    add_an_assumption("(~ __START__) || (" + vlg_ila.decodeNames[0] + ")",
                      "issue_decode"); // __ISSUE__ |=> decode
    add_an_assumption("(~ __START__) || (" + vlg_ila.validName + ")",
                      "issue_valid"); // __ISSUE__ |=> decode
  }

  if (has_flush) {
    ILA_ASSERT(IN("pre-flush end", instr) and
               IN("post-flush end", instr)); // there has to be something

    std::string issue_cond;
    if (instr["pre-flush end"].is_string())
      issue_cond = "(" + ReplExpr(instr["pre-flush end"].get<std::string>()) +
                   ") && __RESETED__";
    else {
      issue_cond = "1";
      ILA_ERROR << "pre-flush end field should be a string!";
    }
    vlg_wrapper.add_wire("__ISSUE__", 1, true);
    add_wire_assign_assumption("__ISSUE__", issue_cond, "ISSUE");

    std::string finish_cond;
    if (instr["post-flush end"].is_string())
      finish_cond = "(" + ReplExpr(instr["post-flush end"].get<std::string>()) +
                    ") && __ENDED__";
    else {
      finish_cond = "1";
      ILA_ERROR << "post-flush end field should be a string!";
    }
    vlg_wrapper.add_wire("__ENDFLUSH__", 1, true);
    add_wire_assign_assumption("__ENDFLUSH__", finish_cond, "ENDFLUSH");

    // enforcing flush constraints
    std::string flush_enforcement = VLG_TRUE " == 1";
    if (instr["flush constraints"].is_string()) {
      flush_enforcement +=
          "&& (" + ReplExpr(instr["flush constraints"].get<std::string>()) +
          ")";
    } else if (instr["flush constraints"].is_array()) {
      for (auto&& c : instr["flush constraints"])
        if (c.is_string())
          flush_enforcement += "&& (" + ReplExpr(c.get<std::string>()) + ")";
        else
          ILA_ERROR << "flush constraint field of instruction:"
                    << _instr_ptr->name().str()
                    << " must be a string or an array of string.";
    } else
      ILA_ERROR << "flush constraint field of instruction:"
                << _instr_ptr->name().str()
                << " must be string or array of string.";

    add_an_assumption(
        "(~ ( __RESETED__ && ~ ( __START__  || __STARTED__ ) ) ) || (" +
            flush_enforcement + ")",
        "flush_enforce_pre");
    add_an_assumption("(~ ( __ENDED__ )) || (" + flush_enforcement + ")",
                      "flush_enforce_post");

  } else {
    vlg_wrapper.add_wire("__ISSUE__", 1, true);
    add_wire_assign_assumption("__ISSUE__", "1", "ISSUE"); // issue ASAP
    // start decode -- issue enforce (e.g. valid, input)
  } // end of no flush
}

void VlgSglTgtGen::ConstructWrapper_register_extra_io_wire() {
  for(auto && refered_vlg_item : _all_referred_vlg_names) {

    auto idx = refered_vlg_item.first.find("[");
    auto removed_range_name = refered_vlg_item.first.substr(0,idx);
    auto vlg_sig_info = vlg_info_ptr->get_signal(removed_range_name);

    auto vname = ReplaceAll(ReplaceAll(ReplaceAll(refered_vlg_item.first, "." , "__DOT__"), "[","_"),"]","_");
    // + ReplaceAll(ReplaceAll(refered_vlg_item.second.range, "[","_"),"]","_"); // name for verilog
    auto width = vlg_sig_info.get_width();

    vlg_wrapper.add_wire( vname , width, 1 ); // keep
    _idr.RegisterExtraWire(vname, vname);
  }
}

void VlgSglTgtGen::ConstructWrapper_add_module_instantiation() {
  // instantiate ila module
  if (target_type == target_type_t::INSTRUCTIONS) {
    auto ila_mod_inst = ConstructWrapper_get_ila_module_inst();
    vlg_wrapper.add_stmt(ila_mod_inst);
  }

  // instantiate verilog module
  std::string verilog_inst_str =
      vlg_info_ptr->get_top_module_name() + " " + _vlg_mod_inst_name + "(\n";

  _idr.VlgAddTopInteface(vlg_wrapper ); // put the extra wire there, and it should add wire also 
  verilog_inst_str += _idr.GetVlgModInstString(vlg_wrapper);
  verilog_inst_str += ");";

  vlg_wrapper.add_stmt(verilog_inst_str);
}

void VlgSglTgtGen::ConstructWrapper_add_helper_memory() {
  // TODO ..
}

void VlgSglTgtGen::ConstructWrapper_add_uf_constraints() {}

// for invariants or for instruction
void VlgSglTgtGen::ConstructWrapper() {
  ILA_ASSERT(target_type == target_type_t::INVARIANTS ||
             target_type == target_type_t::INSTRUCTIONS);

  if (bad_state_return())
    return;
  ILA_INFO << 1;
  // 0. The headers you may need to have
  ConstructWrapper_generate_header();
  ILA_INFO << 2;

  // 1. add input
  if (target_type == target_type_t::INSTRUCTIONS) {
    vlg_wrapper.add_input("dummy_reset", 1);
    vlg_wrapper.add_wire("dummy_reset", 1, true);
    if(_vtg_config.InstructionNoReset)
      add_an_assumption(" (~__RESETED__) || (dummy_reset == 0) ", "noreset");
  }

  ILA_INFO << 3;
  // -- find out the inputs
  ConstructWrapper_add_vlg_input_output();
  ILA_INFO << 4;
  ConstructWrapper_add_ila_input();
  ILA_INFO << 5;

  // 2. add some monitors (bound cnt)
  // 3. add assumptions & assertions
  if (target_type == target_type_t::INSTRUCTIONS) {

    ILA_INFO << 5.1;
    ConstructWrapper_add_cycle_count_moniter();
    ILA_INFO << 5.2;
    ConstructWrapper_add_varmap_assumptions();
    ILA_INFO << 5.3;
    ConstructWrapper_add_varmap_assertions();
    ILA_INFO << 5.4;
    ConstructWrapper_add_inv_assumptions();
  } else if (target_type == target_type_t::INVARIANTS) {
    ConstructWrapper_add_inv_assertions();
    max_bound = MAX_CYCLE_CTR;
  }
  ILA_INFO << 6;
  // 4. additional mapping if any
  ConstructWrapper_add_additional_mapping_control();

  ILA_INFO << 7;
  // if invariants, will do nothing
  ConstructWrapper_add_condition_signals();

  ILA_INFO << 8;

  // 5.0 add the extra wires to the top module wrapper
  if(_backend == backend_selector::COSA)
    ConstructWrapper_register_extra_io_wire();

  // 5. module instantiation
  ConstructWrapper_add_module_instantiation();

  ILA_INFO << 9;
  // 6. helper memory
  ConstructWrapper_add_helper_memory(); // need to decide what is the target
                                        // type

  // 7. uni-functions

  ILA_INFO << 10;
  if (target_type == target_type_t::INSTRUCTIONS) {
    ConstructWrapper_add_uf_constraints();
  }
}

bool VlgSglTgtGen::bad_state_return(void) {
  ILA_ERROR_IF(_bad_state) << "VlgSglTgtGen is in a bad state, cannot proceed.";
  return _bad_state;
} // bad_state_return

/// create the wrapper file
void VlgSglTgtGen::Export_wrapper(const std::string& wrapper_name) {
  top_file_name = wrapper_name;
  std::ofstream fout(os_portable_append_dir(_output_path, wrapper_name));
  if (!fout.is_open()) {
    ILA_ERROR << "Error writing file: "
              << os_portable_append_dir(_output_path, wrapper_name);
    return;
  }
  vlg_wrapper.DumpToFile(fout);
}
/// export the ila verilog
void VlgSglTgtGen::Export_ila_vlg(const std::string& ila_vlg_name) {

  if (target_type == target_type_t::INVARIANTS) {
    ila_file_name = "";
    ILA_WARN << "Should not export ila when verifying invariants.";
    return;
  }

  ila_file_name = ila_vlg_name;
  std::ofstream fout;
  std::string fn;
  if (_backend == backend_selector::COSA) {
    fn = os_portable_append_dir(_output_path, top_file_name);
    fout.open(fn, std::ios_base::app);
  } else if (_backend == backend_selector::JASPERGOLD) {
    fn = os_portable_append_dir(_output_path, ila_vlg_name);
    fout.open(fn);
  }
  if (!fout.is_open()) {
    ILA_ERROR << "Error writing ila to file: " << fn;
    return;
  }
  vlg_ila.DumpToFile(fout);
}

void VlgSglTgtGen::ExportAll(const std::string& wrapper_name,
                             const std::string& ila_vlg_name,
                             const std::string& script_name,
                             const std::string& extra_name,
                             const std::string& mem_name) {
  if (os_portable_mkdir(_output_path) == false)
    ILA_WARN << "Cannot create output directory:" << _output_path;
  // you don't need to worry about the path and names
  Export_wrapper(wrapper_name);
  if (target_type != target_type_t ::INVARIANTS)
    Export_ila_vlg(ila_vlg_name); // this has to be after Export_wrapper
  Export_problem(extra_name);
  Export_script(script_name);
  Export_modify_verilog(); // this must be after Export_wrapper
  Export_mem(mem_name);
}

} // namespace ilang
