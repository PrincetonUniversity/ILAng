/// \file Source for Verilog Verification Targets Generation (single target)
/// the connection wires / instantiation and etc.
// --- Hongce Zhang

#include <ilang/vtarget-out/vtarget_gen_impl.h>

#include <cmath>
#include <fstream>
#include <iostream>

#include <ilang/ila/ast_hub.h>
#include <ilang/util/container_shortcut.h>
#include <ilang/util/fs.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>

namespace ilang {

// ------------- CONFIGURATIONS -------------------- //

#define VLG_TRUE "`true"
#define VLG_FALSE "`false"

#define IntToStr(x) (std::to_string(x))

// ------------- END of CONFIGURAIONS -------------------- //

// ------------------------ ILA ----------------------------- //
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
  if (target_type == target_type_t::INVARIANTS ||
      target_type == target_type_t::INV_SYN_DESIGN_ONLY)
    return "";

  vlg_wrapper.add_wire(vlg_ila.GetValidSignalName(_instr_ptr), 1, true);
  vlg_wrapper.add_wire(vlg_ila.GetDecodeSignalName(_instr_ptr), 1, true);

  rfmap_add_internal_wire(vlg_ila.GetValidSignalName(_instr_ptr), 1);
  rfmap_add_internal_wire(vlg_ila.GetDecodeSignalName(_instr_ptr), 1);
  rfmap_add_replacement("$decode", vlg_ila.GetDecodeSignalName(_instr_ptr));
  rfmap_add_replacement("$valid", vlg_ila.GetValidSignalName(_instr_ptr));

  // TODO: check whether all ports have been dealt with
  // TODO: check whether there are any extra ports we create
  std::set<std::string> port_connected; // store the name of ila port

  // .. record function

  // this is the string to construct
  auto retStr = vlg_ila.moduleName + " " + _ila_mod_inst_name + " (\n";

  std::set<std::string> func_port_skip_set;

  // ite ( unknown) also use this port
  for (auto&& sname_cond_pair : vlg_ila.state_update_ite_unknown) {
    const auto& port_name = sname_cond_pair.second.condition;
    func_port_skip_set.insert(port_name);
    port_connected.insert(port_name);
    vlg_wrapper.add_wire(port_name, 1, true);
    vlg_wrapper.add_output(port_name, 1);
    rfmap_add_internal_wire(port_name, 1);

    retStr += "   ." + port_name + "(" + port_name + "),\n";
  }

  for (auto&& func_app : vlg_ila.ila_func_app) {
    func_port_skip_set.insert(func_app.result.first);
    port_connected.insert(func_app.result.first);
    /// new reg : put in when __START__
    if (!IN(func_app.func_name, func_cnt))
      func_cnt.insert({func_app.func_name, 0});
    unsigned func_no = func_cnt[func_app.func_name]++;

    std::string func_reg_w =
        func_app.func_name + "_" + IntToStr(func_no) + "_result_wire";

    vlg_wrapper.add_wire(func_reg_w, func_app.result.second, true);
    rfmap_add_internal_wire(func_reg_w, func_app.result.second);
    // add as a module input, also
    vlg_wrapper.add_input(func_reg_w, func_app.result.second);

    retStr += "   ." + func_app.result.first + "(" + func_reg_w + "),\n";

    unsigned argNo = 0;
    for (auto&& arg : func_app.args) {
      func_port_skip_set.insert(arg.first);
      port_connected.insert(arg.first);

      std::string func_arg_w = func_app.func_name + "_" + IntToStr(func_no) +
                               "_arg" + IntToStr(argNo) + "_wire";
      // this should be module output
      vlg_wrapper.add_wire(func_arg_w, arg.second, true);
      rfmap_add_internal_wire(func_arg_w, arg.second);

      // vlg_wrapper.add_always_stmt( "if( __START__ ) " + func_arg + " <= " +
      // func_arg_w + ";" );

      retStr += "   ." + arg.first + "(" + func_arg_w + "),\n";
      argNo++;
    }
  } // end of functions

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
                "),\n";                      // no init anyway!
    else if (w.first == vlg_ila.startName) { // .__START__(__START__)
      retStr += "   ." + vlg_ila.startName + "(" + "__START__" + "),\n";
    } else {
      ILA_ERROR_IF(!IN("__ILA_I_" + w.first, vlg_wrapper.wires))
          << "__ILA_I_" + w.first << " has not been defined yet";
      retStr += "   ." + w.first + "(__ILA_I_" + w.first + "),\n";
    }
  } // end of inputs

  // TODO:: Function here !
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
      // ILA_ERROR_IF( not IN ("__ILA_I_" + w.first , vlg_wrapper.wires) ) <<
      // "__ILA_I_" + w.first << " has not been defined yet";
      ILA_ERROR << "Does not know how to connect:" << w.first << ", ignored.";
      // std::cout<< w.first<<std::endl;
      retStr += "   ." + w.first + "(),\n"; // __ILA_I_" + w.first + "
    }
  }

  // for internal memory connect the probes
  for (auto&& port : vlg_ila.mem_probe_o) {
    std::string wrapper_wire_name = "__ILA_SO_" + port.first;
    vlg_wrapper.add_wire(wrapper_wire_name, port.second, true);
    retStr += "   ." + port.first + "(" + wrapper_wire_name + "),\n";
  }

  // handle memory io - use internal storage for this purpose
  for (auto&& ila_name_rport_pair : vlg_ila.ila_rports) {
    const auto& ila_name = ila_name_rport_pair.first;
    const auto& rports = ila_name_rport_pair.second;
    const auto adw = GetMemInfo(ila_name);
    auto aw = adw.first;
    auto dw = adw.second; // address/data width
    ILA_CHECK(aw > 0 && dw > 0)
        << "Implementation bug: unable to find mem:" << ila_name;

    for (auto&& rport : rports) {
      auto no = rport.first;    // is the num
      auto port = rport.second; // is the port
      auto rdw = "__IMEM_" + ila_name + "_" + IntToStr(no) + "_rdata";
      auto raw = "__IMEM_" + ila_name + "_" + IntToStr(no) + "_raddr";
      // auto rew = "__IMEM_" + ila_name + "_" + IntToStr(no) + "_ren"; no need,
      // r_en is the start signal

      rfmap_add_internal_wire(rdw, dw);
      rfmap_add_internal_wire(raw, aw);

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
    ILA_CHECK(aw > 0 && dw > 0)
        << "Implementation bug: unable to find mem:" << ila_name;

    for (auto&& wport : wports) {
      auto no = wport.first;    // is the num
      auto port = wport.second; // is the port
      auto wdw = "__IMEM_" + ila_name + "_" + IntToStr(no) + "_wdata";
      auto waw = "__IMEM_" + ila_name + "_" + IntToStr(no) + "_waddr";
      auto wew = "__IMEM_" + ila_name + "_" + IntToStr(no) + "_wen";
      auto wdw_delay = wdw + "_d1";
      auto waw_delay = waw + "_d1";
      auto wew_delay = wew + "_d1";

      vlg_wrapper.add_wire(wdw, dw, true);
      vlg_wrapper.add_wire(waw, aw, true);
      vlg_wrapper.add_wire(wew, 1, true);
      rfmap_add_internal_wire(wdw, dw);
      rfmap_add_internal_wire(waw, aw);
      rfmap_add_internal_wire(wew, 1);

      // latch the write signal
      vlg_wrapper.add_reg(wdw_delay, dw);
      vlg_wrapper.add_reg(waw_delay, aw);
      vlg_wrapper.add_reg(wew_delay, 1);
      rfmap_add_internal_reg(wdw_delay, dw);
      rfmap_add_internal_reg(waw_delay, aw);
      rfmap_add_internal_reg(wew_delay, 1);
      vlg_wrapper.add_always_stmt("if (__START__) " + wdw_delay + " <= " + wdw +
                                  ";");
      vlg_wrapper.add_always_stmt("if (__START__) " + waw_delay + " <= " + waw +
                                  ";");
      vlg_wrapper.add_always_stmt("if (__START__) " + wew_delay + " <= " + wew +
                                  ";");

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
    if (!IN("__ILA_SO_" + r.first, vlg_wrapper.wires)) {
      ILA_WARN_IF(!StrStartsWith(r.first, "__COUNTER_start__n"))
          << "__ILA_SO_" + r.first << " will be ignored";

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

// ------------------------ VERILOG ----------------------------- //

void VlgSglTgtGen::ConstructWrapper_add_vlg_input_output() {

  auto vlg_inputs = vlg_info_ptr->get_top_module_io(refinement_map.width_info);

  ILA_CHECK(
      refinement_map.rtl_interface_connection.clock_domain_defs.size() == 1 &&
      IN("default", refinement_map.rtl_interface_connection.clock_domain_defs))
      << "Not implemented. Cannot handle multi-clock.";

  ILA_CHECK(
      refinement_map.rtl_interface_connection.custom_reset_domain_defs.empty())
      << "Not implemented. Cannot handle customized reset.";

  const auto& clock_pins =
      refinement_map.rtl_interface_connection.clock_domain_defs.at("default");
  const auto& reset_pins = refinement_map.rtl_interface_connection.reset_pins;
  const auto& nreset_pins = refinement_map.rtl_interface_connection.nreset_pins;
  const auto& custom_input = refinement_map.rtl_interface_connection.input_port_connection;
  for (auto&& name_siginfo_pair : vlg_inputs) {
    std::string refstr = "**KEEP**";
    if (IN(name_siginfo_pair.first, clock_pins))
      refstr = "**CLOCK**";
    else if (IN(name_siginfo_pair.first, reset_pins))
      refstr = "**RESET**";
    else if (IN(name_siginfo_pair.first, nreset_pins))
      refstr = "**NRESET**";
    else if (IN(name_siginfo_pair.first, custom_input)) {
      auto short_name = name_siginfo_pair.first;
      auto wname = "__VLG_II_" + short_name;
      add_wire_assign_assumption( wname, custom_input.at(name_siginfo_pair.first),
        "vlg_input_wire");
      rfmap_add_internal_wire(wname,
        name_siginfo_pair.second.get_width() );
      refstr = "**CUSTOM_INPUT**";
    }

    _idr.RegisterInterface(name_siginfo_pair.second, refstr);
  }
} // ConstructWrapper_add_vlg_input_output

// ------------------------ ALL instantiation ----------------------------- //
void VlgSglTgtGen::ConstructWrapper_add_module_instantiation() {
  // instantiate verilog module
  std::string verilog_inst_str =
      vlg_info_ptr->get_top_module_name() + " " + _vlg_mod_inst_name + "(\n";

  _idr.VlgAddTopInteface(
      vlg_wrapper); // put the extra wire there, and it should add wire also
  verilog_inst_str += _idr.GetVlgModInstString(vlg_wrapper);
  verilog_inst_str += ");";

  vlg_wrapper.add_stmt(verilog_inst_str);
} // ConstructWrapper_add_module_instantiation

// ------------------------ OTERHS (refs) ----------------------------- //
void VlgSglTgtGen::ConstructWrapper_register_extra_io_wire() {
  for (auto&& extra_wire : rtl_extra_wire) {
    const auto& wire_name = extra_wire.first;
    unsigned width = extra_wire.second.width;

    vlg_wrapper.add_wire(wire_name, width, 1); // keep
    vlg_wrapper.add_output(wire_name, width);  // add as output of the wrapper
    _idr.RegisterExtraWire(wire_name, wire_name);
  }
} // ConstructWrapper_register_extra_io_wire

} // namespace ilang
