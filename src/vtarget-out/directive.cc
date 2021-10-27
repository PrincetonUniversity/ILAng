/// \file Source for Interace Directive in Refinement relations in Verilog
/// Verification Target Generation
// --- Hongce Zhang

#include <ilang/vtarget-out/directive.h>

#include <ilang/util/container_shortcut.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>

namespace ilang {

#define VLG_TRUE "`true"

// ---------------------- class IntefaceDirectiveRecorder
// -------------------------------

void IntefaceDirectiveRecorder::ConnectModuleInputAddWire(
    const std::string& short_name, unsigned width) {
  if (IN(short_name, mod_inst_rec)) {
    ILA_ERROR << short_name << "is already connected. Ignored.";
    return;
  }
  input_wires.push_back({short_name, width});
  mod_inst_rec.insert(
      {short_name, inf_connector_t({inf_dir_t::INPUT, short_name})});
}

void IntefaceDirectiveRecorder::ConnectModuleOutputAddWire(
    const std::string& short_name, unsigned width) {
  if (IN(short_name, mod_inst_rec)) {
    ILA_ERROR << short_name << "is already connected. Ignored.";
    return;
  }
  output_wires.push_back({short_name, width});
  mod_inst_rec.insert(
      {short_name, inf_connector_t({inf_dir_t::SO, short_name})});
}

/// Return a string used for instantiating
std::string IntefaceDirectiveRecorder::GetVlgModInstString(
    VerilogGeneratorBase& gen) const {
  ModuleInstSanityCheck(gen); // make sure we didn't miss any wire
  std::string retStr;
  std::string sep;
  for (auto&& signal_conn_pair : mod_inst_rec) {
    const auto& signal_name = signal_conn_pair.first;
    // const auto& conn_tp = signal_conn_pair.second.first;
    const auto& the_wire_connected_to_the_port = signal_conn_pair.second.second;

    retStr += sep + "    ." + signal_name + "(" +
              the_wire_connected_to_the_port + ")";
    sep = ",\n";
  }
  retStr += "\n";
  return retStr;
} // you can append after it

/// Add signals to the wrapper_generator
void IntefaceDirectiveRecorder::VlgAddTopInteface(
    VerilogGeneratorBase& gen) const {
  for (auto&& w : output_wires) {
    gen.add_output(w.first, w.second);
    gen.add_wire(w.first, w.second, true);
  }
  for (auto&& w : input_wires) {
    gen.add_input(w.first, w.second);
    gen.add_wire(w.first, w.second, true);
  }
  for (auto&& w : internal_wires) {
    gen.add_wire(w.first, w.second, true);
    gen.add_output(w.first, w.second);
  }
}

void IntefaceDirectiveRecorder::ModuleInstSanityCheck(
    VerilogGeneratorBase& gen) const {
  for (auto&& signal_conn_pair : mod_inst_rec) {
    const auto& conn_tp = signal_conn_pair.second.first;
    const auto& the_wire_connected_to_the_port = signal_conn_pair.second.second;
    if (conn_tp == inf_dir_t::NC)
      continue; // no need to check them, will be declared

    if (conn_tp == inf_dir_t::START)
      continue; // this is connected to __START__ | __STARTED__ // hope it will
                // be fine

    if (IN(the_wire_connected_to_the_port, gen.wires))
      continue; // if found okay

    // handles ~x
    if (the_wire_connected_to_the_port[0] == '~') {
      if (IN(the_wire_connected_to_the_port.substr(1), gen.wires))
        continue;
    }

    ILA_CHECK(false) << "Connecting signal: " << the_wire_connected_to_the_port
                     << " tp: " << conn_tp
                     << " is not declared. Implementation bug!";
  }
}
// register extra state out name
void IntefaceDirectiveRecorder::RegisterExtraWire(
    const std::string& io_name, const std::string& outside_name) {
  if (!IN(io_name, mod_inst_rec))
    mod_inst_rec.insert(
        {{io_name, inf_connector_t({inf_dir_t::SO, outside_name})}});
  else {
    ILA_ERROR << io_name << " has been connected already.";
  }
}

/// Used to tell this module about the refinement relations ,  , ila interface
/// checker?
// TODO: connect all signals as KEEP, except for clock/rst
void IntefaceDirectiveRecorder::RegisterInterface(const SignalInfoBase& vlg_sig,
                                                  const std::string& refstr) {

  auto short_name = vlg_sig.get_signal_name();
  bool is_input = vlg_sig.is_input();
  bool is_output = vlg_sig.is_output();
  unsigned width = vlg_sig.get_width();

  // temporary fix if cannot get its width
  if (width == 0) {
    ILA_WARN << "assuming " << short_name << " has width 1";
    width = 1;
  }
  if (!is_input && !is_output)
    ILA_ERROR << "Implementation bug: I/O direction is unknown for "
              << short_name;

  if (is_input && is_output) {
    ILA_WARN << "not handling inout wire: " << short_name
             << ", will not be connected";
    // nc and skip
    mod_inst_rec.insert({short_name, inf_connector_t({inf_dir_t::NC, ""})});
    return;
  }

  if (refstr == "**KEEP**") {
    if (is_input) {
      if (IN(short_name, mod_inst_rec)) {
        ILA_ERROR << short_name << " has already been connected";
      } else {
        input_wires.push_back({"__VLG_I_" + short_name, width});
        mod_inst_rec.insert(
            {short_name,
             inf_connector_t({inf_dir_t::INPUT, "__VLG_I_" + short_name})});
      }
    }
    if (is_output) {
      if (IN(short_name, mod_inst_rec))
        ILA_ERROR << short_name << "is already connected. Ignored.";
      else {
        output_wires.push_back({"__VLG_O_" + short_name, width});
        mod_inst_rec.insert(
            {short_name,
             inf_connector_t({inf_dir_t::SO, "__VLG_O_" + short_name})});
      }
    }
  } else if (refstr == "**START**") {
    ILA_ERROR_IF(!is_input || width != 1)
        << "Expecting `" << short_name << "` to be input of width 1";
    mod_inst_rec.insert(
        {short_name,
         inf_connector_t({inf_dir_t::START, "__START__ | __STARTED__"})});
  } else if (refstr == "**RESET**") {
    ILA_ERROR_IF(!is_input || width != 1)
        << "Expecting `" << short_name << "` to be input of width 1";
    if (_reset_vlg)
      mod_inst_rec.insert(
          {short_name, inf_connector_t({inf_dir_t::RESET, "rst"})});
    else
      mod_inst_rec.insert(
          {short_name, inf_connector_t({inf_dir_t::RESET, "dummy_reset"})});
  } else if (refstr == "**NRESET**") {
    ILA_ERROR_IF(!is_input || width != 1)
        << "Expecting `" << short_name << "` to be input of width 1";
    if (_reset_vlg)
      mod_inst_rec.insert(
          {short_name, inf_connector_t({inf_dir_t::RESET, "~rst"})});
    else
      mod_inst_rec.insert(
          {short_name, inf_connector_t({inf_dir_t::RESET, "~dummy_reset"})});
  } else if (refstr == "**CLOCK**") {
    ILA_ERROR_IF(!is_input || width != 1)
        << "Expecting `" << short_name << "` to be input of width 1";
    mod_inst_rec.insert(
        {short_name, inf_connector_t({inf_dir_t::CLOCK, "clk"})});
  } else if (refstr == "**CUSTOM_INPUT**") {
    ILA_CHECK(is_input) << "Cannot assign to output port : " << short_name;
    ILA_ERROR_IF(IN(short_name, mod_inst_rec)) << short_name << " has already been connected";
    internal_wires.push_back({"__VLG_II_" + short_name, width});
    mod_inst_rec.insert(
        {short_name,
          inf_connector_t({inf_dir_t::INPUT, "__VLG_II_" + short_name})});
  } else {
    ILA_ASSERT(false) << "Implementation error. Should not be reachable.";
  } // decide how to connect and signals to create
  return;
} // IntefaceDirectiveRecorder::RegisterInterface

void IntefaceDirectiveRecorder::Clear(bool reset_vlg) {
  mod_inst_rec.clear();
  input_wires.clear();
  internal_wires.clear();
  output_wires.clear();

  _reset_vlg = reset_vlg;
}

} // namespace ilang
