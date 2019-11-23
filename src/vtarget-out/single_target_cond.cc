/// \file Source for Verilog Verification Targets Generation (single target)
/// the conditions
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

//  FLUSH case
//  1 RESET
//  2             RESETED                   ---> assume flush & preflush cond
//  ...                                     ---> assume flush & preflush cond
//  n ISSUE = pre-flush end                 ---> assume flush & preflush cond
//  n+1           START                     ---> assume varmap  ---> assume inv
//  (maybe globally?) n+2                   STARTED n+3 STARTED
//  ...                   ... (forever)
//  m             IEND
//  m+1                    ENDED            ---> assume flush & postflush cond
//  ...                    ENDED (forever)  ---> assume flush & postflush cond
//  l             ENDFLUSH = post-flush end ---> assume flush & postflush cond
//  ---> assert varmap l+1                    FLUSHENDED       ---> assume flush
//  & postflush cond
//

void VlgSglTgtGen::ConstructWrapper_add_cycle_count_moniter() {
  // find in rf_cond, how many cycles will be needed
  max_bound = 0;

  auto& instr = get_current_instruction_rf();

  if (!instr.is_null() && IN("ready bound", instr) &&
      instr["ready bound"].is_number_integer())
    max_bound = instr["ready bound"].get<int>();
  else
    max_bound = _vtg_config.MaxBound;

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
  // how start is triggered
  if (_vtg_config.VerificationSettingAvoidIssueStage) {
    vlg_wrapper.add_stmt("if (rst) __START__ <= 1;");
    vlg_wrapper.add_stmt("else if (__START__ || __STARTED__) __START__ <= 0;");
  }
  else {
    vlg_wrapper.add_stmt("if (rst) __START__ <= 0;");
    vlg_wrapper.add_stmt("else if (__START__ || __STARTED__) __START__ <= 0;");
    vlg_wrapper.add_stmt("else if (__ISSUE__) __START__ <= 1;");
  }
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

  vlg_wrapper.add_reg ("__2ndENDED__", 1);
  vlg_wrapper.add_stmt("always @(posedge clk) begin");
  vlg_wrapper.add_stmt("if (rst) __2ndENDED__ <= 1'b0;");
  vlg_wrapper.add_stmt("else if (__ENDED__ && __EDCOND__ && ~__2ndENDED__)  __2ndENDED__ <= 1'b1; end");

  vlg_wrapper.add_wire("__2ndIEND__", 1);
  vlg_wrapper.add_assign_stmt("__2ndIEND__", "__ENDED__ && __EDCOND__ && ~__2ndENDED__");

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



void VlgSglTgtGen::ConstructWrapper_add_condition_signals() {
  // TODO
  // remember to generate
  // __ISSUE__ == start condition (if no flush, issue == true?)
  // __IEND__ == ( end condition ) &&  STARTED
  // __ENDFLUSH__ == (end flush condition ) && ENDED
  // flush : !( __ISSUE__ ? || __START__ || __STARTED__ ) |-> flush

  ILA_ASSERT (target_type == target_type_t::INSTRUCTIONS );
  // we don't need additional signals, just make reset drives the design

  // find the instruction
  auto& instr = get_current_instruction_rf();
  ILA_ASSERT(!instr.is_null());

  // __IEND__
  std::string iend_cond = VLG_FALSE;
  // bool no_started_signal = false;
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
      } else if (bound == 0) {
        // iend_cond += "|| (__START__)";
        // no_started_signal = true; // please don't use && STARTED
        ILA_ERROR << "Does not support bound : 0, please use a buffer to hold "
                     "the signal.";
      } else
        ILA_ERROR << "ready bound field of instruction: "
                  << _instr_ptr->name().str()
                  << " has to a non negative integer";
    } else
      ILA_ERROR << "ready bound field of instruction: "
                << _instr_ptr->name().str() << " has to a non negative integer";
  } // end of ready bound/condition

  // max bound for max checking range
  std::string max_bound_constr;
  if (IN("max bound", instr)) {
    if (instr["max bound"].is_number_integer()) {
      max_bound_constr =
          "&& ( __CYCLE_CNT__ <= " + IntToStr(instr["max bound"].get<int>()) +
          ")";
    }
  }

  vlg_wrapper.add_wire("__IEND__", 1, true);
  vlg_wrapper.add_wire("__EDCOND__", 1, true);
  // if(no_started_signal)
  //  add_wire_assign_assumption("__IEND__", "(" + iend_cond + ")",
  //                            "IEND");
  // else
  auto end_no_recur = has_flush ? "(~ __FLUSHENDED__ )" : "(~ __ENDED__)";
  
  add_wire_assign_assumption("__EDCOND__",
                             "(" + iend_cond + ") && __STARTED__ " ,
                             "EDCOND");

  add_wire_assign_assumption("__IEND__",
                             "(" + iend_cond + ") && __STARTED__ && __RESETED__ && " +
                                 end_no_recur + max_bound_constr,
                             "IEND");
  // handle start decode
  ILA_ERROR_IF(IN("start decode", instr))
      << "'start decode' is replaced by start condition!";
  if (IN("start condition", instr)) {
    handle_start_condition(instr["start condition"]);
  } else {
    add_an_assumption("(~ __START__) || (" + vlg_ila.decodeNames[0] + ")",
                      "issue_decode"); // __ISSUE__ |=> decode
    add_an_assumption("(~ __START__) || (" + vlg_ila.validName + ")",
                      "issue_valid"); // __ISSUE__ |=> decode
  }

  if (has_flush) {
    ILA_ASSERT(IN("pre-flush end", instr) &&
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

    vlg_wrapper.add_reg("__FLUSHENDED__", 1);
    vlg_wrapper.add_stmt(
        "always @(posedge clk) begin\n"
        "if(rst) __FLUSHENDED__ <= 0;\n"
        "else if( __ENDFLUSH__ && __ENDED__ ) __FLUSHENDED__ <= 1;\n end");

    // enforcing flush constraints
    std::string flush_enforcement = VLG_TRUE;
    if (instr["flush constraints"].is_null()) {
    } // do nothing. we are good
    else if (instr["flush constraints"].is_string()) {
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

    // TODO: preflush and postflush

    add_an_assumption(
        "(~ ( __RESETED__ && ~ ( __START__  || __STARTED__ ) ) ) || (" +
            flush_enforcement + ")",
        "flush_enforce_pre");
    add_an_assumption("(~ ( __ENDED__ )) || (" + flush_enforcement + ")",
                      "flush_enforce_post");

  } else {
    vlg_wrapper.add_wire("__ISSUE__", 1, true);
    if (_vtg_config.ForceInstCheckReset) {
      vlg_wrapper.add_input("__ISSUE__", 1);
    } else
      add_wire_assign_assumption("__ISSUE__", "1", "ISSUE"); // issue ASAP
    // start decode -- issue enforce (e.g. valid, input)
  } // end of no flush
} // ConstructWrapper_add_condition_signals

} // namespace ilang

