/// \file Source for Verilog Verification Targets Generation (single target)
/// the conditions
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

#include <ilang/rfmap-in/rfexpr_shortcut.h>

namespace ilang {

// ------------- CONFIGURATIONS -------------------- //

#define VLG_TRUE "`true"
#define VLG_FALSE "`false"

#define IntToStr(x) (std::to_string(x))

// ------------- END of CONFIGURAIONS -------------------- //

//  NON-FLUSH case
//  1 RESET
//  2 ISSUE = true      RESETED (forever)
//  3           START                     ---> assume varmap  ---> assume inv
//  4                   STARTED
//  5                   STARTED
//  ...                   ...
//  6           IEND                      ---> check varmap
//  7                     ENDED

/// setup reset, add assumptions if necessary
void VlgSglTgtGen::ConstructWrapper_reset_setup() {
  if (target_type == target_type_t::INSTRUCTIONS) {
    vlg_wrapper.add_input("dummy_reset", 1);
    vlg_wrapper.add_wire("dummy_reset", 1, true);
    rfmap_add_internal_wire("dummy_reset", 1);
    if (_vtg_config.InstructionNoReset) {
      add_an_assumption(rfmap_imply(rfmap_var("__RESETED__"),
                                    rfmap_not(rfmap_var("dummy_reset"))),
                        "noreset");
    }
  } else if (target_type == target_type_t::INVARIANTS ||
             target_type == target_type_t::INV_SYN_DESIGN_ONLY) {
    if (_vtg_config.InvariantCheckNoReset) {
      if (_backend == ModelCheckerSelection::JASPERGOLD) {
        // no need to any thing
      } else if (VlgVerifTgtGenBase::backend_needs_yosys(_backend)) {
        add_a_direct_assumption("rst == 0", "noreset");
      }
    }
    // JasperGold will not mess with it
    // yosys : abc needs assumptions but not all of them
  }
} // ConstructWrapper_reset_setup

void VlgSglTgtGen::ConstructWrapper_add_cycle_count_moniter() {
  // find in rf_cond, how many cycles will be needed
  max_bound = 0;

  const auto& instr = get_current_instruction_rf();

  if (instr.is_readybound())
    max_bound = instr.ready_bound;
  else
    max_bound = _vtg_config.MaxBound;
  if (instr.max_bound > max_bound)
    max_bound = instr.max_bound;

  cnt_width = (int)std::ceil(std::log2(max_bound + 20));
  vlg_wrapper.add_reg("__CYCLE_CNT__",
                      cnt_width); // by default it will be an output reg
  rfmap_add_internal_reg("__CYCLE_CNT__", cnt_width);

  vlg_wrapper.add_stmt("always @(posedge clk) begin");
  vlg_wrapper.add_stmt("if (rst) __CYCLE_CNT__ <= 0;");
  vlg_wrapper.add_stmt(
      "else if ( ( __START__ || __STARTED__ ) &&  __CYCLE_CNT__ < " +
      IntToStr(max_bound + 10) + ") __CYCLE_CNT__ <= __CYCLE_CNT__ + 1;");
  vlg_wrapper.add_stmt("end");

  vlg_wrapper.add_reg("__START__", 1);
  rfmap_add_internal_reg("__START__", 1);
  rfmap_add_replacement("decode", "__START__");
  vlg_wrapper.add_stmt("always @(posedge clk) begin");
  // how start is triggered
  if(_vtg_config.ForceInstCheckReset) {
    vlg_wrapper.add_stmt("if (__ISSUE__ && !__START__ && !__STARTED__) __START__ <= 1;");
  } else {
    vlg_wrapper.add_stmt("if (rst) __START__ <= 1;");
  }
  vlg_wrapper.add_stmt("else if (__START__ || __STARTED__) __START__ <= 0;");

  vlg_wrapper.add_stmt("end");

  vlg_wrapper.add_reg("__STARTED__", 1);
  rfmap_add_internal_reg("__STARTED__", 1);
  rfmap_add_replacement("afterdecode", "__STARTED__");
  vlg_wrapper.add_stmt("always @(posedge clk) begin");
  vlg_wrapper.add_stmt("if (rst) __STARTED__ <= 0;");
  vlg_wrapper.add_stmt(
      "else if (__START__) __STARTED__ <= 1;"); // will never return to zero
  vlg_wrapper.add_stmt("end");

  vlg_wrapper.add_reg("__ENDED__", 1);
  rfmap_add_internal_reg("__ENDED__", 1);
  vlg_wrapper.add_stmt("always @(posedge clk) begin");
  vlg_wrapper.add_stmt("if (rst) __ENDED__ <= 0;");
  vlg_wrapper.add_stmt(
      "else if (__IEND__) __ENDED__ <= 1;"); // will never return to zero
  vlg_wrapper.add_stmt("end");

  vlg_wrapper.add_reg("__2ndENDED__", 1);
  rfmap_add_internal_reg("__2ndENDED__", 1);
  vlg_wrapper.add_stmt("always @(posedge clk) begin");
  vlg_wrapper.add_stmt("if (rst) __2ndENDED__ <= 1'b0;");
  vlg_wrapper.add_stmt("else if (__ENDED__ && __EDCOND__ && ~__2ndENDED__)  "
                       "__2ndENDED__ <= 1'b1; end");

  vlg_wrapper.add_wire("__2ndIEND__", 1);
  vlg_wrapper.add_assign_stmt("__2ndIEND__",
                              "__ENDED__ && __EDCOND__ && ~__2ndENDED__");

  vlg_wrapper.add_reg("__RESETED__", 1);
  rfmap_add_internal_reg("__RESETED__", 1);
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

void VlgSglTgtGen::ConstructWrapper_add_condition_signals() {
  // TODO
  // remember to generate
  // __ISSUE__ == start condition (if no flush, issue == true?)
  // __IEND__ == ( end condition ) &&  STARTED
  // __ENDFLUSH__ == (end flush condition ) && ENDED
  // flush : !( __ISSUE__ ? || __START__ || __STARTED__ ) |-> flush

  ILA_CHECK(target_type == target_type_t::INSTRUCTIONS);
  // we don't need additional signals, just make reset drives the design

  // find the instruction
  const auto& instr = get_current_instruction_rf();

  // __IEND__
  rfmap::RfExpr iend_cond;
  // bool no_started_signal = false;
  if (instr.is_readysignal()) {
    iend_cond = instr.ready_signal;
  } else {
    ILA_ASSERT(instr.is_readybound());
    unsigned bound = instr.ready_bound;
    ILA_ERROR_IF(bound == 0)
        << "Does not support bound : 0, please use a buffer to hold "
           "the signal.";
    iend_cond =
        rfmap_eq(rfmap_var("__CYCLE_CNT__"), rfmap_const(10, cnt_width, bound));
    //  "( __CYCLE_CNT__ == " + IntToStr(cnt_width) + "'d"
    //              + IntToStr(bound) + ")";
  }

  // max bound for max checking range
  rfmap::RfExpr max_bound_constr = rfmap_true();
  if (instr.max_bound != 0) {
    max_bound_constr = rfmap_le(rfmap_var("__CYCLE_CNT__"),
                                rfmap_const(10, cnt_width, instr.max_bound));
    // "&& ( __CYCLE_CNT__ <= " + IntToStr(instr.max_bound) + ")";
  }

  vlg_wrapper.add_wire("__IEND__", 1, true);
  vlg_wrapper.add_wire("__EDCOND__", 1, true);
  vlg_wrapper.add_output("__IEND__", 1);
  vlg_wrapper.add_output("__EDCOND__", 1);

  rfmap_add_internal_wire("__IEND__", 1);
  rfmap_add_internal_wire("__EDCOND__", 1);
  rfmap_add_replacement("commit", "__IEND__");

  auto end_no_recur = rfmap_not(rfmap_var("__ENDED__"));

  add_wire_assign_assumption(
      "__EDCOND__", rfmap_and(iend_cond, rfmap_var("__STARTED__")), "EDCOND");

  add_wire_assign_assumption(
      "__IEND__",
      rfmap_and({iend_cond, rfmap_var("__STARTED__"), rfmap_var("__RESETED__"),
                 end_no_recur, max_bound_constr}),
      "IEND");

  if(_vtg_config.CheckInstrCommitSatisfiable) {
    add_a_cover(rfmap_var("commit"), "inst_will_commit");
  }
  
  // handle start decode

  if (!instr.start_condition.empty()) {
    handle_start_condition(instr.start_condition);
  } else {
    add_an_assumption(rfmap_imply(rfmap_var("__START__"), rfmap_var("$decode")),
                      "issue_decode"); // __ISSUE__ |-> decode
    add_an_assumption(rfmap_imply(rfmap_var("__START__"), rfmap_var("$valid")),
                      "issue_valid"); // __ISSUE__ |-> valid
  }

  vlg_wrapper.add_wire("__ISSUE__", 1, true);
  rfmap_add_internal_wire("__ISSUE__", 1);

  if (_vtg_config.ForceInstCheckReset) {
    vlg_wrapper.add_input("__ISSUE__", 1);
  } else
    vlg_wrapper.add_assign_stmt("__ISSUE__", "1");
  // start decode -- issue enforce (e.g. valid, input)

} // ConstructWrapper_add_condition_signals

} // namespace ilang
