/// \file Source of initial constraint synthesis utility
// --- Hongce Zhang

#include <algorithm>
#include <fstream>
#include <ilang/util/container_shortcut.h>
#include <ilang/util/fs.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>
#include <ilang/vtarget-out/absmem.h>
#include <ilang/vtarget-out/vtarget_gen_yosys.h>
#include <iostream>

namespace ilang {

std::string single_ind_inv_tmpl = R"***(
;----------------------------------------
;  Single Inductive Invariant Synthesis
;  Generated from ILAng
;----------------------------------------

%%

;(declare-rel INIT (|%1%_s|))
;(declare-rel T (|%1%_s|) (|%1%_s|))
(declare-rel INV (|%1%_s|))
(declare-rel fail ())


(declare-var |__BI__| |%1%_s|)
(declare-var |__I__| |%1%_s|)

(declare-var |__S__| |%1%_s|)
(declare-var |__S'__| |%1%_s|)

; to do : no 

(rule (=> (and (|%1%_n rst| |__BI__|) (|%1%_t| |__BI__| |__I__|)) (INV |__I__|)))
(rule (=> (and (INV |__S__|) (|%1%_t| |__S__| |__S'__|)) (INV |__S'__|)))
(rule (=> (and (INV |__S__|) (not (|%1%_a| |__S__|))) fail))

(query fail :print-certificate true)

)***";


// o.w. we need to find two ind-inv
std::string dual_ind_inv_reset_start_tmpl = R"***(
;----------------------------------------
;  Dual Inductive Invariant Synthesis
;  Generated from ILAng
;----------------------------------------

; wrapper smt
%wrapperSmt%

; customized bv2bool
(define-fun zbv2bool ((bv1b (_ BitVec 1))) Bool (= bv1b #b1)) 

; additional mapping control
; |__AMC__design| is actually the invariants
; 
(define-fun |__AMC__design| ((|__Sv__| |%d%_s|)) Bool %amcFunc_design%)
(define-fun |__AMC__wrapper| ((|__Sw__| |%w%_s|)) Bool %amcFunc_wrapper%)

; includes the start_condition, issue_decode, issue_valid
(define-fun |__ASPT__| ((|__Sw__| |%w%_s|)) Bool %ASPT%) 

; includes the variable_map_assert
(define-fun |__ASST__| ((|__Sw__| |%w%_s|)) Bool %ASST%) 

(declare-rel INV1 (|%d%_s|)) ; inv1 is on design
(declare-rel INV2 (|%w%_s|)) ; inv2 is on wrapper
(declare-rel fail ())

(declare-var |__SvBI__| |%d%_s|) ; design
(declare-var |__SvI__|  |%d%_s|) ; design
(declare-var |__Sv__|   |%d%_s|) ; design
(declare-var |__Sv'__|  |%d%_s|) ; design

(declare-var |__SwBI__| |%w%_s|) ; wrapper : before init
(declare-var |__Swst__| |%w%_s|) ; wrapper : starting -- __START__ signal is true
(declare-var |__Sw__|   |%w%_s|) ; wrapper : generic state
(declare-var |__Sw'__|  |%w%_s|) ; wrapper : new state
;(declare-var |__Svst__| |%d%_s|) ; design  : starting -- __START__ signal is true here


; init => inv1
(rule (=> 
  (and 
    (|%d%_n rst| |__SvBI__|) 
    (|%d%_t|     |__SvBI__| |__SvI__|)
    ;(not (|%d%_n rst| |__SvI__|))    ; why not removed?
    (|%d%_h| |__SvBI__|)
    (|%d%_h| |__SvI__|)
    (|__AMC__design| |__SvI__|)
  ) (INV1 |__SvI__|)))

; inv1 /\ T => inv1
(rule (=> 
  (and
    (INV1    |__Sv__|)
    (|%d%_t| |__Sv__| |__Sv'__|)
    (|%d%_h| |__Sv__|)
    (|%d%_h| |__Sv'__|)
    (|__AMC__design| |__Sv__|)
    (|__AMC__design| |__Sv'__|))
  (INV1 |__Sv'__|)))


; init /\ inv1 => inv2
(rule (=> 
    (and
      (|%w%_n rst|          |__SwBI__|)
      (not (|%w%_n rst|     |__Swst__|)) ; why not removed?
      (|%w%_h| |__SwBI__|)
      (|%w%_h| |__Swst__|)
      (|%w%_t|              |__SwBI__| |__Swst__|)
      (|__AMC__wrapper|     |__Swst__|)
      (|__ASPT__|           |__Swst__|)
      (INV1 (|%w%_h %subi%| |__Swst__|))
    )
    (INV2 |__Swst__|)
  )
)

; inv2 /\ T => inv2
(rule 
  (=>
    (and
        (INV2 |__Sw__|)
        (|%w%_t| |__Sw__| |__Sw'__|)
        (|__AMC__wrapper| |__Sw__|)
        (|__AMC__wrapper| |__Sw'__|)
        (not (|%w%_n rst|     |__Sw__|))  ; why not removed?
        (not (|%w%_n rst|     |__Sw'__|)) ; why not removed?
        (|%w%_h| |__Sw__|)
        (|%w%_h| |__Sw'__|)
    )
    (INV2 |__Sw'__|)
  )
)


; inv2 /\ ~ assert => fail
(rule 
  (=> 
    (and
      (INV2             |__Sw__|)
      (|__AMC__wrapper| |__Sw__|)
      (|%w%_h| |__Sw__|)
      (not (|__ASST__|  |__Sw__|))
    )
    fail)
)

(query fail :print-certificate true)

)***";


// o.w. we need to find two ind-inv
std::string dual_ind_inv_tmpl = R"***(
;----------------------------------------
;  Dual Inductive Invariant Synthesis
;  Generated from ILAng
;----------------------------------------

; wrapper smt
%wrapperSmt%

; customized bv2bool
(define-fun zbv2bool ((bv1b (_ BitVec 1))) Bool (= bv1b #b1)) 

; additional mapping control
; |__AMC__design| is actually the invariants
; 
(define-fun |__AMC__design| ((|__Sv__| |%d%_s|)) Bool %amcFunc_design%)
(define-fun |__AMC__wrapper| ((|__Sw__| |%w%_s|)) Bool %amcFunc_wrapper%)

; includes the start_condition, issue_decode, issue_valid
(define-fun |__ASPT__| ((|__Sw__| |%w%_s|)) Bool %ASPT%) 

; includes the variable_map_assert
(define-fun |__ASST__| ((|__Sw__| |%w%_s|)) Bool %ASST%) 

(declare-rel INV1 (|%d%_s|)) ; inv1 is on design
(declare-rel INV2 (|%w%_s|)) ; inv2 is on wrapper
(declare-rel fail ())

(declare-var |__SvBI__| |%d%_s|) ; design
(declare-var |__SvI__|  |%d%_s|) ; design
(declare-var |__Sv__|   |%d%_s|) ; design
(declare-var |__Sv'__|  |%d%_s|) ; design

(declare-var |__SwBI__| |%w%_s|) ; wrapper : before init
(declare-var |__SwI__|  |%w%_s|) ; wrapper : init state
(declare-var |__Swst__| |%w%_s|) ; wrapper : starting -- __START__ signal is true
(declare-var |__Sw__|   |%w%_s|) ; wrapper : generic state
(declare-var |__Sw'__|  |%w%_s|) ; wrapper : new state
;(declare-var |__Svst__| |%d%_s|) ; design  : starting -- __START__ signal is true here


; init => inv1
(rule (=> 
  (and 
    (|%d%_n rst| |__SvBI__|) 
    (|%d%_t|     |__SvBI__| |__SvI__|)
    ;(not (|%d%_n rst| |__SvI__|))    ; why not removed?
    (|%d%_h| |__SvBI__|)
    (|%d%_h| |__SvI__|)
    (|__AMC__design| |__SvI__|)
  ) (INV1 |__SvI__|)))

; inv1 /\ T => inv1
(rule (=> 
  (and
    (INV1    |__Sv__|)
    (|%d%_t| |__Sv__| |__Sv'__|)
    (|%d%_h| |__Sv__|)
    (|%d%_h| |__Sv'__|)
    (|__AMC__design| |__Sv__|)
    (|__AMC__design| |__Sv'__|))
  (INV1 |__Sv'__|)))


; init /\ inv1 => inv2
(rule (=> 
    (and
      (|%w%_n rst|          |__SwBI__|)
      (not (|%w%_n rst|     |__SwI__|))  ; why not removed?
      (not (|%w%_n rst|     |__Swst__|)) ; why not removed?
      (|%w%_h| |__SwBI__|)
      (|%w%_h| |__SwI__|)
      (|%w%_h| |__Swst__|)
      (|%w%_t|              |__SwBI__| |__SwI__|)
      (|__AMC__wrapper|     |__SwI__|)
      (|%w%_t|              |__SwI__|  |__Swst__|)
      (|__AMC__wrapper|     |__Swst__|)
      (|__ASPT__|           |__Swst__|)
      (INV1 (|%w%_h %subi%| |__Swst__|))
    )
    (INV2 |__Swst__|)
  )
)

; inv2 /\ T => inv2
(rule 
  (=>
    (and
        (INV2 |__Sw__|)
        (|%w%_t| |__Sw__| |__Sw'__|)
        (|__AMC__wrapper| |__Sw__|)
        (|__AMC__wrapper| |__Sw'__|)
        (not (|%w%_n rst|     |__Sw__|))  ; why not removed?
        (not (|%w%_n rst|     |__Sw'__|)) ; why not removed?
        (|%w%_h| |__Sw__|)
        (|%w%_h| |__Sw'__|)
    )
    (INV2 |__Sw'__|)
  )
)


; inv2 /\ ~ assert => fail
(rule 
  (=> 
    (and
      (INV2             |__Sw__|)
      (|__AMC__wrapper| |__Sw__|)
      (|%w%_h| |__Sw__|)
      (not (|__ASST__|  |__Sw__|))
    )
    fail)
)

(query fail :print-certificate true)

)***";

// a local helper function to produce a list of and
std::string JoinListWithAnd(const std::vector<std::string> & l) {
  if (l.size() == 0)
    return "true";
  else if(l.size() == 1)
    return l[0];
  return "(and " + Join(l, " ")+")";
}

size_t skipArgs(const std::string & stmt, size_t start) {
  // need to fit 
  auto pos = start;
  ILA_ASSERT(stmt.at(pos) == '(') << "Expecting '('";
  unsigned level = 0;
  do {
    if (stmt.at(pos) == '(')
      level ++;
    else if (stmt.at(pos) == ')')
      level --;
    pos ++;
  } while(level != 0);
  return pos;
}

// a local helper function to return the type of a smt (define-fun ) stmt 
bool is_returntype_bool(const std::string & stmt) {
  std::string beginning("(define-fun |");
  ILA_ASSERT (stmt.find(beginning) == 0) << "Not a `(define-fun |` stmt";
  auto pos =  beginning.length()+1;
  auto end_func_name_pos = stmt.find('|',pos);
  auto start_arg_list = stmt.find('(', end_func_name_pos);
  auto end_arg_list = skipArgs(stmt, start_arg_list);
  auto Bool_pos = stmt.find("Bool", end_arg_list);
  auto Bitvec_pos = stmt.find("(_ BitVec", end_arg_list);
  if (Bool_pos < Bitvec_pos)
    return true;
  return false;
}


// extract 
bool extractSigDefFromLine(
  const std::string & mod_name,
  const std::string & line,
  std::set<std::string> & s, 
  std::vector<std::pair<std::string,bool>> & v) {
  // list of (name, is bool?)
  bool found_match_state = false;
  std::string search_target_wire_num = "(define-fun |" + mod_name + "#";
  std::string search_target_n = "(define-fun |" + mod_name + "_n ";
  bool returnBool;
  if (line.find(search_target_wire_num) == 0) { // begins with it
    auto mark = line.find("; \\");
    if (mark != line.npos) {
      auto signame = line.substr(mark+strlen("; \\"));
      // it should not contain EOL
      //signame = ReplaceAll(ReplaceAll(signame, "\n",""),"\r",""); 
      if( IN(signame, s ) ) {
        s.erase(signame); // remove it from the set

        auto num_start = line.substr(search_target_wire_num.size());
        auto end = num_start.find('|');
        auto num = num_start.substr(0,end);
        auto smt_expr = "|" + mod_name + "#" + num + "|";

        v.push_back(std::make_pair(smt_expr,is_returntype_bool(line))); // |mod#n|

        found_match_state = true;
      }
    } // found "; \\"
  } // end of exists signal definition type 1
  else if (line.find(search_target_n) == 0) { // begins with it
    auto len  = search_target_n.size();
    auto mark = line.find('|',len);
    auto signame = line.substr(len, mark-len);

    if( IN(signame, s) ) {
      s.erase(signame); // remove it from the set

      auto smt_expr = "|" + mod_name + "_n " + signame + "|";

      v.push_back(std::make_pair(smt_expr,is_returntype_bool(line)));  // |mod_n signal|
      found_match_state = true;
    }
  }

  return found_match_state;
}

/// generate the Yosys script for single invariant
void VlgSglTgtGen_Yosys::single_inv_problem(const std::string& ys_script_name, const std::string & pdr_template_name) {
  ILA_ASSERT ( not _vtg_config.YosysSmtArrayForRegFile)
    << "Future work: unable to handle arrays";

  auto ys_fn_full = os_portable_append_dir( _output_path, ys_script_name );
  std::ofstream ys_fout(ys_fn_full);

  std::string options;
  if ( not vlg_include_files_path.empty() )
    options += " -I./";
  ys_fout << "read_verilog"<< options << " -sv "
    << os_portable_append_dir( _output_path , top_file_name)<< std::endl;
  ys_fout << "prep -top "<< top_mod_name <<std::endl;
  ys_fout << yosysGenerateSmtScript_w_Array; // Maybe yosysGenerateSmtScript_wo_Array ?

  std::string write_smt2_options = " -mem -bv -wires -tpl " + 
    os_portable_append_dir( _output_path, pdr_template_name) ;
  ys_fout << "write_smt2"<<write_smt2_options
    << os_portable_append_dir( _output_path, 
         os_portable_remove_file_name_extension(top_file_name)
         + ".smt2");
} // single_inv_problem

/// generate the template file
void VlgSglTgtGen_Yosys::single_inv_tpl(const std::string & tpl_name) {
  ILA_ERROR << "Todo: not taking assumptions into account: future work!";
  { // First, write the template
    std::string pdr_template_name = 
      os_portable_append_dir(_output_path, tpl_name);
    std::ofstream fout(pdr_template_name);
    fout << ReplaceAll(single_ind_inv_tmpl, "%1%", top_mod_name);
  } // finish write template
} // single_inv_tpl

  /// generate the Yosys script for dual invariant
  void VlgSglTgtGen_Yosys::dual_inv_problem(const std::string& ys_script_name) {
    // this is the yosys script for ? what?
    return; // do nothing
  }


// -------------------------------------------
// Summary of the assertions/assumptions we need to handle
//
// assert: variable_map_assert
//         invariant_assert -- should no be here
// 
// assmpt:  noreset (AMC) 
//          funcmap (AMC)
//          absmem (AMC)
//          additional_mapping_control_assume (AMC)
//          invariant_assume (AMC_design)
//          issue_decode (START -- ASPT)
//          issue_valid  (START -- ASPT)
//          start_condition (START -- ASPT)
//
// (AMC means should always be true)
//
// -------------------------------------------

  /// generate the template file
  void VlgSglTgtGen_Yosys::dual_inv_tpl(const std::string & tpl_name, YosysDesignSmtInfo & smt_info) {
    // get a local copy of the stringstream
    std::string all_smt = smt_info.full_smt.str();
    // the Verilog top module
    auto vlg_top_module_name = vlg_info_ptr->get_top_module_name();
    
    // define amc(d/w)/asst/aspt funcs
    std::string amc_design;
    std::string amc_wrapper;
    std::string asst;
    std::string aspt;
    { // Construct the above four 
      std::set<std::string> wn_amc_design_item; // wn stands for wire name
      std::set<std::string> wn_amc_wrapper_item;
      std::set<std::string> wn_asst_item; // assertions
      std::set<std::string> wn_aspt_item; // assumptions

      { // find the verilog signal name
        for (auto&& pbname_prob_pair : _problems.assertions) {
          const auto & dspt = pbname_prob_pair.first;
          const auto & exprs = pbname_prob_pair.second;

          if (dspt == "invariant_assert") {
            ILA_ASSERT(false) << "Unanticipated dspt: " << dspt;
          }
          else if(dspt == "variable_map_assert") {
            // 
            for (const auto & expr : exprs.exprs) {
              ILA_ASSERT( expr.find("=") == expr.npos ) 
                << "Bug: should be pure name."
                << "but get: " << expr;

              wn_asst_item.insert(expr);
            }
          }
          else
            ILA_ASSERT(false) << "Unknown dspt:" << dspt;


        } // end of parsing asserts

        for (auto && pbname_prob_pair : _problems.assumptions) {
          const auto & dspt = pbname_prob_pair.first;
          const auto & exprs = pbname_prob_pair.second;
          for (const auto &expr : exprs.exprs) {
            ILA_ASSERT( expr.find("=") == expr.npos ) // no "="
              << "Bug: should be pure name."
              << " but get: " << expr
              << " dspt: " << dspt; 

            if(dspt == "invariant_assume")
              wn_amc_design_item.insert(expr);
            else if(
              dspt == "noreset" ||
              dspt == "funcmap" ||
              dspt == "absmem" ||
              dspt == "additional_mapping_control_assume" ||
              dspt == "func_arg" ||
              dspt == "func_result" ||
              dspt == "post_value_holder"
                )
              wn_amc_wrapper_item.insert(expr);
            else if(
              dspt == "issue_decode" ||
              dspt == "issue_valid"  ||
              dspt == "start_condition" ||
              dspt == "variable_map_assume"
            )
              wn_aspt_item.insert(expr);
            else
              ILA_ASSERT(false) << "Unknown dspt : " << dspt;
          } // for expr
        } // for assumptions

      } // gen wire name

      std::vector<std::pair<std::string,bool>> amc_design_item; // no wn here : in the submodule 
      std::vector<std::pair<std::string,bool>> amc_wrapper_item; // in the top module
      std::vector<std::pair<std::string,bool>> asst_item; // assertions
      std::vector<std::pair<std::string,bool>> aspt_item; // assumptions
      { // find number name --- smt name
        // algo : go line by line, check in "wn_" or not, if so, add ow ignored
        enum {BEFORE, SUBMODULE, TOPMODULE} state = BEFORE;
        for (std::string line;  std::getline(smt_info.full_smt, line);) {
          if ( state == BEFORE and
              line.find("; yosys-smt2-module ") == 0) { // starts with it
            // new module
            auto modname = line.substr(strlen("; yosys-smt2-module "));
            if (modname == vlg_top_module_name) 
              state = SUBMODULE; // go to next state
          } // find vlg module
          else if (state == SUBMODULE) {
            if ( extractSigDefFromLine(
                  vlg_top_module_name, line, wn_amc_design_item,
                  amc_design_item) ) { /* do nothing */ }
            else if(line.find("; yosys-smt2-module ") == 0) {
              auto modname = line.substr(strlen("; yosys-smt2-module "));
              if (modname == top_mod_name)
                state = TOPMODULE; // go to next state
            } // end of go to next module
            // else do nothing  
          } // deal with submodule (verilog top) -- continue to the wrapper
          else if (state == TOPMODULE) {
            if ( extractSigDefFromLine( top_mod_name, line,
                   wn_amc_wrapper_item, amc_wrapper_item ) ) { /* do nothing */ }
            else if ( extractSigDefFromLine( top_mod_name, line,
                   wn_asst_item, asst_item ) ) { /* do nothing */ }
            else if ( extractSigDefFromLine( top_mod_name, line,
                   wn_aspt_item, aspt_item ) ) { /* do nothing */ }
            else { /* do nothing */ }
          }
        } // end of for readline
        ILA_ASSERT (state == TOPMODULE) 
          << "BUG: Error in parsing smt-lib2 file! "
          << "Not reaching the top module.";
        // sanity check -- if all sigs are found

        ILA_ASSERT (
          wn_amc_design_item.empty() and
          wn_amc_wrapper_item.empty() and 
          wn_asst_item.empty() and
          wn_aspt_item.empty()
          ) << "Missing signals in SMT parsing, HC gen will be incorrect";
      } //  find number name --- smt name

      { // construct expressions
        // (signame |%d%_s|) or (signame |%w%_s|), use " " to join and add "(and" ")"
        std::vector<std::string> items;
        items.clear();
        for (auto && name_bool_pair: amc_design_item) {
          if (name_bool_pair.second)
            items.push_back("("+name_bool_pair.first+" |__Sv__|)");
          else
            items.push_back("(zbv2bool ("+name_bool_pair.first+" |__Sv__|))");
        }
        amc_design = JoinListWithAnd(items);


        items.clear();
        for (auto && name_bool_pair: amc_wrapper_item) {
          if (name_bool_pair.second)
            items.push_back("("+name_bool_pair.first+" |__Sw__|)");
          else
            items.push_back("(zbv2bool ("+name_bool_pair.first+" |__Sw__|))");
        }
        amc_wrapper = JoinListWithAnd(items);
        
        items.clear();
        for (auto && name_bool_pair: aspt_item) {
          if (name_bool_pair.second)
            items.push_back("("+name_bool_pair.first+" |__Sw__|)");
          else
            items.push_back("(zbv2bool ("+name_bool_pair.first+" |__Sw__|))");
        }
        aspt = JoinListWithAnd(items);

        items.clear();
        for (auto && name_bool_pair: asst_item) {
          if (name_bool_pair.second)
            items.push_back("("+name_bool_pair.first+" |__Sw__|)");
          else
            items.push_back("(zbv2bool ("+name_bool_pair.first+" |__Sw__|))");
        }
        asst = JoinListWithAnd(items);

        /*
        for_each(aspt_item.begin(), aspt_item.end(),
          [](std::string & s) -> void {s = "("+s+" |__Sw__|)";} );
        aspt = JoinListWithAnd(aspt_item);

        for_each(asst_item.begin(), asst_item.end(),
          [](std::string & s) -> void {s = "("+s+" |__Sw__|)";} );
        asst = JoinListWithAnd(asst_item);*/

      } // construct expressions
    } // Construct exprs done

    std::string ret_tpl_smt;
    if (_vtg_config.VerificationSettingAvoidIssueStage)
      ret_tpl_smt = dual_ind_inv_reset_start_tmpl;
    else
      ret_tpl_smt = dual_ind_inv_tmpl;
    { // now create the template 
      // 1. func sub
      ret_tpl_smt = ReplaceAll(ret_tpl_smt, "%wrapperSmt%", all_smt);
      ret_tpl_smt = ReplaceAll(ret_tpl_smt, "%amcFunc_design%", amc_design);
      ret_tpl_smt = ReplaceAll(ret_tpl_smt, "%amcFunc_wrapper%", amc_wrapper);
      ret_tpl_smt = ReplaceAll(ret_tpl_smt, "%ASST%", asst);
      ret_tpl_smt = ReplaceAll(ret_tpl_smt, "%ASPT%", aspt);
      // 2. name sub
      ret_tpl_smt = ReplaceAll(ret_tpl_smt, "%subi%", _vlg_mod_inst_name);
      ret_tpl_smt = ReplaceAll(ret_tpl_smt, "%d%", vlg_top_module_name);
      ret_tpl_smt = ReplaceAll(ret_tpl_smt, "%w%", top_mod_name);
    }

    { // output the tpl
      std::ofstream tpl_fout(tpl_name);
      tpl_fout << ret_tpl_smt;
    } // finish output

  } // dual_inv_tpl 



}; // namespace ilang
