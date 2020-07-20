/// \file Source for Verilog Verification Targets Generation (single target)
/// assumption and assertion handling generic case -- JasperGold has its
/// override
// --- Hongce Zhang

#include <ilang/vtarget-out/vtarget_gen_impl.h>

#include <cmath>
#include <fstream>
#include <iostream>

#include <ilang/ila/ast_hub.h>
#include <ilang/mcm/ast_helper.h>
#include <ilang/util/container_shortcut.h>
#include <ilang/util/fs.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>

namespace ilang {

void VlgSglTgtGen::add_wire_assign_assumption(const std::string& varname,
                                              const std::string& expression,
                                              const std::string& dspt) {
  //_problems.assumptions.push_back(varname + " = " +
  //                                convert_expr_to_cosa(expression));
  vlg_wrapper.add_assign_stmt(varname, expression);
  ILA_CHECK(_vtg_config.CosaDotReferenceNotify !=
                vtg_config_t::CosaDotReferenceNotify_t::NOTIFY_PANIC ||
            expression.find(".") == std::string::npos)
      << "expression:" << expression << " contains unfriendly dot.";
  ILA_WARN_IF(_vtg_config.CosaDotReferenceNotify ==
                  vtg_config_t::CosaDotReferenceNotify_t::NOTIFY_WARNING &&
              expression.find(".") != std::string::npos)
      << "expression:" << expression << " contains unfriendly dot.";
}

void VlgSglTgtGen::add_reg_cassign_assumption(const std::string& varname,
                                              const std::string& expression,
                                              int width,
                                              const std::string& cond,
                                              const std::string& dspt) {
  // vlg_wrapper.add_always_stmt(varname + " <= " + varname + ";");
  // _problems.assumptions.push_back("(!( " + convert_expr_to_cosa(cond) +
  //                                 " ) | (" + varname + " = " +
  //                                convert_expr_to_cosa(expression) + "))");

  ILA_CHECK(_vtg_config.CosaDotReferenceNotify !=
                vtg_config_t::CosaDotReferenceNotify_t::NOTIFY_PANIC ||
            expression.find(".") == std::string::npos)
      << "expression:" << expression << " contains unfriendly dot.";

  ILA_WARN_IF(_vtg_config.CosaDotReferenceNotify ==
                  vtg_config_t::CosaDotReferenceNotify_t::NOTIFY_WARNING &&
              expression.find(".") != std::string::npos)
      << "expression:" << expression << " contains unfriendly dot.";

  // vlg_wrapper.add_always_stmt("if (" + cond + ") " + varname +
  //                            " <= " + expression + "; //" + dspt);
  // we prefer the following way, as we get the value instantaneously
  std::string rand_in_name = "__" + varname + "_init__";
  vlg_wrapper.add_input(rand_in_name, width);
  vlg_wrapper.add_wire(rand_in_name, width);

  vlg_wrapper.add_init_stmt(varname + " <= " + rand_in_name + ";");
  vlg_wrapper.add_always_stmt(varname + " <= " + varname + ";");
  add_an_assumption(
      "(~(" + cond + ") || ((" + varname + ") == (" + expression + ")))", dspt);
}

/// Add an assumption
void VlgSglTgtGen::add_an_assumption(const std::string& aspt,
                                     const std::string& dspt) {
  auto assumption_wire_name = vlg_wrapper.sanitizeName(dspt) + new_mapping_id();
  vlg_wrapper.add_wire(assumption_wire_name, 1, true);
  vlg_wrapper.add_output(assumption_wire_name,
                         1); // I find it is necessary to connect to the output

  ILA_CHECK(_vtg_config.CosaDotReferenceNotify !=
                vtg_config_t::CosaDotReferenceNotify_t::NOTIFY_PANIC ||
            aspt.find(".") == std::string::npos)
      << "aspt:" << aspt << " contains unfriendly dot.";

  ILA_WARN_IF(_vtg_config.CosaDotReferenceNotify ==
                  vtg_config_t::CosaDotReferenceNotify_t::NOTIFY_WARNING &&
              aspt.find(".") != std::string::npos)
      << "aspt:" << aspt << " contains unfriendly dot.";

  vlg_wrapper.add_assign_stmt(assumption_wire_name, aspt);
  add_a_direct_assumption(
      assumption_wire_name +
          (_backend == backend_selector::COSA ? " = 1_1" : ""),
      dspt);
} // add_an_assumption

/// Add an assertion
void VlgSglTgtGen::add_an_assertion(const std::string& asst,
                                    const std::string& dspt) {
  auto assrt_wire_name = vlg_wrapper.sanitizeName(dspt) + new_property_id();
  vlg_wrapper.add_wire(assrt_wire_name, 1, true);
  vlg_wrapper.add_output(assrt_wire_name,
                         1); // I find it is necessary to connect to the output
  vlg_wrapper.add_assign_stmt(assrt_wire_name, asst);
  add_a_direct_assertion(
      assrt_wire_name + (_backend == backend_selector::COSA ? " = 1_1" : ""),
      dspt);
  ILA_CHECK(_vtg_config.CosaDotReferenceNotify !=
                vtg_config_t::CosaDotReferenceNotify_t::NOTIFY_PANIC ||
            asst.find(".") == std::string::npos)
      << "asst:" << asst << " contains unfriendly dot.";
  ILA_WARN_IF(_vtg_config.CosaDotReferenceNotify ==
                  vtg_config_t::CosaDotReferenceNotify_t::NOTIFY_WARNING &&
              asst.find(".") != std::string::npos)
      << "asst:" << asst << " contains unfriendly dot.";

  //_problems.probitem[dspt].assertions.push_back(convert_expr_to_cosa(asst));
}

}; // namespace ilang
